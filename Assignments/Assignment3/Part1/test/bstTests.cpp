#include "gtest/gtest.h"
#include "../BST.h"
#include "../WordPair.h"
#include "../ElementAlreadyExistsException.h"
#include "../ElementDoesNotExistException.h"
#include "../EmptyDataCollectionException.h"

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

// Test 3: Check true is always true
TEST(PLACEHOLDER_TEST, TRUE_IS_TRUE)
{
  EXPECT_TRUE(true);
}