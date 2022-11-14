/*
 * BankSimApp.cpp
 *
 * Description: A Bank Simulation App which models Events described in the Bank Simulation problem.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 */

// Simulation Begins
// Processing an arrival event at time:     1
// Processing an arrival event at time:     2
// Processing an arrival event at time:     4
// Processing a departure event at time:    6
// Processing a departure event at time:   11
// Processing a departure event at time:   16
// Processing an arrival event at time:    20
// Processing an arrival event at time:    22
// Processing an arrival event at time:    24
// Processing a departure event at time:   25
// Processing an arrival event at time:    26
// Processing an arrival event at time:    28
// Processing an arrival event at time:    30
// Processing a departure event at time:   30
// Processing a departure event at time:   35
// Processing a departure event at time:   40
// Processing a departure event at time:   45
// Processing a departure event at time:   50
// Processing an arrival event at time:    88
// Processing a departure event at time:   91
// Simulation Ends

// Final Statistics:

// 	Total number of people processed: 10
// 	Average amount of time spent waiting: 5.6

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Queue.h"
#include "PriorityQueue.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
    // Initialize variables
    Queue<Event> tellerLine;
    PriorityQueue<Event> eventQueue;
    bool tellerAvail = true;
    int people = 0;
    int cumulativeTime = 0;

    cout << "Simulation Begins" << endl;
    // Create arrival events with command line input
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

    // While there are still events to be processed...
    while (!eventQueue.isEmpty())
    {
        // Get the next event from the eventQueue and dequeue it
        Event nextEvent = eventQueue.peek();
        eventQueue.dequeue();

        // If the next event is an arrival
        if (nextEvent.getType() == 'A')
        {
            // If the teller is available
            if (tellerAvail)
            {
                // Process the arrival event
                cout << "Processing an arrival event at time: " << nextEvent.getTime() << endl;
                // Set the teller to unavailable
                tellerAvail = false;
                // Create a departure event
                Event departureEvent('D', nextEvent.getTime() + nextEvent.getLength(), nextEvent.getLength());
                // Enqueue the departure event
                eventQueue.enqueue(departureEvent);
            }
            // If the teller is not available
            else
            {
                // Process the arrival event
                cout << "Processing an arrival event at time: " << nextEvent.getTime() << endl;
                // Enqueue the arrival event
                tellerLine.enqueue(nextEvent);
            }
        }

        // If the next event is a departure
        else if (nextEvent.getType() == 'D')
        {
            // Process the departure event
            cout << "Processing a departure event at time: " << nextEvent.getTime() << endl;
            // Calculate the time spent waiting
            int timeSpentWaiting = nextEvent.getTime() - nextEvent.getLength();
            // Add the time spent waiting to the cumulative time
            cumulativeTime += timeSpentWaiting;
            // If the teller line is not empty
            if (!tellerLine.isEmpty())
            {
                // Get the next arrival event from the teller line
                Event nextArrivalEvent = tellerLine.peek();
                // Dequeue the next arrival event
                tellerLine.dequeue();
                // Create a departure event
                Event departureEvent('D', nextEvent.getTime() + nextArrivalEvent.getLength(), nextArrivalEvent.getLength());
                // Enqueue the departure event
                eventQueue.enqueue(departureEvent);
            }
            // If the teller line is empty
            else
            {
                // Set the teller to available
                tellerAvail = true;
            }
        }
    }

    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl << endl;
    cout << "\tTotal number of people processed: " << people << endl;
    cout << "\tAverage amount of time spent waiting: " << (float)cumulativeTime / people << endl << endl;
    return 0;
}