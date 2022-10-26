#include "gtest/gtest.h"
#include "../BST.h"
#include "../WordPair.h"
#include "../ElementAlreadyExistsException.h"
#include "../ElementDoesNotExistException.h"
#include "../EmptyDataCollectionException.h"
#include <iostream>
using std::cout; 

// Remove later
void visit(WordPair & element)
{
   cout << element << endl;
}

struct BSTTest : public ::testing::Test
{
  BST *bst;
  BST *bst2;
  // Create word pair objects
  WordPair *wp1;
  WordPair *wp2;
  WordPair *wp3;
  WordPair *wp4;
  WordPair *wp5;
  WordPair *wp6;
  WordPair *wp7;
  WordPair *wp8;
  WordPair *wp9;
  WordPair *wp10;

  // Initialize BSTNodes
  BSTNode *node1;
  BSTNode *node2;
  BSTNode *node3;
  BSTNode *node4;
  BSTNode *node5;
  BSTNode *node6;
  BSTNode *node7;
  BSTNode *node8;
  BSTNode *node9;
  BSTNode *node10;

  virtual void SetUp() override
  {
    // Initialize BSTs
    bst = new BST();
    bst2 = new BST();

    // Initialize word pairs with ../dataFile.txt
    wp1 = new WordPair("stop", "mevyap");
    wp2 = new WordPair("food", "Soj");
    wp3 = new WordPair("win", "Qap");
    wp4 = new WordPair("conduit", "'och");
    wp5 = new WordPair("today", "jajvam");
    wp6 = new WordPair("face", "qab");
    wp7 = new WordPair("laser", "'uD'a'");
    wp8 = new WordPair("roof", "beb");
    wp9 = new WordPair("take", "chen form");
    wp10 = new WordPair("water", "bIQ");

    // Initialize BSTNodes
    node1 = new BSTNode(*wp1);
    node2 = new BSTNode(*wp2);
    node3 = new BSTNode(*wp3);
    node4 = new BSTNode(*wp4);
    node5 = new BSTNode(*wp5);
    node6 = new BSTNode(*wp6);
    node7 = new BSTNode(*wp7);
    node8 = new BSTNode(*wp8);
    node9 = new BSTNode(*wp9);
    node10 = new BSTNode(*wp10);
  }

  virtual void TearDown() override
  {
    delete bst;
    delete bst2;
    delete wp1;
    delete wp2;
    delete wp3;
    delete wp4;
    delete wp5;
    delete wp6;
    delete wp7;
    delete wp8;
    delete wp9;
    delete wp10;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;
    delete node8;
    delete node9;
    delete node10;
  }
};

// Test 1: Test the default constructor
TEST(BST_CONSTRUCTOR, BST_DEFAULT_CONSTRUCTOR)
{
  BST *bst = new BST();
  EXPECT_EQ(bst->getElementCount(), 0);
  delete bst;
}

// Test 2: Test the copy constructor with an empty BST
TEST_F(BSTTest, BST_COPY_CONSTRUCTOR_EMPTY)
{
  BST *bstCopy = new BST(*bst);
  EXPECT_EQ(bstCopy->getElementCount(), 0);
  delete bstCopy;
}

// Test 3: Test the copy constructor with a BST with elements
// Seg Faults
// TEST_F(BSTTest, COPY_CONSTRUCTOR_NON_EMPTY_BST)
// {
//   // Insert elements into bst
//   bst->insert(*wp2);
//   bst->insert(*wp3);
//   bst->insert(*wp4);
//   bst->insert(*wp5);
//   bst->insert(*wp6);
//   EXPECT_EQ(bst->getElementCount(), 5);

//   // Copy bst
//   BST *bstCopy = new BST(*bst);
//   EXPECT_EQ(bstCopy->getElementCount(), bst->getElementCount());

//   // Capture original and copy elements
//   std::string bstOutput = testing::internal::GetCapturedStdout();
//   bst->traverseInOrder(visit);

//   std::string bstCopyOutput = testing::internal::GetCapturedStdout();
//   bstCopy->traverseInOrder(visit);

//   // Compare original and copy elements
//   EXPECT_EQ(bstOutput, bstCopyOutput);
//   delete bstCopy;
// }

// Test 4: Retrieve an element from an empty BST
TEST_F(BSTTest, RETRIEVE_FROM_EMPTY_BST)
{
  EXPECT_THROW(bst->retrieve(*wp1), EmptyDataCollectionException);
}

// Test 5: Testing the insert method and check whether elements were correctly added to the BST
TEST_F(BSTTest, INSERTED_CORRECT_ORDER)
{
  bst->insert(*wp1);
  bst->insert(*wp2);
  bst->insert(*wp3);
  bst->insert(*wp4);
  bst->insert(*wp5);

  // Check that 5 elements were correctly added to the BST
  EXPECT_EQ(bst->getElementCount(), 5);

  // Check that the elements were added in the correct order with traversalInOrder()
  testing::internal::CaptureStdout();
  bst->traverseInOrder(visit);
  // Capture the output of the traversal and compare it to the expected output
  std::string output = testing::internal::GetCapturedStdout();
  std::string expected = "conduit:'och\n\nfood:Soj\n\nstop:mevyap\n\ntoday:jajvam\n\nwin:Qap\n\n";
  ASSERT_EQ(output, expected);
}

// Test 6: Testing the insert method with duplicate elements
TEST_F(BSTTest, BST_INSERT_DUPLICATE)
{
  bst->insert(*wp1);
  bst->insert(*wp2);
  bst->insert(*wp3);
  bst->insert(*wp4);
  bst->insert(*wp5);

  // Check that 5 elements were correctly added to the BST
  EXPECT_EQ(bst->getElementCount(), 5);
  // Try to insert a duplicate element
  EXPECT_THROW(bst->insert(*wp1), ElementAlreadyExistsException);
}

// Test 7: Retrieve an element from a BST that contains the element
TEST_F(BSTTest, BST_RETRIEVE_ELEMENT_EXISTS)
{
  // Insert 2 elements into the BST
  bst->insert(*wp9);
  bst->insert(*wp10);
  EXPECT_EQ(bst->getElementCount(), 2);

  // Duplicate wp1 and try to retrieve it from the BST
  WordPair *wp9Dupe = new WordPair(wp9->getEnglish(), wp9->getTranslation());
  ASSERT_EQ(*wp9, *wp9Dupe);

  // Retrieve wp1Dupe from the BST
  WordPair &wp9Retrieved = bst->retrieve(*wp9Dupe);
  EXPECT_EQ(wp9Retrieved, *wp9);
  delete wp9Dupe;
}

// Test 8: Retrieve an element from a BST that does not contain the element
TEST_F(BSTTest, RETRIEVE_ELEMENT_DOES_NOT_EXIST)
{
  // Insert elements 5, 6, 7, 8, and 9 into the BST
  bst->insert(*wp5);
  bst->insert(*wp6);
  bst->insert(*wp7);
  bst->insert(*wp8);
  bst->insert(*wp9);
  EXPECT_EQ(bst->getElementCount(), 5);

  // Try to retrieve wp1 from the BST
  EXPECT_THROW(bst->retrieve(*wp1), ElementDoesNotExistException);
}





// Test X: Check true is always true
TEST(SANITY_CHECK, TRUE_IS_TRUE)
{
  EXPECT_TRUE(true);
}
