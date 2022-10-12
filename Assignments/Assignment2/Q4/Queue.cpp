/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Steven Wong and Chen Min
 * Date: October 2022
 */

#include <iostream>
#include "Queue.h"

using namespace std;

// Default constructor
Queue::Queue()
{
    elements = new int[INITIAL_CAPACITY];
}

// Destructor
Queue::~Queue()
{
    delete[] elements;
    elementCount = 0;
    frontindex = 0;
    backindex = 0;
}

// Description: Inserts element x at the back of Queue
void Queue::enqueue(int x)
{
    // If the queue is full, resize it
    if (elementCount == capacity )
    {
        // Create a new array with double the capacity
        int new_capacity = capacity * 2;
        int* temp = new int[new_capacity];
        // Copy the elements from the old array to the new array
        for (int i = 0; i < elementCount; i++)
        {
            if (i + frontindex <= capacity - 1 )
                temp[i] = elements[i + frontindex];
            else
                temp[i] = elements[i + frontindex - capacity];
        }
        // Delete the old array and update the Queue's data members
        delete[] elements;
        elements = new int[new_capacity];
        capacity = new_capacity;
        elements = temp;
        frontindex = 0;
        backindex = elementCount;
    }
    
    // Add the new element to the back of the queue
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
    return;
}

// Description: Removes the frontmost element
void Queue::dequeue()
{
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    
    if (elementCount <= capacity * 0.25 && 0.5 * capacity >= INITIAL_CAPACITY)
    {
        int new_capacity = 0.5 * capacity;
        int* temp = new int[new_capacity];
        for (int i = 0; i < elementCount; i++)
        {
            temp[i] = elements[i + frontindex];
        }
        delete[] elements;
        elements = new int[new_capacity];
        capacity = new_capacity;
        elements = temp;
        frontindex = 0;
        backindex = elementCount;
    }
    return;
}

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
int Queue::peek()const
{
    return elements[frontindex];
}

// Description: Returns true if and only if Queue empty
bool Queue::isEmpty()const
{
    return elementCount == 0;
}

// Get the current capacity of the queue
unsigned int Queue::getCapacity() const
{
    return capacity;
}

// Get the number of elements in the queue
unsigned int Queue::getElementCount() const
{
    return elementCount;
}

// Description: Used to print out the Queue for testing purposes
ostream &operator<<(ostream &os, const Queue &q)
{
    // Go from front to back
    for (int i = 0; i < q.elementCount; i++)
        os << q.elements[(q.frontindex + i) % q.capacity] << " ";
    return os;
}
