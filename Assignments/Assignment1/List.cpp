/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Each element is in descending order of cell phone number.
 *                   - ***There is another class invariant: Add it here!*** ^^???
 *
 * Author: Steven Wong
 * 
 * Last modified: Sept. 2022
 */

#include <iostream>
#include "List.h"
#include "Member.h"

using namespace std;

// TODO
// Private Methods:
// Is that how you declare?
// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
void List::clear()
{
    // How to remove all elements from the list?
    // Perhaps calling the removeAll function()
    // Or just setting elementCount to 0
    elementCount = 0;
}

// Public Methods:
// Default constructor
List::List()
{
    // Initialize an array of Members on the heap with the default capacity
    elements = new Member[CAPACITY];

    // Initializing elementCount not required right?
    elementCount = 0;
}

// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    // Does this deallocate memory of the Member type objects??
    delete [] elements;
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
    // Check if newElement is already in the data collection
    if (search(newElement) == NULL) return false;

    // Iterate through the array until current !< next (We found the right place for it)


}

/* Description: Remove an element. 
 * Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
 *                and elementCount has been decremented.
 */
bool List::remove(Member& toBeRemoved)
{
    // Check if toBeRemoved exists in the data collection
    if (search(toBeRemoved) == NULL) return false;




}

// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll()
{
    // Call the remove?? 
    clear();
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search(Member& target)
{
    // Iterate through the elements...
    for (unsigned int i = 0, j = getElementCount(); i < j; i++)
    {
        // if the ith element is equal to the target element, return it
        if (elements[i] == *target) return elements[i];
    }

    // At this point, the element does not exist in the data collection... return NULL
    return NULL;
}

// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)
void List::printList()
{
    // CAN I USE THE FUNCTION THAT SAYS FOR TESTING PURPOES IN MEMBER.CPP??


    // Correct to assume that list elements are already sorted??
    for (unsigned int i = 0, j = getElementCount(); i < j; i++)
    {
        // Get the current member and print out their information
        Member curr = elements[i];
        cout <<  curr.getName() << ", " << curr.getPhone() << ", " << curr.getEmail() << ", " << curr.getCreditCard() << endl;
    }
}