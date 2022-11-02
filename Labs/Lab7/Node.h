/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 
#ifndef NODE_H
#define NODE_H


class Node {
public:

   // Public attributes
   int data = 0;            // The data in the node
   Node * next = nullptr;   // Pointer to next node
	
   // Constructors (why no destructor?)
   Node();
   Node(int theData);
   Node(int theData, Node * theNextNode);

}; 
#endif
