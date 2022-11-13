/*
 * PriorityQueue.h
 *
 * Description: Implemented using the Binary Heap Data Collection ADT from Part 2 as the underlying data structure.
 *              Functionally, the operations of the Priority class are wrapper methods to the public methods of the
 *              Binary Heap ADT class.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"

template <class ElementType>
class PriorityQueue
{
    private:
        // Underlying data structure of our PriorityQueue
        BinaryHeap<ElementType> priorityQueue;

    /******* Start of Priority Queue Public Interface *******/
    public:
        // Default Constructor
        PriorityQueue();

        // Copy Constructor
        PriorityQueue(const PriorityQueue<ElementType> &q);

        // Destructor
        ~PriorityQueue();

        // Description: Returns true if this Priority Queue is empty, otherwise false.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement in this Priority Queue and 
        //              returns true if successful, otherwise false.
        // Time Efficiency: O(log2 n)
        bool enqueue(ElementType &newElement);

        // Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        // Time Efficiency: O(log2 n)
        void dequeue();
   
        // Description: Returns (but does not remove) the element with the next 
        //              "highest" priority from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
        // Time Efficiency: O(1)
        ElementType &peek() const;

        // Description: Prints all elements in the priority queue for testing purposes.
        // Time Efficiency: O(n)
        // Precondition: This Priority Queue is not empty.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        void printPriorityQueue() const;
};
#include "PriorityQueue.cpp"
#endif