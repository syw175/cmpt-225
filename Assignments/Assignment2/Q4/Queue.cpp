/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Steven Wong + YOUR NAME
 * Date: October 2022
 */

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