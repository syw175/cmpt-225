/* 
 * Queue.cpp - Does not work well! CHANGE THIS LATER
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Steven Wong
 * Date: October 2022
 */
 

 // What else to change?? 
 // ElementCount is incorrectly set at some point in this program, go fix it 
 // Consider trying to handle exceptions... specifically where the preconditions of dequeue() and peek() have not been satisfied
 // Also need to add a proper test Driver for this program to test all the new updated functionality

#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue()
{
    elements = new int[INITIAL_CAPACITY];
}

// Description: Destructor
Queue::~Queue()
{
    delete[] elements;
    elements = nullptr;
}

// ToDO
// Method to enlarge the array if it becomes full
// Takes a int for choice FOR NOW
void Queue::resize(void)
{
    if (elementCount == capacity)
    {
        // Update capacity size
        capacity *= 2;
        // Create a new array of elements
        int *newElements = new int[capacity];

        // Copy over the previous elements from the back to the front and then delete the queue
        // Start from the back elements and 
        // for (unsigned int i =
    }
    else
    {
        // If choice is not 0, that means the array is too big and we need to shrink it


    }
    return;
}

// Description: Inserts element x at the back of Queue
// Time Efficiency: O(1)

// ToDO
// Rewrite this function and also change the time efficiency of this enqueue + description
// Double the capacity of array whenever I enqueue into a full array... expensive resizing becomes amortized across enough operations
// Feel free to add a private helper method to the queue class
void Queue::enqueue(int x)
{
    // If the array is full we need to resize it
    resize();

    // Enqueue our new element and update elementCount and back index
    elementCount++;
    elements[backindex] = x;
    backindex++;
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)

// Rewrite this function to make this program more efficient, update description + time efficiency
// Halve the capacity of the queue whenever the array is less than 1/4 full 
// Invariant: The min capacity cannot drop below the value of INITAL_CAPACITY

// TODO
void Queue::dequeue()
{
    // If trying to dequeue from an empty array... raise an exception
    if (isEmpty())
    {
        cout << "Exception: Cannot dequuee from an empty array" << endl;
        abort();
    }

    elementCount--;
    frontindex++;
    // frontindex = (frontindex + 1) % capacity;


    // Check on the state of the array after dequeueing an element
    // If it is less than 1/4 full AND if min capacty won't drop below the INITAL_CAPACITY...
    //               half the capacity of the queue
    resize();
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const
{
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const
{
    return elementCount == 0;
}

// Description: Used to print out the Queue for testing purposes
std::ostream &operator<<(std::ostream &os, const Queue &q)
{
    // Need Correction here
    for (unsigned int i = 0; i < q.elementCount; i++)
    {
        os << q.elements[i];
    }
    return os;
}
