/*
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Steven Wong
 * Date: October 2022
 */

#include <iostream>
#include <exception>
#include "Stack.h"

// Done
// Default Constructor
Stack::Stack() {}

// Done
// Destructor
Stack::~Stack()
{
    // Iterate through the linked list and deallocate nodes from the heap
    StackNode *current = head;
    while (current != nullptr)
    {
        StackNode *next = current->next;
        // Delete the current node and move to the next node
        delete current;
        current = next;
    }
}

// Done
// Returns true if the Stack is empty and false otherwise
bool Stack::isEmpty() const
{
    return size() == 0;
}

// Done
// Pre-Condition: The stack must not be empty
// Retrieve and return the top most element of the stack
int Stack::peek() const
{
    // Ensure that the pre-condition is met
    if (isEmpty())
        throw std::runtime_error("Stack is empty. Cannot peek.");
 
    // Iterate to the last node in the SHSL linked list (the top of the stack)
    StackNode *current = head;
    while (current->next != nullptr)
        current = current->next;

    // Return the data of the last node
    return current->data;
}

// Incomplete
// Insert an element onto the top of the stack and return true if successful, false otherwise
bool Stack::push(int newElement)
{
    bool pushed = true;
    // Create a new StackNode and set its data to the newElement
    StackNode *newNode = new StackNode;
    newNode->data = newElement;
    newNode->next = nullptr;

    // If memory allocation failed, set pushed to false
    if (newNode == nullptr)
        pushed = false;
    // If the stack is empty, set the head to newElement and increment elementCount
    else if (isEmpty())
    {
        head = newNode;
        elementCount++;
    }
    else
    {
        StackNode *current = head;
        while (current->next != nullptr)
            current = current->next;

        current->next = newNode;
        elementCount++;
    }
    return pushed;
}

// Done
// Remove the top most element of the stack, return true if successful, false otherwise
bool Stack::pop()
{
    bool popped = true;
    // If the stack is empty, set the status of popped to false
    if (isEmpty())
        popped = false;
    // If the stack is not empty, delete the last node
    else
    {
        // Iterate to the last node in the SHSL linked list (the top of the stack)
        StackNode *current = head;
        while (current->next != nullptr)
            current = current->next;

        // Delete the last node and decrement elementCount
        delete current;
        elementCount--;
        // If the stack is now empty, set the head to nullptr
        if (isEmpty())
            head = nullptr;
    }
    // Return the status of popped
    return popped;
}

// Done
// Returns the number of elements in the stack
unsigned int Stack::size() const
{
    return elementCount;
}
