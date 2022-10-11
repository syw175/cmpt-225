#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
    elements = new int[INITIAL_CAPACITY];
}

Queue::~Queue()
{
    delete[] elements;
    elementCount = 0;
    frontindex = 0;
    backindex = 0;
}

void Queue::enqueue(int x)
{
    if (elementCount == capacity )
    {
        int new_capacity = capacity * 2;
        int* temp = new int[new_capacity];
        for (int i = 0; i < elementCount; i++)
        {
            if (i + frontindex <= capacity - 1 )
                temp[i] = elements[i + frontindex];
            else
                temp[i] = elements[i + frontindex - capacity];
        }
        delete[] elements;
        elements = new int[new_capacity];
        capacity = new_capacity;
        elements = temp;
        frontindex = 0;
        backindex = elementCount;
    }
    
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
    return;
}

void Queue::dequeue()
{
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    
    if (elementCount <= capacity * 0.25 && 0.5 * elementCount >= INITIAL_CAPACITY)
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

int Queue::peek()const
{
    return elements[frontindex];
}

bool Queue::isEmpty()const
{
    return elementCount == 0;
}

unsigned int Queue::getCapacity() const
{
    return capacity;
}

unsigned int Queue::getElementCount() const
{
    return elementCount;
}

// Description: Used to print out the Queue for testing purposes
ostream &operator<<(ostream &os, const Queue &q)
{
    // Go from front to back
    for (int i = 0; i < q.elementCount; i++)
    {
        os << q.elements[(q.frontindex + i) % q.capacity] << " ";
    }
    return os;
}

// /* 
//  * Queue.cpp - Does not work well! CHANGE THIS LATER
//  *
//  * Description: Array-based implementation of Queue as an ADT class
//  * Class Invariant: Queue maintained in FIFO order
//  *
//  * Author: Steven Wong
//  * Date: October 2022
//  */
 

//  // What else to change?? 
//  // ElementCount is incorrectly set at some point in this program, go fix it 
//  // Consider trying to handle exceptions... specifically where the preconditions of dequeue() and peek() have not been satisfied
//  // Also need to add a proper test Driver for this program to test all the new updated functionality

// #include <iostream>
// #include "Queue.h"

// using std::cout;
// using std::endl;

// // Done
// // Description: Default Constructor
// Queue::Queue()
// {
//     elements = new int[INITIAL_CAPACITY];
// }

// // Done
// // Description: Destructor
// Queue::~Queue()
// {
//     delete[] elements;
//     elements = nullptr;
// }

// // TODO
// // Method to enlarge the array if it becomes full
// // Takes a int for choice FOR NOW
// void Queue::resize(void)
// {
//     if (elementCount == capacity)
//     {
//         // Create a new array of elements with double the capacity of the existing array
//         int newCapacity = capacity * 2;
//         int *newElements = new int[newCapacity];
        
//         // Copy over the previous elements from the back to the front and then delete the existing one
//         for (unsigned int i = 0; i < elementCount; i++)
//         {
//             newElements[newCapacity - i - 1] = newElements[backIndex - 1];

//         }

//         // Update our data members
//         delete[] elements;
//         capacity = newCapacity;
//         elements = newElements;

//         // Check this...
//         frontindex = 0;
//         backindex = elementCount;
//     }
//     // Otherwise, we are decreasing the size of the array and copy it over
//     else
//     {
//         int newCapacity = capacity/2;
//         int *newElements = new int[newCapacity];
//         if (!newCapacity < INITIAL_CAPACITY)
//         {
//             // Resize it
//             // Copy over the old elements
//             for (unsigned int i = 0; i < elementCount; i++)

//             {

//             }
//         }

//         delete[] elements;
//         capacity = newCapacity;
//         elements = newElements;

//         // Check this
//         frontindex = 0;
//         backindex = elementCount;
//     }
//     return;
// }

// // Description: Inserts element x at the back of Queue
// // Time Efficiency: O(1)

// // TODO
// // Rewrite this function and also change the time efficiency of this enqueue + description
// // Double the capacity of array whenever I enqueue into a full array... expensive resizing becomes amortized across enough operations
// // Feel free to add a private helper method to the queue class
// void Queue::enqueue(int x)
// {
//     // If the array is full we need to resize it
//     resize();

//     // Enqueue our new element and update elementCount and back index
//     elementCount++;
//     elements[backindex] = x;
//     backindex++;


//     return;
// }

// // Description: Removes the frontmost element
// // Precondition: Queue not empty
// // Time Efficiency: O(1)

// // Rewrite this function to make this program more efficient, update description + time efficiency
// // Halve the capacity of the queue whenever the array is less than 1/4 full
// // Invariant: The min capacity cannot drop below the value of INITAL_CAPACITY

// // TODO
// void Queue::dequeue()
// {
//     // If trying to dequeue from an empty array... raise an exception
//     if (isEmpty())
//     {
//         cout << "Exception: Cannot dequuee from an empty array" << endl;
//         abort();
//     }

//     elementCount--;
//     frontindex++;
//     // frontindex = (frontindex + 1) % capacity;

    
    
//     // Check on the state of the array after dequeueing an element
//     // If it is less than 1/4 full AND if min capacty won't drop below the INITAL_CAPACITY...
//     //               half the capacity of the queue
//     resize();
//     return;
// } 

// // DONE
// // Description: Returns a copy of the frontmost element
// // Precondition: Queue not empty
// // Time Efficiency: O(1)
// int Queue::peek() const
// {
//     return elements[frontindex];    
// } 

// // DONE
// // Description: Returns true if and only if Queue empty
// // Time Efficiency: O(1)
// bool Queue::isEmpty() const
// {
//     return elementCount == 0;
// }

// // DONE
// // Description: Used to print out the Queue for testing purposes
// std::ostream &operator<<(std::ostream &os, const Queue &q)
// {
//     // Need Correction here
//     for (unsigned int i = 0; i < q.elementCount; i++)
//     {
//         os << q.elements[i];
//     }
//     return os;
// }
