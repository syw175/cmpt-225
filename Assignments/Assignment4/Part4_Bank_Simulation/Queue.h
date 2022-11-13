/*
 * Queue.h
 * 
 * Description: This is a linked list-based implementation of a Queue ADT class.
 *              Its underlying data structure is a doubly-headed doubly-linked list (DHDL).
 *              Class Invariant:  FIFO or LILO order
 *
 * Author: SW
 * Date: Last modified: November 2022
 */

#include <iostream>
#include <ostream>
#include "EmptyDataCollectionException.h"

#ifndef QUEUE_H
#define QUEUE_H

template <class ElementType>
class Queue {
    private:
        class Node {               
            public:
                // Data members
                ElementType &data;
                Node *next;
                Node *prev;

                // Default constructor
                Node() : next(nullptr), prev(nullptr) {}
                // Parameterized constructor
                Node(ElementType &data) : data(data), next(nullptr), prev(nullptr) {}
        };

        Node *head = nullptr;
        Node *tail = nullptr;

    /******* Start of Queue Public Interface *******/
    public:
        // Default constructor
        Queue();

        // Copy constructor
        Queue(const Queue &src);

        // Destructor
        ~Queue();

        // Overload the << operator for Queue class
        // Description: For testing purposes only, to print out elements in the Queue
        // Time Efficiency: O(n)
        // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Making_New_Friends
        // https://www.youtube.com/watch?v=POa_V15je8Y
        // friend std::ostream &operator<< (std::ostream&os, Queue<ElementType> const &q)
        // {
        //     // If the queue is empty, print "{}"
        //     if (q.isEmpty())
        //         os << "{}";
        //     // If the queue is not empty, print "{element1, element2, ...}"
        //     else
        //     {
        //         os << "{";
        //         Node *current = q.head;
        //         // Loop through queue and separate elements with a comma
        //         while (current != nullptr)
        //         {
        //             os << current->data;
        //             if (current->next != nullptr)
        //                 os << ", ";
        //             // Move to next node
        //             current = current->next;
        //         }
        //         os << "}";
        //     }
        //     return os;
        // }

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

        // Description: Prints out the elements in this Queue for TESTING PURPOSES
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(n)
        void print() const;
};
#include "Queue.cpp"
#endif