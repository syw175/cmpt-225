/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Each element is in descending order of cell phone number.
 *
 * Author: Steven Wong
 * 
 * Last modified: Sept. 2022
 */

#include <iostream>
#include "List.h"
#include "Member.h"

using namespace std;

// Default constructor
List::List() {}

// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    this->clear();
}

// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const
{
    return elementCount;
}

/* Description: Insert an element.
 * Precondition: newElement must not already be in data collection.  
 * Postcondition: newElement inserted in its proper place in List
 *                and elementCount has been incremented.   
 */
bool List::insert(Member& newElement)
{
   bool inserted = true;

    // Do not insert newElement if it already exists in the data structure
    if (search(newElement) != NULL)
    {
        inserted = false;
    }
    // If newElement is not in the list, insert it in its proper place
    else
    {
        // If the list is empty, allocate memory for the list
        if (getElementCount() == 0)
        {
            elements = new Member[CAPACITY];
        }

        // If the list is not empty, check if the list at capacity
        if (getElementCount() == CAPACITY)
        {
            inserted = false;
        }
        // If the list is not full, insert newElement in its proper sorted place
        else 
        {
            // Find the correct index position to insert the newElement
            unsigned int index = 0;
            while (index < getElementCount() && newElement < elements[index])
            {
                index++;
            }

            // Shift all elements after the index to the right
            for (unsigned int i = getElementCount(); i > index; i--)
            {
                elements[i] = elements[i - 1];
            }

            // Insert newElement at the index
            elements[index] = newElement;
            elementCount++;
        }
    }
    return inserted;
}

/* Description: Remove an element. 
 * Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
 *                and elementCount has been decremented.
 */
bool List::remove(Member& toBeRemoved)
{
    bool result = true;

    // Check whether the element toBeRemoved exists in the data structure
    if (search(toBeRemoved) == NULL)
    {
        result = false;
    }
    else
    {
        // Find the index position of the element to be removed
        unsigned int i = 0;
        for (i = 0; i < getElementCount(); i++)
        {
            if (toBeRemoved == elements[i])
                break;
        }

        // Shift all elements to the right of the element to be removed to the left
        for (int j = i; j < getElementCount() - 1; j++)
        {
            elements[j] = elements[j + 1];
        }

        // Decrement the element count
        elementCount--;

        // If the list is empty, deallocate the array from the heap
        if (getElementCount() == 0)
            this->clear();
    }
    return result;
} 

// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
//                 List is returned to the default state in the constructor.
void List::clear()
{
   delete [] elements;
   elements = NULL;
   elementCount = 0;
   return;
}

// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll()
{
    this->clear();
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search(Member& target)
{
    // Initialize a pointer to a Member object
    Member *person = NULL;
    if (getElementCount() != 0)
    {
        // Iterate through the array until we find the target
        for (unsigned int i = 0, j = getElementCount(); i < j; i++)
        {
            // If we find the target, set person to the address of the target
            if (elements[i] == target) person = &elements[i];
        }
    }
    // Return the address of the target or NULL if not found
    return person;
}

// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)
void List::printList()
{
    // Check if the list is not empty before printing
    if (getElementCount() != 0)
    {
        // Iterate through the array and print each element
        for (unsigned int i = 0, j = getElementCount(); i < j; i++)
        {
            cout << elements[i];
        }
    }
}
