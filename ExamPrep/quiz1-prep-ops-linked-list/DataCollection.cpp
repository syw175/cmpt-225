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
   // UNTESTED
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
   // UNTESTED
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
   // DONE AND TESTED
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
   // DONE AND TESTED
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

// Below follows SOME PRACTICE QUESTIONS
// Description: Remove the first occurence of a target element in the linked list
// Throw an UnableToInsertException if unable to remove
void DataCollection::removeTargetElement(const int elementToRemove)
{
   // WORKING AND TESTED WITH NO MEMORY LEAKS
   // If list is empty, throw exception
   if (head == nullptr)
      throw UnableToInsertException("Unable to remove targetElement because the list is empty");
   // If element to be removed is head, remove it and set head to nullptr
   else if (head->data == elementToRemove)
   {
      Node *tmp = head->next;
      delete head;
      head = tmp;
   }
   // Search the list, remove element, fix the pointers to the adjacent node and return
   else
   {
      // Create a pointer to the current node
      Node *current = head;
      while (current->next != nullptr)
      {
         // If the next node is the target element, remove it
         if (current->next->data == elementToRemove)
         {
            // Create a pointer to the node to be removed
            Node *tmp = current->next->next;
            delete current->next;
            current->next = tmp;
            // Return to exit the function
            return;
         }
         // If next node is not target element, move to the next node
         current = current->next;
      }
      // At this point, the target element was not found in the list
      throw UnableToInsertException("Unable to remove targetElement because it is not found in the list");
   }
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
   Node *curr = head;
   Node *prev = nullptr;
   Node *next = nullptr;
   // While current is not null
   while (curr != nullptr)
   {
      // Save current's pointer to the next element
      next = curr->next;
      // Reverse current's pointer to the previous element
      curr->next = prev;
      // Update the previous pointer
      prev = curr; 
      // Go to the next node
      curr = next;
   }
   // Update head ref
   head = prev;
}

// Description: Insert the targetElement at a specified ith "index", assume linkedlist starts at 1
// Throws an Unable to Insert Exception if unable to insert
void DataCollection::insertElementAt(const int elementToAdd, const int index)
{
   // Implement me
   // To Check

}

// Description: Insert the targetElement in its correct ascending order position
// If the element already exists in the linked list, put it before or after
void DataCollection::insertAscendingOrder(const int elementToAdd)
{
   // Implement me
   // UNTESTED
   // To Check
   Node *prev = nullptr;
   Node *curr = head;

   // Create a newNode containing elementToAdd
   Node *newNode = new Node(elementToAdd);
   // If list is empty, make newNode our head
   if (head == nullptr)
      head = newNode;
   // If the value of newNode is less than head, then set head to newNode
   else if (newNode->data < head->data)
   {
      newNode->next = head;
      head = newNode;
   }
   // Else, iterate through the linked list and find our proper place for newNode
   else
   {
      Node *prev = nullptr;
      Node *curr = head;
      while (curr != nullptr && curr->data < newNode->data)
      {
         prev = curr;
         curr = curr->next;
      }
      prev->next = newNode;
      newNode->next = curr;
   }
}


// Description: Insert the targetElement in its correct descending order position
// If the element already exists in the linked list, put it before or after
void DataCollection::insertDescendingOrder(const int elementToAdd)
{
   // Implement me
}

// Description: Prints the content of this DataCollection "thisDC".
ostream & operator<<(ostream & os, const DataCollection & thisDC)
{
   // TESTED AND WORKING
   DataCollection::Node *current = thisDC.head;
   cout << "{";
   
   while (current != nullptr)
   {
      cout << current -> data;
      current = current -> next;
      if (current != nullptr)
         cout << ",";
   }
   cout << "}";
   return os;
} 
