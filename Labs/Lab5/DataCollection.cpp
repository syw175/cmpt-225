/* 
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: No class invariant!
 *
 * Author: AL
 * Date: Oct. 2022
 */

#include <iostream>
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

   // Put your code here!
   // When would I be unable to append?
   
   // Create a new node for newElement
   Node *toBeAppended = new Node(newElement);

   // Check if memory allocation failed, and throw an exception
   if (toBeAppended == nullptr)
   {
      throw UnableToInsertException("Memory alloc failed");
   }

   // If head is nullptr, set it to ToBeAppended
   if (head == nullptr)
      head = toBeAppended;
   else
   {
      Node *current = head;
      while (current->next != nullptr)
      {
         current = current->next;
      }
      current->next = toBeAppended;
   }

   return;
}

// Description: Prepends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   
   // Put your code here!

   // Create a new node for newElement
   Node *toBePrepended = new Node(newElement);

   // Check if memory allocation was successful and throw an error if not
   if (toBePrepended == nullptr)
      throw UnableToInsertException("Error memory allocation issue");

   // If the head is nllptr, set it to ToBePrepended
   if (head == nullptr)
      head = toBePrepended;
   else
   {
      toBePrepended->next = head;
      head = toBePrepended;
   }
   return;
}
 
// Description: Prints the content of this DataCollection "thisDC".
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; 
   while (current != nullptr){
      cout << current -> data; 
      current = current -> next; 
      if (current != nullptr){
         cout << ","; 
      }
   }
   cout << "}";

   return os;

} 
