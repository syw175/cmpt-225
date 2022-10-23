/* 
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: No class invariant!
 *
 * Author: Steven Wong
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
   Node *toBeAppended = new Node(newElement);

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


// Below follows SOME PRACTICE QUESTIONS I MADE FOR QUIZ PREP
// Description: Remove the first occurence of a target element in the linked list
void DataCollection::removeTargetElement(const int elementToRemove)
{
   // Implement me
}

// Description: Remove some element at a specified ith "index", assume linkedlist starts at 1
// Throws an UnableToInsertException (FOR SAKE OF TIME ONLY...) if unable to remove element
void DataCollection::removeElementAt(const int index)
{
   // Implement me
}

// Description: Remove the second last element of the linkedlist
// Throws an Unable to InsertException (FOR SAKE OF TIME) if unable to remove this element
void DataCollection::removeSecondLastElement()
{
   // Implement me
}

// Description: Reverse the linkedlist
void DataCollection::reverseList()
{
   // Implement me
}

// Description: Insert the targetElement at a specified ith "index", assume linkedlist starts at 1
// Throws an Unable to Insert Exception if unable to insert
void DataCollection::insertElementAt(const int elementToAdd, const int index)
{
   // Implement me
}

// Description: Insert the targetElement in its correct ascending order position
// If the element already exists in the linked list, put it before or after
void DataCollection::insertAscendingOrder(const int elementToAdd)
{
   // Implement me
}

// Description: Insert the targetElement in its correct descending order position
// If the element already exists in the linked list, put it before or after
void DataCollection::insertDescendingOrder(const int elementToAdd)
{
   // Implement me
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
