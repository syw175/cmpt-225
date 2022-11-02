/*
 * Node.cpp
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */

#include "Node.h"

template <class ElementType>
Node<ElementType>::Node() { }

template <class ElementType>
Node<ElementType>::Node(ElementType &theData) : data(theData) { }

template <class ElementType>
Node<ElementType>::Node(ElementType &theData, Node * theNextNode) : data(theData), next(theNextNode) { }