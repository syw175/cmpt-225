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

#include <cassert>
#include "Stack.h"
                
// Default Constructor
Stack::Stack() {}

// Destructor
Stack::~Stack()
{
    // Iterate through the linked list and deallocate nodes from the heap
    StackNode *current = head;
    while (current != nullptr)
    {
        StackNode *temp = current->next;
        delete current;
        current = temp;
    }
}

// Returns true if the Stack is empty and false otherwise
bool Stack::isEmpty() const
{
    return elementCount == 0;
}

// Retrieve and return the top most element of the stack 
int &Stack::peek() const
{   
    // Pre-Condition: The stack must not be empty
    assert(!isEmpty());

    // Iterate to the last node in the SHSL linked list (the top of the stack)
    StackNode *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Return the data of the top most element in the stack
    return current->data;
}

// Insert an element onto the top of the stack and return true if successful, false otherwise
bool Stack::push(int &newElement)
{
    // Incomplete
    bool status = true; 

    StackNode *element = new StackNode();

    // Check if memory allocation failed
    if (!element)
        return false;

    element->data = newElement;
    element->next = nullptr;

}

// Remove the top most element of the stack, return true if successful, false otherwise
bool Stack::pop()
{
    // Incomplete
    bool status = true;

    // Check whether that stack is empty
    if (isEmpty())
    {
        status = false;
    }
    else
    {
        // Iterate to the last node in the SHSL linked list (the top of the stack)
        StackNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
    }
    // Remove the top node
}
