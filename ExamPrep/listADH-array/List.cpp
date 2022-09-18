/*
 * List.cpp  ***Using a heap-allocated array***
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates allowed).
 *                   - Position-oriented list.
 *                   - List position of elements start at 1 (not 0). 
 *
 * Inspired on: May 18, 2016 - inspired from List from our textbook.
 * Date: Sept. 16 (latest modification)
 * Author: AL
 * Implemented by: Steven Wong
 */

#include <iostream>
#include "List.h"

using namespace std;

// Constructor
List::List()
{
    elements = new int[CAPACITY];
    elementCount = 0;
}

// Destructor
List::~List()
{
    delete [] elements;
}

// Returns the current number of elements in the List.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// Insert newElement at newPosition in the List
// Postcondition: If 1 <= newPosition <= getElementCount() + 1,  the insertion
//                is successful, newElement is at newPosition in the List,
//                other elements, located after newElement, "have moved" 1 position up, 
//                and the returned value is true. Otherwise, false is returned.
bool List::insert(unsigned int newPosition, const int& newElement)
{
    // Validate the position given by the client
    if (newPosition < 1 || newPosition > getElementCount() + 1) return false;

    // Check if the List is full
    if (getElementCount() == CAPACITY) return false;
  
    // Move the elements to make room for the new element
    for (int i = getElementCount(); i >= newPosition; i--)
    {
        elements[i] = elements[i - 1];
    }
    // Set the new element
    elements[newPosition - 1] = newElement;

    // Increment the element count
    elementCount++;
    return true;
}

// Description: Removes the element at position in the List 
// Postcondition: If 1 <= position <= getElementCount() and the removal is successful,
//                the element at position in the List is removed, and
//                other elements "have moved" 1 position down, 
//                and the returned value is true. Otherwise, false is returned.
bool List::remove(unsigned int position)
{
    // Validate the position given by the client
    if (position < 1 || position > getElementCount()) return false;

    // Move the elements to fill the gap
    for (int i = position - 1; i < getElementCount() - 1; i++)
    {
        elements[i] = elements[i + 1];
    }
    // Decrement the element count
    elementCount--;
    return true;
}

// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
void List::clear()
{
    elementCount = 0;
}

// Description: Returns the element at position in the List.
// Precondition: 1 <= position <= getElementCount().
int List::getElement(unsigned int position) const
{
    // Validate the position given by the client
    if (position < 1 || position > getElementCount()) return false;

    // Return the element at the given position
    return elements[position - 1];
}

// Description: Prints all elements in the List.
void List::printList() const
{
    // Check if the list is empty
    if (getElementCount() == 0)
        cout << "The list is empty" << endl;
    else
        for (unsigned int i = 1; i <= getElementCount(); i++)
        {
            cout << getElement(i) << " ";
        }
    // Insert a new line and flush the output buffer
    cout << endl;
}