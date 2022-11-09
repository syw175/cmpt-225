/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 *
 */  

#include <iostream>
#include "BinaryHeap.h"

using std::cout;
using std::endl;

// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{

}

// Copy Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap<ElementType> &bh)
{

}

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
   delete[] heap;
   heap = nullptr;
}

// Description: Returns the number of elements in the BinaryHeap.
// Postcondition: BinaryHeap is unchanged.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{

}

// Description: Insert newElement in the BinaryHeap, return true if successful.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement)
{

}

// Description: Remove the element with the lowest value in the BinaryHeap.
// Precondition: BinaryHeap is not empty.
// Exception: Throws EmptyDataCollectionException if BinaryHeap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove()
{

}

// Description: Retrieve the element with the lowest value in the BinaryHeap.
// Precondition: BinaryHeap is not empty.
// Postcondition: The BinaryHeap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if BinaryHeap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const
{

}

// For testing purposes only.
// Description: Prints a string representation of the BinaryHeap.
// Postcondition: The BinaryHeap is unchanged.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::print() const
{
   // Print out the heap array.
}