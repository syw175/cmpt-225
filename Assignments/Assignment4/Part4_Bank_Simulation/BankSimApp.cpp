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

using std::cout;
using std::cin;
using std::endl;

// Function prototypes
void processArrival(Event &arrival, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, bool &tellerAvailable);
void processDeparture(Event &departure, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, bool &tellerAvailable, int &cumulativeTime);

int main(int argc, char* argv[])
{
    // Initialize variables
    Queue<Event> tellerLine;
    PriorityQueue<Event> eventQueue;
    bool tellerAvail = true;
    int people = 0;
    int cumulativeTime = 0;

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

    // While there remains events to be processed in the event queue...
    while (!eventQueue.isEmpty())
    {
        // Get the next highest priority event and get current time
        Event nextEvent = eventQueue.peek();

        // Process the event
        if (nextEvent.isArrival())
            processArrival(nextEvent, eventQueue, tellerLine, tellerAvail);
        else
            processDeparture(nextEvent, eventQueue, tellerLine, tellerAvail, cumulativeTime);
    }

    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "\tTotal number of people processed: " << people << endl;
    cout << "\tAverage amount of time spent waiting: " << (float)cumulativeTime / people << endl << endl;
    return 0;
}

// Process an arrival event
void processArrival(Event &arrival, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, bool &tellerAvail)
{
    cout << "Processing an arrival event at time: " << arrival.getTime() << endl;
    // Dequeue the arrival event
    eventQueue.dequeue();

    // If the teller is available, create a departure event and enqueue it
    if (tellerLine.isEmpty() && tellerAvail)
    {
        Event departureEvent('D', arrival.getTime() + arrival.getLength(), 0);
        eventQueue.enqueue(departureEvent);
        tellerAvail = false;
    }
    else
    {
        tellerLine.enqueue(arrival);
    }
}

// Process a departure event
void processDeparture(Event &departure, PriorityQueue<Event> &eventQueue, Queue<Event> &tellerLine, bool &tellerAvail, int &cumulativeTime)
{
    cout << "Processing a departure event at time: " << departure.getTime() << endl;
    // Dequeue the departure event
    eventQueue.dequeue();

    // If the teller line is not empty, create a departure event and enqueue it
    if (!tellerLine.isEmpty())
    {
        // Customer at front of line begins transaction
        Event customer = tellerLine.peek();
        cout << "Values going in: " << departure.getTime() << " " << customer.getTime() << endl;
        cumulativeTime += (departure.getTime() - customer.getTime());
        cout << "Cumulative time spent waiting: " << cumulativeTime << endl;

        tellerLine.dequeue();
        Event nextDeparture('D', departure.getTime() + customer.getLength());
        eventQueue.enqueue(nextDeparture);
    }
    else
    {
        tellerAvail = true;
    }
}