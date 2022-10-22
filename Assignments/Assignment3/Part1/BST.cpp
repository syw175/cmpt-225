/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Completed by: Steven Wong
 * Date of last modification: Oct. 2022
 */
 
#include "BST.h"
#include "WordPair.h"
   
// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver 
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.


/* Constructors and destructor */

// Default constructor
BST::BST() { }

// Copy constructor
BST::BST(BST &aBST)
{
   root = treeCopy(aBST.root);
   elementCount = aBST.getElementCount();
}

// Destructor 
BST::~BST()
{
   destroyBST(root);
}

/* Getters and setters */

// Description: Returns the number of elements currently stored in the binary search tree.   
// Time efficiency: O(1)   
unsigned int BST::getElementCount() const
{
   return this->elementCount;
}

/* BST Operations */

// Description: Inserts an element into the binary search tree.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the binary search tree.
// Exception: Throws the exception "ElementAlreadyExistsException" 
//            if "newElement" already exists in the binary search tree.
// Time efficiency: O(log2 n)   
void BST::insert(WordPair & newElement)
{
   // Binary search tree is empty, so add the new element as the root
   if (elementCount == 0)
   {
      root = new BSTNode(newElement);
      elementCount++;
   }
   else
   {
      if (!insertR(newElement, root))
      {
         // cout << "BST:insert( )" << *newElement << " already in BST!" << endl; // For testing purposes
         throw ElementAlreadyExistsException("Element already exists in the data collection.");
      }
   }
   return;
}

// Description: Recursive insertion into a binary search tree.
//              Returns true when "anElement" has been successfully inserted into the 
//              binary search tree. Otherwise, returns false.
bool BST::insertR(WordPair & anElement, BSTNode * current)
{
   // to check
   // Cannot have two identical elements in our BST
   if (anElement == current->element)
      return false;

   // If anElement is less than the current node's element, the correct position for anElement is on the left sub-tree
   else if (anElement < current->element)
   {
      // If left is empty, insert anElement and increment elementCount
      if (!current->hasLeft())
      {
         BSTNode *newNode = new BSTNode(anElement);
         current->left = newNode;
         elementCount++;
         return true;
      }
      // Otherwise, traverse to the next left-subtree
      else
         return insertR(anElement, current->left);
   }
   // Otherwise, anElement belongs on the right subtree of the BST
   else
   {
      // If right is empty, insert anElement and increment elementCount
      if (!current->hasRight())
      {
         BSTNode *newNode = new BSTNode(anElement);
         current->right = newNode;
         elementCount++;
         return true;
      }
      // Otherwise, traverse to the next right-subtree
      else
         return insertR(anElement, current->right);
   }
}


// Description: Retrieves "targetElement" from the binary search tree.
//           This is a wrapper method which calls the recursive retrieveR( ).
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException" 
//         if the binary search tree is empty.
// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
//         thrown from the retrieveR(...)
//         if "targetElement" is not in the binary search tree.
// Time efficiency: O(log2 n)
WordPair& BST::retrieve(WordPair & targetElement) const
{
   if (elementCount == 0)  
      throw EmptyDataCollectionException("Binary search tree is empty.");

   WordPair& translated = retrieveR(targetElement, root);
   return translated;
}

// TO CHECK
// Description: Recursive retrieval from a binary search tree.
// Exception: Throws the exception "ElementDoesNotExistException" 
//         if "targetElement" is not found in the binary search tree.
WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const
{
   // If current is nullptr, targetElement is not in the BST
   if (current == nullptr)
      // NOT FOUND
      throw ElementDoesNotExistException("Cannot retrieve, element is not in the tree!");
   // If current is targetElement, return the wordpair
   else if (current->element == targetElement)
   {
      // FOUND
      // CHECK IF THIS WORKS
      WordPair &found = current->element;
      return found;
   }
   // If targetElement is less than current, search the BST's left sub-tree
   else if (targetElement < current->element)
      return retrieveR(targetElement, current->left);
   // If targetElement is greater than current, search the BST's right sub-tree
   else
      return retrieveR(targetElement, current->right);
}

// Description: Traverses the binary search tree in order.
//           This is a wrapper method which calls the recursive traverseInOrderR( ).
//           The action to be done on each element during the traverse is the function "visit".
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException" 
//         if the binary search tree is empty.
// Time efficiency: O(n)     
void BST::traverseInOrder(void visit(WordPair &)) const
{
   if (elementCount == 0)  
      throw EmptyDataCollectionException("Binary search tree is empty.");

   traverseInOrderR(visit, root);
   return;
}

// I pass visit depending on my needs
// Description: Recursive in order traversal of a binary search tree.   
void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const
{ 
   // If current is nullptr, then base case is reached
   if (current == nullptr)
      return;

   // Recursively traverse the BST's left sub-tree
   if (current->hasLeft())
      traverseInOrderR(visit, current->left);

   // Visit the BST's current element
   // Visit() has a ref parameter, we need an lvalue to reference &element
   WordPair &element = current->element;
   visit(element);

   // Recursively traverse through BST's right sub-tree
   if (current->hasRight())
      traverseInOrderR(visit, current->right);
}

// To-Do
// Description: Recursive post-order traversal deep copy method
BSTNode *BST::treeCopy(const BSTNode *node)
{
   return nullptr;
}

// To-Do
// Description: Destroy all BSTNodes in the BST post-order traversal (Both sub-trees have to be deleted first)
void BST::destroyBST(BSTNode *root)
{
   // Base case
   if (root->isLeaf())
      return;
   
   // Traverse the left sub-tree and delete its nodes
   if (root->hasLeft())
      destroyBST(root->left);
   
   // Traverse the right sub-tree and delete its nodes
   if (root->hasRight())
      destroyBST(root->right);
   
   // Delete the node
   delete root;
}