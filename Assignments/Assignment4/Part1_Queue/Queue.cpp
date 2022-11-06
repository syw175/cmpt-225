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

#include <iostream>
#include <ostream>
#include "EmptyDataCollectionException.h"
#include "Queue.h"

template <class ElementType>
// Default constructor
Queue<ElementType>::Queue() {}

// Copy constructor
template <class ElementType>
Queue<ElementType>::Queue(const Queue<ElementType> &src)
{
    // If the source queue is empty, do nothing
    if (src.isEmpty())
        return;
    // If the source queue is not empty, copy the elements
    else
    {
        // Start at the head of the source queue
        Node *current = src.head;
        while (current != nullptr)
        {
            enqueue(current->data);
            current = current->next;
        }
    }
}

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
    return head == nullptr;
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

    // If the queue is empty, set head and tail to the new node
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Set the new node's prev to the current tail and update the tail's next
        newNode->prev = tail;
        tail->next = newNode;
        // Set the tail to the new node
        tail = newNode;
    }
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
    if (head == tail)
    {
        // Set head and tail to nullptr
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    // Case where queue has more than 1 element
    else
    {
        // Set the head to the next node and delete the old head
        Node *oldHead = head;
        head = head->next;
        delete oldHead;
    }
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
