/* 
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: No class invariant!
 *
 * Author: Steven Wong
 * Date: Oct. 2022
 */
 
#ifndef DATA_COLLECTION_H
#define DATA_COLLECTION_H
#include <iostream>

using std::ostream;

class DataCollection {

   private:

      // Description:  Nodes for a singly-linked list
      class Node {
         public:
            int data;
            Node * next = nullptr;
         Node(int theData): data(theData) {}
      };
      // Data member: 
      Node * head = nullptr;  // head is the pointer to the first node

   public:

      // Description: Default constructor. Constructs a DataCollection object.
      DataCollection();

      // Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
      DataCollection(const DataCollection & DC);

      // Description: Destructs a DataCollection object, releasing all heap-allocated memory.
      ~DataCollection();

      // Description: Appends an element (newElement) to the DataCollection.
      // Exception Handling: Throws UnableToInsertException.
      void append(int newElement);

      // Description: Prepends an element (newElement) to the DataCollection.
      // Exception Handling: Throws UnableToInsertException.
      void prepend(int newElement);



      // Below follows SOME PRACTICE QUESTIONS I MADE FOR QUIZ PREP
      // Description: Remove the first occurence of a target element in the linked list
      // Throw an UnableToInsertException if unable to remove
      void removeTargetElement(const int elementToRemove);

      // Description: Remove the second last element of the linkedlist
      // Throws an Unable to InsertException (FOR SAKE OF TIME) if unable to remove this element
      void removeSecondLastElement();

      // Description: Remove some element at a specified ith "index", assume linkedlist starts at 1
      // Throws an UnableToInsertException (FOR SAKE OF TIME ONLY...) if unable to remove element
      void removeElementAt(const int index);

      // Description: Reverse the linkedlist
      void reverseList();

      // Description: Insert the targetElement in its correct ascending order position
      // If the element already exists in the linked list, put it before or after
      void insertAscendingOrder(const int elementToAdd);

      // Description: Insert the targetElement in its correct descending order position
      // If the element already exists in the linked list, put it before or after
      void insertDescendingOrder(const int elementToAdd);

      // Description: Insert the targetElement at a specified ith "index", assume linkedlist starts at 1
      // Throws an Unable to Insert Exception if unable to insert
      void insertElementAt(const int elementToAdd, const int index);




      // Description: Prints the content of this DataCollection "thisDC".
      friend ostream & operator<<(ostream & os, const DataCollection & thisDC);
};
#endif
