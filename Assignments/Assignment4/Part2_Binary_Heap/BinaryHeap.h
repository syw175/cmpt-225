/* 
 * BinaryHeap.h
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 * 
 * Author: Steven Wong
 * Last Modification: November 2022
 *
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

template <class ElementType>
class BinaryHeap
{
    private:
        ElementType *elements; // Array of elements in the heap
        unsigned int elementCount; // Number of elements in the heap
        unsigned int capacity; // Current capacity of the heap array

        // Utility method
        // Description: Recursively put the array back into a ____________ Binary Heap.
        void reHeapDown(unsigned int indexOfRoot);


    public:
        // Description: Default Constructor
        BinaryHeap();

        // Description: Copy Constructor
        BinaryHeap(const BinaryHeap<ElementType> &b);

        // Description: Destructor
        ~BinaryHeap();

        // Description: Returns the number of elements in the BinaryHeap.
        // Postcondition: BinaryHeap is unchanged.
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Insert newElement in the BinaryHeap, return true if successful.
        // Time Efficiency: O(log2 n)
        bool insert(ElementType &newElement);

        // Description:
        // Precondition: BinaryHeap is not empty.
        // Exception: Throws EmptyDataCollectionException if BinaryHeap is empty.
        // Time Efficiency: O(log2 n)
        void remove();

        // Description:
        // Precondition: BinaryHeap is not empty.
        // Postcondition: The BinaryHeap is unchanged.
        // Exceptions: Throws EmptyDataCollectionException if BinaryHeap is empty.
        // Time Efficiency: O(1)
        ElementType &retrieve() const;
};
#include "BinaryHeap.cpp"
#endif
