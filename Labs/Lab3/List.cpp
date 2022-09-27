/*
 * List.cpp - Implementation of the List class
 *
 * Class Description: A data collection List ADT class:
 *                    linked list-based implementation. 
 *                    Its underlying data structure is a 
 *                    singly-headed singly-linked list (SHSL).
 *
 * Creation Date:
 * Author:
 */

#include <string>
#include <iostream>
#include "List.h"

using std::cout;
using std::cin;
using std::endl;

// Constructors and Destructors

// Description: Default constructor
List::List(){
	elementCount = 0;
	head = NULL;
}

// Description: Copy constructor creates a new List object as a copy of an existing List object.
List::List(const List& lst){
	elementCount = lst.elementCount;
	head = lst.head; //shallow copy - you need to fix this!

}

// Description: Destruct a List object, releasing all heap-allocated memory.
List::~List(){
	// You need to write this!

}

/**************************************************************************/
// List Operations
//
// Description: Append an element (newElement) to the list.
// Postcondition: newElement is inserted at the end of the list.
void List::append(int newElement){
	Node * newNode = new Node(newElement); //new Node with x

	// Check to see if list is empty
	if (head == NULL){
		// Make new Node the new head
		head = newNode;
	}else{
		// Move to the end of the list
		Node * current = head;
		while (current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	elementCount++;
	return;
}


/*
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot
 * foresee how it is to be displayed (in a TUI or GUI environment).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<.
 */
// Description: Prints the contents of the List from the first to the 
//              last element, along with the content of elementCount.
void List::printList(){
	Node * current = head;
	cout << "{"; //Nice format!
	// Traverse the list
	while (current != NULL){
		cout << current -> data; // Print data
		current = current -> next; // Go to next Node
		if (current != NULL){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be needed.
	return;
}
// end of implementation file of List class
