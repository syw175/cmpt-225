/*
 * BSTTestDriver.cpp
 * 
 * Description: Simple test driver for BST class.
 *              Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Date of last modification: Decemeber 2022
 */

#include "BST.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char* argv[])
{
    // Instiate a BST object
    BST *bst = new BST();

/*
    // This BST should look like this:
    //
    //          50
    //         /  \
    //        25  75
    //       / \  / \
    //      12 37 62 87
    //     / \   /
    //    6  18 31
    //
*/

    // Check base conditions
    assert(bst->getElementCount() == 0);
    assert(bst->sum() == 0);
    assert(bst->numberOfLevels() == 0);
    // Insert 10 elements into the BST to create a balanced tree
    bst->insert(50);
    assert(bst->getElementCount() == 1);
    assert(bst->sum() == 50);
    assert(bst->numberOfLevels() == 1);

    // Check with two elements
    bst->insert(25);
    assert(bst->getElementCount() == 2);
    assert(bst->sum() == 75);
    assert(bst->numberOfLevels() == 2);
    
    // Check with three elements
    bst->insert(75);
    assert(bst->getElementCount() == 3);
    assert(bst->sum() == 150);
    assert(bst->numberOfLevels() == 2);
    
    bst->insert(12);
    bst->insert(37);
    bst->insert(62);
    bst->insert(87);
    assert(bst->getElementCount() == 7);
    assert(bst->sum() == 348);
    assert(bst->numberOfLevels() == 3);

    bst->insert(6);
    bst->insert(18);
    bst->insert(31);
    assert(bst->getElementCount() == 10);
    assert(bst->sum() == 403);
    assert(bst->numberOfLevels() == 4);

    // Insert my test cases here....
    // --------------------------------------------------------------------------------------------

    cout << "Result of sum(): " << bst->sum() << endl;
    cout << "Result of numberOfLevels(): " << bst->numberOfLevels() << endl;







    // --------------------------------------------------------------------------------------------
    // Delete the BST object
    delete bst;
    bst = nullptr;

    return 0;
}