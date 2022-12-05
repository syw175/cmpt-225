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
    
    // Insert 10 elements into the BST to create a balanced tree
    bst->insert(50);
    bst->insert(25);
    bst->insert(75);
    bst->insert(12);
    bst->insert(37);
    bst->insert(62);
    bst->insert(87);
    bst->insert(6);
    bst->insert(18);
    bst->insert(31);
    assert(bst->getElementCount() == 10);

    // Insert my test cases here....
    // --------------------------------------------------------------------------------------------







    // --------------------------------------------------------------------------------------------
    // Delete the BST object
    delete bst;
    bst = nullptr;

    return 0;
}