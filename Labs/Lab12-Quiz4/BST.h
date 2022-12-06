/*
 * BST.h
 * 
 * Description: Binary Search Tree (BST) data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 * 
 * Date of last modification: Nov. 2022
 */

#ifndef BST_H
#define BST_H

#include "UnableToInsertException.h"


class BST {
	
private:

  class BSTNode {

    public:
  
      int element = 0;
      BSTNode * left = nullptr;
      BSTNode * right = nullptr;

      // Constructors
      BSTNode() {}
      BSTNode(int element) { this->element = element; }

      BSTNode(int element, BSTNode * left, BSTNode * right) {
        this->element = element;
        this->left = left;
        this->right = right;
      }

      // Boolean helper functions
      bool isLeaf() const { return (left == nullptr && right == nullptr); }
      bool hasLeft() const { return (left != nullptr); }
      bool hasRight() const { return (right != nullptr); }

  };
  
/* Data Members */

  // You cannot change the following data members of this class.

  BSTNode * root = nullptr; 
  unsigned int elementCount = 0;          

/* Utility methods */
  	
  // Feel free to add private methods to this class.
	
  // Description: Recursive insertion into this BST.
  void insertR(BSTNode * newElement, BSTNode * current);

  // Description: Recursively traverse the this BST
  //              printing its elements in order.   
  void printInOrderR(BSTNode * current) const;
	
  // Description: Recursive preorder traversal of this BST in order to build its copy.
  void copyR(BSTNode * current);

  // Description: Recursive postorder traversal of this BST in order to release heap memory allocated to BSTNode.
  void destroyR(BSTNode * current);

  unsigned int numberOfLevelsR(BSTNode *current) const;

  int sumR(BSTNode *current) const;






public:

  // You cannot change the prototype of the public methods of this class.
  // You cannot add public methods to this class.  


/* Constructors and Destructor */

  // Default constructor: Constructs an empty tree.
  BST();            

  // Parameterized constructor
  BST(int element);        

  // Copy constructor
  BST(const BST & aBST);

  // Destructor 
  ~BST();


/* Getters and setters */
   
  // Description: Returns the number of elements currently stored in this BST.  
  unsigned int getElementCount() const;
  

/* BST Operations */

  // Description: Inserts an element into this BST.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).  
  void insert(int newElement);

  // Description: Prints the content of this BST in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void printInOrder() const;

  // Description: Computes and returns the sum of all the elements (sum of their value) in this BST.
  // Feel free to implement this method as an iterative method or
  // as a wrapper method calling a recursive method.
  int sum() const;

  // Description: Returns the number of levels of this BST. 
  // Feel free to implement this method as an iterative method or
  // as a wrapper method calling a recursive method.
  unsigned int numberOfLevels() const;

};

#endif
