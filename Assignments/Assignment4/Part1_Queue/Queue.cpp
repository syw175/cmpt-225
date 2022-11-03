/*
 * Queue.cpp
 * 
 * Description: This is a linked list-based implementation of a Queue ADT class.
 *              Its underlying data structure is a doubly-headed singly-linked list (DHSL).
 *              Class Invariant:  FIFO or LILO order
 *
 * Author: SW
 * Date: Last modified: November 2022
 */



// QUESTIONS: 
// CAN I ADD AN ELEMENT COUNT GETTER?
// DOING THE PRINT OUT OF QUEUE, INVARIANT?

#include <iostream>
#include "EmptyDataCollectionException.h"
#include "Queue.h"

template <class ElementType>
// Default constructor
Queue<ElementType>::Queue() {}

// Destructor
template <class ElementType>
Queue<ElementType>::~Queue()
{
    // Dequeue until no elements are left...
    while (!isEmpty())
        dequeue();
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    // Check w/ TAs
    // return elementCount == 0;
    return head == nullptr && tail == nullptr;
}

// Description: For testing purposes only, to print out elements in the Queue
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(n)
template <class ElementType>
std::ostream &operator<<(std::ostream &os, const Queue<ElementType> &q)
{
    // If the queue is empty, print "EMPTY"
    if (q.isEmpty())
        os << "{}" << std::endl;
    else
    {
        os << "{";
        Node<ElementType> *curr = head;
        while (curr != tail)
        {
            os << curr->data;
            curr = curr->next;
        }
        os << curr->data << "}" << std::endl;
    }
    return os;
}

// Description: Inserts newElement at the "back" of this Queue
//              (not necessarily the "back" of this Queue's data structure)
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement)
{

}

// Description: Removes (but does not return) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue()
{

}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const
{
    // If the queue is empty, throw an exception
    if (isEmpty())
        throw EmptyDataCollectionException("Cannot peek into an empty Queue");
    
    // Return the element at the front of the Queue
    return head->data;
}
