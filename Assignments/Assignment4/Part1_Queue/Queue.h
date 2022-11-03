/*
 * Queue.h
 * 
 * Description: This is a linked list-based implementation of a Queue ADT class.
 *              Its underlying data structure is a doubly-headed singly-linked list (DHSL).
 *              Class Invariant:  FIFO or LILO order
 *
 * Author: SW
 * Date: Last modified: November 2022
 */

#ifndef QUEUE_H
#define QUEUE_H

template <class ElementType>
class Queue {
    private:
        // Node is a nested class within Queue.
        class Node {
            public:
                // Data members
                ElementType &data;
                Node<ElementType> *next = nullptr;

                // Default constructor
                Node<ElementType> () {}
  
                // Parameterised Constructor
                Node<ElementType> (ElementType &data) : this->data(data) {}
        };

        Node *head = nullptr;
        Node *tail = nullptr;
        unsigned int elementCount = 0;

    /******* Start of Queue Public Interface *******/
    public:
        // Default constructor
        Queue();

        // Destructor
        ~Queue();

        // Overloaded << operator
        // Description: For testing purposes only, to print out elements in the Queue
        // Time Efficiency: O(n)
        friend std::ostream &operator<<(std::ostream &os, const Queue &q);
        
        // Description: Returns true if this Queue is empty, otherwise false.
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement at the "back" of this Queue
        //              (not necessarily the "back" of this Queue's data structure)
        //              and returns true if successful, otherwise false.
        // Time Efficiency: O(1)
        bool enqueue(ElementType &newElement);

        // Description: Removes (but does not return) the element at the "front" of this Queue
        //              (not necessarily the "front" of this Queue's data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        void dequeue();

        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of this Queue's data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType &peek() const;
};
#include "Queue.cpp"
#endif