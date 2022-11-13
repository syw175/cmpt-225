// Short testdriver for my binary heap template class implementation
// Author: Steven Wong
// Last Modification: November 2022

#include <cassert>
#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main (int argc, char**argv)
{
    // Instiatiate a binary heap
    BinaryHeap<int> *bh = new BinaryHeap<int>();
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    int g = 7;
    int h = 8;
    int i = 9;
    int j = 10;
    int k = 11;

    int l = 12;
    int m = 13;
    int n = 14;
    int o = 15;
    
    // Test isEmpty()
    assert(bh->getElementCount() == 0);

    // Print out the heap
    cout << "Printing out an empty heap:" << endl;
    cout << "Expected: " << endl;
    cout << "Actual: " << endl;
    bh->print();

    // Try to remove from an empty heap
    try
    {
        bh->remove();
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Successfully caught exception: " << e.what() << endl;
    }

    // Try to retrieve from an empty heap
    try
    {
        bh->retrieve();
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Successfully caught exception: " << e.what() << endl;
    }

    // Insert an element
    bh->insert(e);
    assert(bh->retrieve() == e);
    assert(bh->getElementCount() == 1);
    cout << "Printing out a heap with one element:" << endl;
    cout << "Expected: \n5" << endl;
    cout << "Actual: " << endl;
    bh->print();
    cout << endl;

    // Insert another element
    bh->insert(d);
    assert(bh->retrieve() == d);
    assert(bh->getElementCount() == 2);
    cout << "Printing out a heap with two elements:" << endl;
    cout << "Expected: \n4\n5" << endl;
    cout << "Actual: " << endl;
    bh->print();
    cout << endl;

    // Insert another
    bh->insert(c);
    assert(bh->retrieve() == c);
    assert(bh->getElementCount() == 3);
    cout << "Printing out a heap with three elements:" << endl;
    cout << "Expected: \n3\n5 4" << endl;
    cout << "Actual: " << endl;
    bh->print();
    cout << endl;

    // Insert another
    bh->insert(b);
    assert(bh->retrieve() == b);
    assert(bh->getElementCount() == 4);
    cout << "Printing out a heap with four elements:" << endl;
    cout << "Expected: \n2\n5 4 3" << endl;
    cout << "Actual: " << endl;
    bh->print();
    cout << endl;

    // Make a copy of the heap
    BinaryHeap<int> *bh2 = new BinaryHeap<int>(*bh);
    assert(bh2->getElementCount() == 4);
    cout << "Printing out a copy of the heap:" << endl;
    cout << "Expected: \n2\n5 4 3" << endl;
    cout << "Actual: " << endl;
    bh2->print();
    cout << endl;

    // Remove elements from bh1
    bh->remove();
    assert(bh->retrieve() == c);
    assert(bh->getElementCount() == 3);
    cout << "Printing out a heap with three elements after removing one:" << endl;
    cout << "Expected: \n3\n5 4" << endl;
    cout << "Actual: " << endl;
    bh->print();
    cout << endl;

    // Remove til one left
    bh->remove();
    bh->remove();
    
    assert(bh->retrieve() == e);
    assert(bh->getElementCount() == 1);
    cout << "Printing out a heap with one element after removing three:" << endl;
    cout << "Expected: \n5" << endl;
    cout << "Actual: "  << endl;
    bh->print();
    cout << endl;

    // Remove last element
    bh->remove();
    assert(bh->getElementCount() == 0);
    cout << "Printing out an empty heap after removing the last element:" << endl;
    cout << "Expected: " << endl;
    cout << "Actual: " << endl;
    bh->print();
    cout << endl;

    // Test whether the copy is still intact
    assert(bh2->getElementCount() == 4);
    assert(bh2->retrieve() == b);
    cout << "Printing out a copy of the heap after removing elements from the original:" << endl;
    cout << "Expected: \n2\n5 4 3" << endl;
    cout << "Actual: " << endl;
    bh2->print();
    cout << endl;

    // Add all of the elements to back to bh for print testing
    assert(bh->getElementCount() == 0);
    bh->insert(a);
    assert(bh->getElementCount() == 1);
    bh->insert(b);
    assert(bh->getElementCount() == 2);
    bh->insert(c);
    assert(bh->getElementCount() == 3);
    bh->insert(d);
    assert(bh->getElementCount() == 4);
    bh->insert(e);
    assert(bh->getElementCount() == 5);
    bh->insert(f);
    assert(bh->getElementCount() == 6);

    bh->insert(l);
    assert(bh->getElementCount() == 7);
    bh->insert(m);
    assert(bh->getElementCount() == 8);
    bh->insert(n);
    assert(bh->getElementCount() == 9);
    bh->insert(o);
    assert(bh->getElementCount() == 10);

    bh->insert(g);
    assert(bh->getElementCount() == 11);
    bh->insert(h);
    assert(bh->getElementCount() == 12);
    bh->insert(i);
    assert(bh->getElementCount() == 13);
    bh->insert(j);
    assert(bh->getElementCount() == 14);
    bh->insert(k);
    assert(bh->getElementCount() == 15);
    cout << "Printing out a heap with 15 elements:" << endl;
    cout << "Expected: \n1\n2 3 4 5 6 15 14 13 12 11 10 7 8 9" << endl;
    cout << "Actual: " << endl;
    bh->print();

    // Delete the heaps
    delete bh;
    delete bh2;
    return 0;
}