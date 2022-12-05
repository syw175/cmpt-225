/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Date of last modification: Nov. 2022
 */
 
#include "BST.h"
#include <iostream>

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
  
  // Description: Recursive preorder traversal of a binary search tree in order to build its copy.
  void BST::copyR(BSTNode * current) {
    
    //cout << "copyR called!" << endl;

    if (current != nullptr) {
      this->insert(current->element);
      copyR(current->left);
      copyR(current->right);
    }    
    return;
  }

  // Description: Recursive postorder traversal of a BST in order to release heap memory allocated to BSTNode.
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
   

  // Description: Returns the number of elements currently stored in the binary search tree.     
  unsigned int BST::getElementCount() const { 
    return this->elementCount;
  }


/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).   
  void BST::insert(int newElement) {
     
    // Binary search tree is empty, so add the new element as the root
    BSTNode * newBSTNode = new BSTNode(newElement);
    if (newBSTNode == nullptr)
      throw UnableToInsertException("In insert(): operator new failed!");
    if (elementCount == 0 ) // and root == nullptr
      root = newBSTNode;
    else {
      try { // can I let it flow through? no try/catch block?
        insertR(newBSTNode, root);
      }
      catch ( UnableToInsertException & e ) {
        throw UnableToInsertException("Operator new failed!");
      }
    }

    this->elementCount++;
    return;
  } 
  

  // Description: Recursive insertion into a binary search tree.
  //              Returns true when "anElement" has been successfully inserted into the 
  //              binary search tree. Otherwise, returns false.
  void BST::insertR(BSTNode * newBSTNode, BSTNode * current) { 
  
    // If the element to be inserted < the element at current node, insert it to the left subtree
    if (newBSTNode->element < current->element) {
      // If current node's left subtree is empty add the new node there
      if (!current->hasLeft()) {
        current->left = newBSTNode; // new BSTNode(anElement);
        return;
      }
      // Otherwise descend into the left subtree
      else 
        insertR(newBSTNode, current->left);
    }
    // If the element to be inserted > the element at current node, insert it to the right subtree
    else { // if ( element >=  current->getElement() ) {
      // If current node's right subtree is empty add the new node there
      if (!current->hasRight()) {
        current->right = newBSTNode; //new BSTNode(anElement);
        return;
      }
      // Otherwise descend into the right subtree
      else 
        insertR(newBSTNode, current->right);
    }
  }

  // Description: Prints the content of the binary search tree in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void BST::printInOrder() const {

    cout << "Printing BST with elementCount = " << elementCount << endl;
    cout << "{ ";
    if (elementCount != 0) printInOrderR(root);
    cout << "}";

    return;
  }

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void BST::printInOrderR(BSTNode *current) const {
    if (current != nullptr) {
      printInOrderR(current->left);
      cout << current->element << " ";
      printInOrderR(current->right);
    }
    return;
  }
  

  // Description: Returns the number of nodes in this binary search tree.
  //              You cannot return "elementCount".
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.		
  unsigned int BST::numberOfNodes( ) const {
    return numberOfNodesR(root);
  }

  // Description: Recursive helper method for numberOfNodes( ).
  unsigned int BST::numberOfNodesR(BSTNode *current) const
  {
    if (current == nullptr) return 0;
    return 1 + numberOfNodesR(current->left) + numberOfNodesR(current->right);
  }

  // Description: Returns the height of this binary search tree.
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int BST::height() const {
    return heightR(root);
  }

  // Description: Recursive helper method for height()
  unsigned int BST::heightR(BSTNode *current) const
  {
    if (current == nullptr) return 0;
    return 1 + std::max(heightR(current->left), heightR(current->right));
  }

  // Description: Returns the sum of all elements in the binary search tree.
  //              Fell free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int BST::sumOfAllNodes() const {
    return sumOfAllNodesR(root);
  }

  // Description: Recursive helper method for sumOfAllNodes
  unsigned int BST::sumOfAllNodesR(BSTNode *current) const
  {
    if (!current) return 0;
    return current->element + sumOfAllNodesR(current->left) + sumOfAllNodesR(current->right);   
  }

  // Description: Return the minimum element in the binary search tree.
  int BST::findMin() const
  {
    // if (elementCount == 0) throw EmptyTreeException("In findMin(): tree is empty!");
    BSTNode *current = root;
    while (current->left != nullptr)
    {
      current = current->left;
    }
    return current->element;
  }

  // Description: Return the minimum element in the binary search tree recursively.
  int BST::findMinR(BSTNode *current) const
  {
    if (current->left == nullptr) return current->element;
    return findMinR(current->left);
  }

  // Description: Return the maximum element in the binary search tree.
  int BST::findMax() const
  {
    // if (elementCount == 0) throw EmptyTreeException("In findMax(): tree is empty!");
    BSTNode *current = root;
    while (current->right != nullptr)
    {
      current = current->right;
    }
    return current->element;
  }

  // Description: Return the maximum element in the binary search tree recursively.
  int BST::findMaxR(BSTNode *current) const
  {
    if (current->right == nullptr) return current->element;
    return findMaxR(current->right);
  }

  // Description: Return true or false if an element is in the binary search tree.
  bool BST::contains(int anElement) const {
    return containsR(anElement, root);
  }

  // Description: Recursive helper method for contains( ).
  bool BST::containsR(int anElement, BSTNode *current) const
  {
    if (current == nullptr) return false;
    if (anElement == current->element) return true;
    if (anElement < current->element) return containsR(anElement, current->left);
    return containsR(anElement, current->right);
  }

  // Description: Return the number of leaves in the binary search tree.
  unsigned int BST::numberOfLeaves() const {
    return numberOfLeavesR(root);
  }

  // Description: Recursive helper method for numberOfLeaves( ).
  unsigned int BST::numberOfLeavesR(BSTNode *current) const
  {
    if (current == nullptr) return 0;
    if (current->isLeaf()) return 1;
    return numberOfLeavesR(current->left) + numberOfLeavesR(current->right);
  }

  // Desription: Return the number of nodes at depth k.
  int BST::numberOfNodesAtDepthK(int k) const {
    return numberOfNodesAtDepthKR(k, root);
  }

  // Description: Recursive helper method for numberOfNodesAtDepthK( ).
  int BST::numberOfNodesAtDepthKR(int k, BSTNode *current) const
  {
    if (current == nullptr) return 0;
    if (k == 0) return 1;
    return numberOfNodesAtDepthKR(k - 1, current->left) + numberOfNodesAtDepthKR(k - 1, current->right);
  }

  // Description: Return the number of nodes with two children.
  int BST::numberOfNodesWithTwoChildren() const {
    return numberOfNodesWithTwoChildrenR(root);
  }

  // Description: Recursive helper method for numberOfNodesWithTwoChildren( ).
  int BST::numberOfNodesWithTwoChildrenR(BSTNode *current) const
  {
    if (current == nullptr) return 0;
    if (current->hasLeft() && current->hasRight()) return 1 + numberOfNodesWithTwoChildrenR(current->left) + numberOfNodesWithTwoChildrenR(current->right);
    return numberOfNodesWithTwoChildrenR(current->left) + numberOfNodesWithTwoChildrenR(current->right);
  }

  // Description: Recursively determine if the binary search tree is balanced.
  bool BST::isBalanced() const {
    return isBalancedR(root);
  }

  // Description: Recursive helper method for isBalanced( ).
  bool BST::isBalancedR(BSTNode *current) const
  {
    if (current == nullptr) return true;
    if (fabs(heightR(current->left) - heightR(current->right)) > 1) return false;
    return isBalancedR(current->left) && isBalancedR(current->right);
  }

  // Description: Calculate the depth of an element in the binary search tree.
  // This is the length of path from the root to the node containing the element.
  int BST::depthOf(int anElement) const
  {
    // Assume the element is in the tree.
    BSTNode *current = root;
    int depth = 0;
    while (current->element != anElement)
    {
      if (anElement < current->element) current = current->left;
      else current = current->right;
      depth++;
    }
    return depth;
  }

  // Description: Return the sum of all elements in a range [min, max] inclusive.
  int BST::sumOfRange(int min, int max) const {
    return sumOfRangeR(min, max, root);
  }

  // Description: Recursive helper method for sumOfRange( ).
  int BST::sumOfRangeR(int min, int max, BSTNode *current) const
  {
    if (current == nullptr) return 0;
    if (current->element < min) return sumOfRangeR(min, max, current->right);
    if (current->element > max) return sumOfRangeR(min, max, current->left);
    return current->element + sumOfRangeR(min, max, current->left) + sumOfRangeR(min, max, current->right);
  }

  // Description: Determine if a binary search tree is full
  bool BST::isFull() const {
    return isFullR(root);
  }

  // Description: Recursive helper method for isFull( ).
  bool BST::isFullR(BSTNode *current) const
  {
    if (current == nullptr) return true;
    if (current->isLeaf()) return true;
    if (current->hasLeft() && current->hasRight()) return isFullR(current->left) && isFullR(current->right);
    return false;
  }

  // Description: Determine if a binary search tree is complete
  bool BST::isComplete() const {
    return isCompleteR(root);
  }

  // Description: Recursive helper method for isComplete( ).
  bool BST::isCompleteR(BSTNode *current) const
  {
    if (current == nullptr) return true;
    if (current->isLeaf()) return true;
    if (current->hasLeft() && current->hasRight()) return isCompleteR(current->left) && isCompleteR(current->right);
    if (current->hasLeft() && !current->hasRight()) return isCompleteR(current->left);
    return false;
  }