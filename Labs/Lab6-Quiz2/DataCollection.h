/* 
 * D203+D204
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list.
 * Class Invariant: No class invariant!
 *
 * Author: AL
 * Date: Oct. 2022
 */
 
#ifndef DATA_COLLECTION_H
#define DATA_COLLECTION_H

using std::ostream;

class DataCollection {

   private:

      // Description:  Nodes for a singly-linked list
      class Node {
         public:
            // Note: data can be assigned any negative or positive integer values or zero.
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
      
      // Description: Removes and returns the element located in the middle of the DataCollection.
      //              The position of the elements in DataCollection ranges from [1 .. "total number of elements"].               
      //              When computing the position of the middle element, round up to nearest integral value.              
      // Exception Handling: Throws EmptyDataCollectionException.
      int removeMiddle();
            
      // Bonus Method: Will be marked only if you have implemented and submitted the above method.
      // Description: Computes and returns the average of the values of all elements found in the DataCollection.
      // Exception Handling: Throws EmptyDataCollectionException.
      float average();
            
      // Description: Prints the content of this DataCollection "thisDC".
      friend ostream & operator<<(ostream & os, const DataCollection & thisDC); 
      
};
#endif
