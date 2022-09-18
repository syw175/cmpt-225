/*
 * List.h  ***Using a heap-allocated array***
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
 */


#include <string>

using namespace std;


class List 
{
private:
   constexpr static const int CAPACITY = 5; // Default capacity of array
                                            // Small capacity so can test when data collection becomes full.
                                            // As we are testing the code of our assignment, we can change the 
                                            // value given to this constant. 
   int * elements;                      // Data structure with size = CAPACITY
   unsigned int elementCount;               // Current number of elements in List

public:
   // Constructor
   List();

   // Destructor
   ~List();

    // Description: Returns the current number of elements in the List.
   unsigned int getElementCount() const;

   // Description: Insert newElement at newPosition in the List. 
   // Postcondition: If 1 <= newPosition <= getElementCount() + 1,  the insertion
   //                is successful, newElement is at newPosition in the List,
   //                other elements, located after newElement, "have moved" 1 position up, 
   //                and the returned value is true. Otherwise, false is returned.
   bool insert(unsigned int newPosition, const int& newElement);

   // Description: Removes the element at position in the List 
   // Postcondition: If 1 <= position <= getElementCount() and the removal is successful,
   //                the element at position in the List is removed, and
   //                other elements "have moved" 1 position down, 
   //                and the returned value is true. Otherwise, false is returned.
   bool remove(unsigned int position);

   // Description: Removes all elements from the List.
   // Postconditions: List contains no elements and the element count is 0.
   void clear();
   
   // Description: Returns the element at position in the List.
   // Precondition: 1 <= position <= getElementCount().
   int getElement(unsigned int position) const;

   // Description: Prints all elements in the List.
   void printList() const;

}; // end header file List
