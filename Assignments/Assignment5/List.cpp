/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 *                    Based on the Hashing strategy and the open addressing
 *                    collision resolution strategy called linear probing hashing.
 * Class Invariant: Data collection with the following characteristics:
 *                  - Each element is unique (no duplicates).
 *
 * Author: AL
 * Completed by: Steven Wong
 * Date: Last modified: Dec 2022
 */

#include <iostream>
#include "List.h"
#include "EmptyDataCollectionException.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "UnableToInsertException.h"

// Constructor
List::List(unsigned int (*hFcn)(string))
{
    this->hashFcn = hFcn;
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{
    delete[] hashTable;
    hashTable = nullptr;
}

// Description: Returns the total element count currently stored in List.
// Postcondition: List remains unchanged.
unsigned int List::getElementCount() const
{
    return elementCount;
}

// Description: Insert an element.
// NOTE: You do not have to expand the hashTable when it is full.
// Precondition: newElement must not already be in in the List.
// Postcondition: newElement inserted and elementCount has been incremented.
// Exception: Throws UnableToInsertException if we cannot insert newElement in the List.
//            For example, if the operator "new" fails, or hashTable is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the List.
void List::insert(Member &newElement)
{
    // Allocate memory for our hashTable if elementCount is 0
    if (getElementCount() == 0)
    {
        hashTable = new Member *[CAPACITY];
        if (hashTable == nullptr)
            throw UnableToInsertException("Unable to insert newElement in the List.");
        // Initialize all elements in hashTable to nullptr with memset
        memset(hashTable, 0, CAPACITY * sizeof(Member *));
    }

    // Check if newElement already exists in the List (hashTable) and throw exception if it does
    if (getElementCount() != 0)
    {
        try 
        {
            search(newElement);
        }
        catch (ElementDoesNotExistException &e)
        {
            // Calculate the index of the hashTable where we want to insert newElement
            unsigned int index = hashFcn(newElement.getPhone());
            // Linear probing
            while (hashTable[index] != nullptr)
            {
                index = (index + 1) % CAPACITY;
            }
            // Insert newElement into the hashTable
            hashTable[index] = &newElement;
        }
    }
}

// Description: Returns a pointer to the target element if found.
// Postcondition: List remains unchanged.
// Exception: Throws EmptyDataCollectionException if the List is empty.
// Exception: Throws ElementDoesNotExistException if newElement is not found in the List.
Member* List::search(Member &target) const
{
    Member *result = nullptr;
    // Check if List is empty
    if (getElementCount() == 0)
        throw EmptyDataCollectionException("List is empty.");

    // Iterate through the hashTable and search for target
    for (int i = 0; i < CAPACITY; i++)
    {
        if (hashTable[i] != nullptr && *hashTable[i] == target)
            result = hashTable[i];
    }
    // At this point, result is not contained in the List, throw exception
    if (result == nullptr)
        throw ElementDoesNotExistException("Element does not exist in the List.");
    
    return result;
}

// Description: Prints all elements stored in the List (unsorted).
// Postcondition: List remains unchanged.
void List::printList() const
{
    // For each index, if the element is not nullptr, print the element
    cout << "{" << endl;
    for (unsigned int i = 0; i < CAPACITY; i++)
    {
        if (hashTable[i] != nullptr)
            cout << *hashTable[i];
    }
    cout << "}" << endl;
}