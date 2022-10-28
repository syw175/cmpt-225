/*
 * D203+D204
 * DataCollection.cpp
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: No class invariant!
 *
 * Author: AL
 * Date: Oct. 2022
 */

#include <iostream>
#include <cmath>   
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::cin;
using std::endl;


// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection(){
   // cout << "DataCollection Default constructor called!" << endl;
}

// Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection & DC){
   // cout << "DataCollection Copy constructor called!" << endl;

   head = nullptr;
   if (DC.head != nullptr){
      Node *current = DC.head;
      while (current != nullptr){
         this->append(current->data); 
         current = current->next; 
      }
   }
}

// Description: Destructs a DataCollection object, releasing all heap-allocated memory.
DataCollection::~DataCollection(){
   // cout << "DataCollection Destructor called!" << endl;

   Node * temp = nullptr;
   for ( Node * toBeDeleted = head; toBeDeleted != nullptr; ) {
      temp = toBeDeleted->next;
      delete toBeDeleted;
      toBeDeleted = temp;
   }
   head = nullptr;
}

// Description: Appends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::append(int newElement){
   Node * newNode = new Node(newElement); 
   if ( newNode == nullptr )  
      throw UnableToInsertException(" in append(): new failed, newNode cannot be allocated heap memory."); 
   if (head == nullptr){
      head = newNode;
   }else{
      Node * current = head;
      while (current->next != nullptr){
         current = current->next;
      }
      current->next = newNode;
   }
   return;
}

// Description: Prepends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   Node * newNode = new Node(newElement); 
   if ( newNode == nullptr )  
      throw UnableToInsertException("in prepend(): new failed, newNode cannot be allocated heap memory."); 
   if (head != nullptr) newNode->next = head;
   head = newNode;

   return;
}
 
// Description: Removes and returns the element located in the middle of the DataCollection.
//              The position of the elements in DataCollection ranges from [1 .. "total number of elements"].               
//              When computing the position of the middle element, round up to nearest integral value.              
// Exception Handling: Throws EmptyDataCollectionException.
int DataCollection::removeMiddle() {
   // If head is nullptr, then the data collection is empty; throw EmptyDataCollectionException
   if (head == nullptr)
      throw EmptyDataCollectionException("Unable to remove the middle element because the Data Collection is empty");

   // Iterate through the linked list and count the number of elements contained it in
   int elementCount = 0; 
   Node *curr = head;
   while (curr != nullptr)
   {
      elementCount++;
      curr = curr->next;
   }

   // Calculate the middle position of the elements (and round up)
   int mid = ceil(elementCount/2.0);
   int elementRemoved = 0;
   Node *prev = nullptr;
   curr = head;

   // Iterate through the linked list until the middle position is reached
   for (int i = 1; i < mid; i++)
   {
      prev = curr;
      curr = curr->next;
   }

   // If the middle element is the first element in the linked list
   if (prev == nullptr)
   {
      head = curr->next;
      elementRemoved = curr->data;
      delete curr;
   }
   else
   {
      prev->next = curr->next;
      elementRemoved = curr->data;
      delete curr;
   }
   return elementRemoved;
}
      
// Bonus Method: Will be marked only if you have implemented and submitted the above method.
// Description: Computes and returns the average of the values of all elements found in the DataCollection.
// Exception Handling: Throws EmptyDataCollectionException.
float DataCollection::average() {

   // Iterate through the linked list and count the number of elements contained it in
   int elementCount = 0; 
   Node *curr = head;
   while (curr != nullptr)
   {
      elementCount++;
      curr = curr->next;
   }

   if (elementCount == 0)
      throw EmptyDataCollectionException("Cannot calculate the average, Data Collection is empty");

   float avg = 0;
   curr = head;
   while (curr != nullptr)
   {
      avg += curr->data;
      curr = curr->next;
   }

   return avg / elementCount;
}

// Description: Prints the content of this DataCollection "thisDC".
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; //Nice format!
   // Traverse the DataCollection
   while (current != nullptr){
      cout << current -> data; // Print data
      current = current -> next; // Go to next Node
      if (current != nullptr){
         cout << ","; // Print a comma unless at the end of DataCollection
      }
   }
   cout << "}"; // Don't print a newline - it might not be needed.

   return os;

} 
