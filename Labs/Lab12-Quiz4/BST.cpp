/*
 * BST.cpp
 * 
 * Description: Binary Search Tree (BST) data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Completed by: Steven Wong
 * Date of last modification: Nov. 2022
 */
 
#include "BST.h"
#include <iostream>
#include <cmath>  // for max

using std::cout;
using std::endl;

/* Constructors and Destructor */

  // Default constructor: Constructs an empty tree.
  BST::BST() { }            

  // Parameterized constructor
  BST::BST(int element) {
    root = new BSTNode(element);
    elementCount = 1;
  }

  // Copy constructor
  BST::BST(const BST & aBST) {
  
    //cout << "BST Copy constructor called!" << endl;
           
    if ( aBST.elementCount == 0 ) {
      //cout << "aBST is empty!" << endl;	
      this->elementCount = 0;
      this->root = nullptr;
    }
    else
      copyR(aBST.root);	
  }

  // Destructor 
  BST::~BST() {

    //cout << "BST destructor called!" << endl;
     
    if ( this->root != nullptr ) {
      destroyR(root);
      root = nullptr;
    }

  }                


/* Helper methods */
  
  // Description: Recursive preorder traversal of this BST in order to build its copy.
  void BST::copyR(BSTNode * current) {
    
    //cout << "copyR called!" << endl;

    if (current != nullptr) {
      this->insert(current->element);
      copyR(current->left);
      copyR(current->right);
    }    
    return;
  }

  // Description: Recursive postorder traversal of this BST in order to release heap memory allocated to BSTNode.
  void BST::destroyR(BSTNode * current) {
  
    // cout << "destroyR called!" << endl;
  
    if (current != nullptr) {
      destroyR(current->left);
      destroyR(current->right);
      delete current;
      current = nullptr;
      this->elementCount--;
    }
    return;
  }

/* Getters and setters */
   
  // Description: Returns the number of elements currently stored in this BST.  
  unsigned int BST::getElementCount() const { 
    return this->elementCount;
  }
  

/* BST Operations */

  // Description: Inserts an element into this BST.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).   
  void BST::insert(int newElement) {
     
    BSTNode * newBSTNode = new BSTNode(newElement);
    if (newBSTNode == nullptr)
      throw UnableToInsertException("In insert(): operator new failed!");
    if (elementCount == 0 ) 
      root = newBSTNode;
    else {
      try { 
        insertR(newBSTNode, root);
      }
      catch ( UnableToInsertException & e ) {
        throw UnableToInsertException("Operator new failed!");
      }
    }

    this->elementCount++;
    return;
  }

  // Description: Recursive insertion into this BST.
  void BST::insertR(BSTNode * newBSTNode, BSTNode * current) { 

    if (newBSTNode->element < current->element) {

      if (!current->hasLeft()) {
        current->left = newBSTNode; 
        return;
      }
      else 
        insertR(newBSTNode, current->left);
    }
    else { 
      if (!current->hasRight()) {
        current->right = newBSTNode;
        return;
      }
      else 
        insertR(newBSTNode, current->right);
    }
  }  
  
  // Description: Computes and returns the sum of all the elements (sum of their value) found in this BST.
  // Feel free to implement this method as an iterative method or
  // as a wrapper method calling a recursive method.
  int BST::sum() const {
    // Recursively call our helper function sumR() which takes a pointer to root
    return sumR(root);
	
  }

  // Note: If called on an empty BST, we will receive an output of 0
  // Recursive helper method for sum()
  int BST::sumR(BSTNode *current) const
  {
    // Base Case: If current node is nullptr, then it's value is 0
    if (!current) return 0;
    // Recursive Case: Add current's element to the running sum and add the values of the
    //                 left subtree and right subtree. 
    return current->element + sumR(current->left) + sumR(current->right);
  }


  // Description: Returns the number of levels of this BST. 
  // Feel free to implement this method as an iterative method or
  // as a wrapper method calling a recursive method.
  unsigned int BST::numberOfLevels() const {
    // Recursively call our helper function numberOfLevelsR which takes a pointer to root
    return numberOfLevelsR(root);
	
  }

  // Note: If called on an empty BST, we will receive an output of 0
  // Recursive helper method for numberOfLevels()
  unsigned int BST::numberOfLevelsR(BSTNode *current) const
  {
    // Base Case: If current node is nullptr, then the corresponding level result is 0
    if (!current) return 0;
    // Recursive Case: For each level traversed add 1, calculate the level of the left
    //                 subtree and right subtree. Whichever is higher is our desired level
    return 1 + std::max(numberOfLevelsR(current->left), numberOfLevelsR(current->right));
  }

  // Description: Prints the content of this BST in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void BST::printInOrder() const {

    cout << "Printing BST with elementCount = " << elementCount << endl;
    cout << "{ ";
    if (elementCount != 0) printInOrderR(root);
    cout << "}";

    return;
  }


  // Description: Recursively traverse this BST printing its elements in order.   
  void BST::printInOrderR(BSTNode *current) const {
    if (current != nullptr) {
      printInOrderR(current->left);
      cout << current->element << " ";
      printInOrderR(current->right);
    }
    return;
  }
