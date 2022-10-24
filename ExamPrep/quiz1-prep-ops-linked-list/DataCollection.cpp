/* 
 * DataCollection.cpp
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
 // Copy constructor
   // 1. Create a new node
   // 2. Copy the data from the old node to the new node
   // 3. Set the next pointer of the new node to the next node in the list
   // 4. Repeat until the end of the list
   head = nullptr;
   Node *current = DC.head;
   while (current != nullptr)
   {
      this->append(current->data);
      current = current->next;
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
   // Iterate through the list to the ith index and remove the element
   // If the list is empty, throw exception
   if (head == nullptr)
      throw UnableToInsertException("Unable to remove element at index because the list is empty");
   // If the index is 1, remove the head
   else if (index == 1)
   {
      Node *tmp = head->next;
      delete head;
      head = tmp;
   }
   // If the index is greater than 1, iterate through the list to the ith index
   // While iterating, if the next node is nullptr, throw exception
   else
   {
      // Create a pointer to the current node
      Node *current = head;
      for (int i = 1; i < index; i++)
      {
         // If the next node is nullptr, throw exception
         if (current->next == nullptr)
            throw UnableToInsertException("Unable to remove element at index because the index is out of bounds");
         // If the next node is not nullptr, move to the next node
         current = current->next;
      }
      // At this point, the current node is the ith index
      // Remove the ith index and fix the pointers to the adjacent nodes
      Node *tmp = current->next->next;
      delete current->next;
      current->next = tmp;
   }
}

// Description: Remove the second last element of the linkedlist
// Throws an Unable to InsertException (FOR SAKE OF TIME) if unable to remove this element
void DataCollection::removeSecondLastElement()
{
   // Throw an exception if the list is empty or has only one element
   if (head == nullptr || head->next == nullptr)
      throw UnableToInsertException("Unable to remove second last element because the list is empty or has only one element");

   // Otherwise iterate through the list until the second last element is found
   Node *current = head;
   while (current->next->next != nullptr)
   {
      current = current->next;
   }
   // Remove the second last element
   delete current->next;
   current->next = nullptr;
}

// Description: Reverse the linkedlist
// WORKING AND TESTED
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
   // Create a new node to be inserted
   Node *toBeInserted = new Node(elementToAdd);

   // If the list is empty and the index is 1, insert the element
   if (head == nullptr && index == 1)
      head = toBeInserted;

   // If the list is not empty and the index is 1, insert the element
   else if (head != nullptr && index == 1)
   {
      toBeInserted->next = head;
      head = toBeInserted;
   }
   // Otherwise iterate through the list to the ith index
   else
   {
      // Create a pointer to the current node
      Node *current = head;
      for (int i = 1; i < index; i++)
      {
         // If the next node is nullptr, throw exception
         if (current->next == nullptr)
            throw UnableToInsertException("Unable to insert element at index because the index is out of bounds");
         // If the next node is not nullptr, move to the next node
         current = current->next;
      }
      // At this point, the current node is the ith index
      // Insert the element and fix the pointers to the adjacent nodes
      toBeInserted->next = current->next;
      current->next = toBeInserted;
   }
}

// Description: Insert the targetElement in its correct ascending order position
// If the element already exists in the linked list, put it before or after
void DataCollection::insertAscendingOrder(const int elementToAdd)
{
   // Create a new node to be inserted
   Node *toBeInserted = new Node(elementToAdd);
   // If the list is empty, set head to the new node
   if (head == nullptr)
      head = toBeInserted;
   // If the list is not empty, iterate through the list
   else
   {
      // Create a pointer to the current node
      Node *current = head;
      // If the element to be inserted is less than the head, insert it before the head
      if (elementToAdd < head->data)
      {
         toBeInserted->next = head;
         head = toBeInserted;
      }
      // If the element to be inserted is greater than the head, iterate through the list
      else
      {
         while (current->next != nullptr)
         {
            // If the element to be inserted is less than the next node, insert it before the next node
            if (elementToAdd < current->next->data)
            {
               toBeInserted->next = current->next;
               current->next = toBeInserted;
               return;
            }
            // If the element to be inserted is greater than the next node, move to the next node
            current = current->next;
         }
         // If the element to be inserted is greater than all the elements in the list, insert it at the end
         current->next = toBeInserted;
      }
   }
}


// Description: Insert the targetElement in its correct descending order position
// If the element already exists in the linked list, put it before or after
void DataCollection::insertDescendingOrder(const int elementToAdd)
{
   // Create a new node to be inserted
   Node *toBeInserted = new Node(elementToAdd);
   // If the list is empty, set head to the new node
   if (head == nullptr)
      head = toBeInserted;
   // If the list is not empty, iterate through the list
   else
   {
      // Create a pointer to the current node
      Node *current = head;
      // If the element to be inserted is greater than the head, insert it before the head
      if (elementToAdd > head->data)
      {
         toBeInserted->next = head;
         head = toBeInserted;
      }
      // If the element to be inserted is less than the head, iterate through the list
      else
      {
         while (current->next != nullptr)
         {
            // If the element to be inserted is greater than the next node, insert it before the next node
            if (elementToAdd > current->next->data)
            {
               toBeInserted->next = current->next;
               current->next = toBeInserted;
               return;
            }
            // If the element to be inserted is less than the next node, move to the next node
            current = current->next;
         }
         // If the element to be inserted is less than all the elements in the list, insert it at the end
         current->next = toBeInserted;
      }
   }
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
