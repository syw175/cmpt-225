/*
 * BankSimApp.cpp
 *
 * Description: A Bank Simulation App which models Events described in the Bank Simulation problem.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 */

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;

// Function prototypes
void processArrival(Event &arrival, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, int &currentTime, bool &tellerAvailable);
void processDeparture(Event &departure, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, int &currentTime, bool &tellerAvailable);

int main(int argc, char* argv[])
{
    // Initialize variables
    Queue<Event> tellerLine;
    PriorityQueue<Event> eventQueue;
    bool tellerAvail = true;
    int people = 0;
    int currentTime = 0;
    int prevEvent = 0;
    int currentWaitTime = 0;
    int processed = 0;
    int totalWaitTime = 0;

    cout << "Simulation Begins" << endl;
    // Read in events with command line input
    while (!cin.eof())
    {
        // Read in the arrival time and transaction time
        int time;
        int duration;
        cin >> time;
        cin >> duration;

        // Create an arrival event, enqueue it, and increment the number of people
        Event arrivalEvent('A', time, duration);
        eventQueue.enqueue(arrivalEvent);
        people++;
    }

    // Get the first currentTime
    if (!eventQueue.isEmpty())
        prevEvent = eventQueue.peek().getTime() + eventQueue.peek().getLength();

    // While there remains events to be processed in the event queue...
    while (!eventQueue.isEmpty())
    {
        // Get the next highest priority event and get current time
        Event nextEvent = eventQueue.peek();

        // If event is not the first event, update the current time
        if (processed != 0)
        {
            // Calculate the current wait time
            currentWaitTime =  prevEvent - nextEvent.getTime();
            // If the current wait time is negative, set it to 0
            if (currentWaitTime <= 0)
                currentWaitTime = 0;
            prevEvent = nextEvent.getTime() + nextEvent.getLength() + currentWaitTime;
        }
        // Increment the number of processed events
        processed++;

        // Update our current time
        currentTime = nextEvent.getTime() + currentWaitTime;

        // Process the event
        if (nextEvent.isArrival())
        {
            // Total wait time is the sum of all wait times
            totalWaitTime += currentWaitTime;
            processArrival(nextEvent, eventQueue, tellerLine, currentTime, tellerAvail);
        }
        else
            processDeparture(nextEvent, eventQueue, tellerLine, currentTime, tellerAvail);
    }

    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "\tTotal number of people processed: " << people << endl;
    cout << "\tAverage amount of time spent waiting: " << (float)totalWaitTime / people << endl << endl;
    return 0;
}

// Process an arrival event
void processArrival(Event &arrival, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, int &currentTime, bool &tellerAvail)
{
    cout << "Processing an arrival event at time: " << std::setw(5) << std::right << currentTime << endl;
    // Dequeue the arrival event
    eventQueue.dequeue();

    // If the teller is available, create a departure event and enqueue it
    if (tellerLine.isEmpty() && tellerAvail)
    {
        Event departureEvent('D', currentTime + arrival.getLength());
        eventQueue.enqueue(departureEvent);
        tellerAvail = false;
    }
    else
        tellerLine.enqueue(arrival);
}

// Process a departure event
void processDeparture(Event &departure, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, int &currentTime, bool &tellerAvail)
{
    cout << "Processing a departure event at time: " << std::setw(4) << std::right << currentTime << endl;
    // Dequeue the departure event
    eventQueue.dequeue();

    // If the teller line is not empty, create a departure event and enqueue it
    if (!tellerLine.isEmpty())
    {
        // Customer at front of line begins transaction
        Event customer = tellerLine.peek();
        tellerLine.dequeue();
        Event nextDeparture('D', currentTime + customer.getLength());
        eventQueue.enqueue(nextDeparture);
    }
    else
    {
        tellerAvail = true;
    }
}