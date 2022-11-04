/*
 * Queue.cpp
 * 
 * Description: This is a linked list-based implementation of a Queue ADT class.
 *              Its underlying data structure is a doubly-headed doubly-linked list (DHDL).
 *              Class Invariant:  FIFO or LILO order
 *
 * Author: SW
 * Date: Last modified: November 2022
 */



// QUESTIONS: 
// ELEMENTCOUNT DATA MEMBER
// CAN I ADD AN ELEMENT COUNT GETTER?
// DOING THE PRINT OUT OF QUEUE, INVARIANT?
// COPY CONSTRUCTOR?

#include <iostream>
#include <ostream>
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

// Description: For testing purposes only, to print out elements in the Queue in FIFO order
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(n)
// https://stackoverflow.com/questions/4014294/operator-overloading-on-class-templates
// https://en.cppreference.com/w/cpp/language/friend
template<class ElementType>
std::ostream &operator<< (std::ostream &os, const Queue<ElementType> &q)
{
    // If the queue is empty, print "{}"
    if (q.isEmpty())
        os << "{}" << std::endl;
    else
    {
        // Print out the elements in the queue in FIFO order
        os << "{";
        Queue<ElementType>::Node *current = q.head;
        while (current != nullptr)
        {
            os << current->data;
            if (current->next != nullptr)
                os << ", ";
            current = current->next;
        }
        os << "}" << std::endl;
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
    Node *newNode = new Node(newElement);
    // If memory alloc failed, we cannot insert.. return
    if (!newNode)
        return false;
    
    // Case where the Queue is empty, head and tail are both newNode
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    // Case where Queue has one or more elements
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }
    elementCount++;
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue()
{
    // If the queue is empty, throw an exception
    if (isEmpty())
        throw EmptyDataCollectionException("Cannot dequeue from an empty Queue");

    // Case where queue only has 1 element
    if (elementCount == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    // Case where queue has 2 elements
    else if (elementCount == 2)
    {
        delete head;
        head = tail;
        head->prev = nullptr;
    }
    // Case where queue has 3 or more elements
    else
    {
        Node *tmp = head->next;
        delete head;
        head = tmp;
        head->prev = nullptr;
    }
    elementCount--;
    return;
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
