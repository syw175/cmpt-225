/*
 * PriorityQueue.cpp
 *
 * Description: Implemented using the Binary Heap Data Collection ADT from Part 2 as the underlying data structure.
 *              Functionally, the operations of the Priority class are wrapper methods to the public methods of the
 *              Binary Heap ADT class.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 */

#include "PriorityQueue.h"

// Default Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
    priorityQueue = new BinaryHeap<ElementType>();
}

// Copy Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue<ElementType> &q)
{
    this->priorityQueue = new BinaryHeap<ElementType>(q->priorityQueue);
}

// Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
    delete priorityQueue;
    priorityQueue = nullptr;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
    return priorityQueue->getElementCount() == 0;
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType &newElement)
{
    return priorityQueue->insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue()
{
    // The priority queue must NOT be empty to remove the next element
    if (isEmpty())
        throw EmptyDataCollectionException("Dequeue() method called with an empty Priority Queue");

    priorityQueue->remove();
}

// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& PriorityQueue<ElementType>::peek() const
{
    // The priority queue must NOT be empty to peek at the next element
    if (isEmpty())
        throw EmptyDataCollectionException("Peek() method called with an empty Priority Queue");

    return priorityQueue->retrieve();
}

// Description: Prints all elements in the priority queue for testing purposes.
// Time Efficiency: O(n)
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
template <class ElementType>
void PriorityQueue<ElementType>::printPriorityQueue() const
{
    // The priority queue must NOT be empty to print the Priority Queue
    if (isEmpty())
        throw EmptyDataCollectionException("PrintPriorityQueue() method called with an empty Priority Queue");
    
    priorityQueue->print();
}