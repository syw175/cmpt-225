/*
 * BST.h
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 * 
 * Date of last modification: December 2022
 */

#ifndef BST_H
#define BST_H

#include "UnableToInsertException.h"
#include <algorithm> 
#include <cmath>


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
	
  // Description: Recursive insertion into a binary search tree.
  //              Returns true when "anElement" has been successfully inserted into the 
  //              binary search tree. Otherwise, returns false.
  void insertR(BSTNode * newElement, BSTNode * current);

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void printInOrderR(BSTNode * current) const;
	
  // Description: Recursive preorder traversal of a binary search tree in order to build its copy.
  void copyR(BSTNode * current);

  // Description: Recursive postorder traversal of a BST in order to release heap memory allocated to BSTNode.
  void destroyR(BSTNode * current);

  // Description: Recursive method to determine the number of nodes in a binary search tree.
  unsigned int numberOfNodesR(BSTNode *current) const;

  // Description: Recursive method to determine the height of a binary search tree.
  unsigned int heightR(BSTNode *current) const;

  // Description: Recursive method to find the sumOfAllNodes
  unsigned int sumOfAllNodesR(BSTNode *current) const;

  // Description: Find the minimum element in the binary search tree recursively.
  int findMinR(BSTNode *current) const;

  // Description: Find the maximum element in the binary search tree recursively.
  int findMaxR(BSTNode *current) const;

  // Description: Recurisve method to determine if a binary search tree contains a given element.
  bool containsR(int anElement, BSTNode *current) const;

  // Description: Recursive method to determine the number of leaves in a binary search tree.
  unsigned int numberOfLeavesR(BSTNode *current) const;

  // Description: Recursive method to determine the number of noes at depth k
  int numberOfNodesAtDepthKR(int k, BSTNode *current) const;

  // Description: Recursive method to determine the number of nodes with two children
  int numberOfNodesWithTwoChildrenR(BSTNode *current) const;

  // Description: Recursive method to determine if a binary search tree is balanced.
  bool isBalancedR(BSTNode *current) const;

  // Description: Returns the sum of all elements in a range [min, max] in a binary search tree.
  int sumOfRangeR(int min, int max, BSTNode *current) const;

  // Description: Recursive method to determine if a binary search tree is a full binary tree.
  bool isFullR(BSTNode *current) const;

  // Description: Recursive method to determine if a binary search tree is a complete binary tree.
  bool isCompleteR(BSTNode *current) const;

public:

// You cannot change the prototype of the public methods of this class.


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
   
  // Description: Returns the number of elements currently stored in the binary search tree.  
  unsigned int getElementCount() const;

/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).  
  void insert(int newElement);

  // Description: Prints the content of the binary search tree in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void printInOrder() const;

  // Description: Returns the height of this binary search tree.
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int height() const;

  // Description: Returns the number of nodes in this binary search tree.
  //              You cannot return "elementCount".
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.		
  unsigned int numberOfNodes( ) const;

  // Description: Returns the sum of all elements in the binary search tree.
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int BST::sumOfAllNodes() const;
  
  // Description: Return the minimum element in the binary search tree.
  int findMin() const;

  // Description: Return the maximum element in the binary search tree.
  int findMax() const;

  // Description: Returns true if the binary search tree contains a given element.
  bool contains(int anElement) const;

  // Description: Returns the number of leaves in the binary search tree.
  unsigned int numberOfLeaves() const;

  // Description: Returns the number of nodes at depth k in the binary search tree.
  int numberOfNodesAtDepthK(int k) const;

  // Description: Returns the number of nodes with two children in the binary search tree.
  int numberOfNodesWithTwoChildren() const;

  // Description: Returns true if the binary search tree is balanced.
  bool isBalanced() const;

  // Description: Returns the depth of the given element in the binary search tree.
  int depthOf(int anElement) const;

  // Description: Returns the sum of all elements in a range [min, max] in the binary search tree.
  int sumOfRange(int min, int max) const;

  // Description: Returns true if the binary search tree is a full binary tree.
  bool isFull() const;

  // Description: Returns true if the binary search tree is a complete binary tree.
  bool isComplete() const;
};

#endif
