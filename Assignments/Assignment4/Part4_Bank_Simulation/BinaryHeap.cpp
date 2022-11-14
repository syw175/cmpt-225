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

#include "BinaryHeap.h"

// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
   heap = new ElementType[INITIAL_CAPACITY];
   capacity = INITIAL_CAPACITY;
   elementCount = 0;
}

// Copy Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap<ElementType> &bh)
{
   // Allocate memory for the new heap
   heap = new ElementType[bh.capacity];
   capacity = bh.capacity;
   elementCount = bh.elementCount;

   // Copy the elements
   for (unsigned int i = 0; i < this->elementCount; i++)
      heap[i] = bh.heap[i];
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
   return elementCount;
}

// Description: Insert newElement in the BinaryHeap, return true if successful.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement)
{
   bool inserted = true;
   
   // Check if the heap is full
   if (getElementCount() == capacity)
   {
      // Expand the heap
      if (!expandHeap())
         inserted = false;
   }

   // If able to insert... 
   if (inserted)
   {
      // Insert the new element at the end of the heap
      heap[getElementCount()] = newElement;
      elementCount++;
      reHeapUp(getElementCount() -1);
   }
   return inserted;
}

// Description: Remove the element with the lowest value in the BinaryHeap.
// Precondition: BinaryHeap is not empty.
// Exception: Throws EmptyDataCollectionException if BinaryHeap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove()
{
   // If the Binary Heap is empty, throw EmptyDataCollectionException
   if (getElementCount() == 0)
      throw EmptyDataCollectionException("Remove() called on an empty Binary Heap");
   // Otherwise, remove the lowest element and maintain the Min Heap structure   
   else
   {
      // Swap the root with the last element in the array
      swap(ROOT, getElementCount() - 1);
      elementCount--;
      reHeapDown(ROOT);
   }
}

// Description: Retrieve the element with the lowest value in the BinaryHeap.
// Precondition: BinaryHeap is not empty.
// Postcondition: The BinaryHeap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if BinaryHeap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const
{
   if (getElementCount() == 0)
      throw EmptyDataCollectionException("Retrieve() method called with an empty Binary Heap");

   return heap[ROOT];
}

// For testing purposes only.
// Description: Prints a string representation of the BinaryHeap.
// Postcondition: The BinaryHeap is unchanged.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::print() const
{
   unsigned int power = 0;
   unsigned int value = 1;
   for(unsigned int i = 0; i < getElementCount(); i++)
   {
      if (i == value)
      {
         std::cout << std::endl;
         power++;
         value += (1 << power);
      }
      std::cout << heap[i] << " ";
   }
   std::cout << std::endl;
}

// Description: Recursively put the array back into a Minimum Binary Heap after remove().
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int index)
{   
   // Find indices of children and set the minimum index to the parent
   unsigned int indexOfLeftChild = leftChildIndex(index);
   unsigned int indexOfRightChild = rightChildIndex(index);
   unsigned int indexOfMin = index;

   // Get the index of the minimum child among the parent and its children
   if (indexOfLeftChild < getElementCount() && heap[indexOfLeftChild] <= heap[indexOfMin])
      indexOfMin = indexOfLeftChild;
   if (indexOfRightChild < getElementCount() && heap[indexOfRightChild] <= heap[indexOfMin])
      indexOfMin = indexOfRightChild;

   // If the minimum index is not the parent, swap the parent with the minimum child, continue reHeapDown
   if (indexOfMin != index)
   {
      swap(index, indexOfMin);
      reHeapDown(indexOfMin);
   }
}

// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int index)
{
   // Base case: elements[indexOfRoot] is the root of the heap
   if (index == ROOT) return;

   // Find the index of the parent
   unsigned int indexOfParent = parentIndex(index);

   // If the parent is greater than the child, swap them
   // We only have the <= operator defined for the ElementType, so we use that
   if (heap[index] <= heap[indexOfParent])
   {
      swap(index, indexOfParent);
      reHeapUp(indexOfParent);
   }
   return;
}

// Description: Swap the values of two elements in the array.
template <class ElementType>
void BinaryHeap<ElementType>::swap(unsigned int index1, unsigned int index2)
{
   ElementType temp = heap[index1];
   heap[index1] = heap[index2];
   heap[index2] = temp;
}

// Description: Expand the capacity of the BinaryHeap.
template <class ElementType>
bool BinaryHeap<ElementType>::expandHeap()
{
   bool expanded = true;
   // Create a new array with double the capacity
   ElementType *newHeap = new ElementType[capacity * 2];

   // Check if the new array was created successfully
   if (newHeap == nullptr)
      expanded = false;
   else
   {
      // Copy the elements from the old array to the new array
      for (unsigned int i = 0; i < capacity; i++)
         newHeap[i] = heap[i];

      // Delete the old array and set the heap pointer to the new array
      delete[] heap;
      heap = newHeap;
      capacity *= 2;
   }
   return expanded;
}