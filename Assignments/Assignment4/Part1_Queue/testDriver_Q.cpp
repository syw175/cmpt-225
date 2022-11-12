// Used to test the Queue class
// Some basic tests for << operator
// Author: SW
// Date Last modified: November 2022

#include <iostream>
#include <cassert>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Queue.h"
#include "Event.h"

using namespace std;

int main(void)
{
    // Create a Queue of numbers
    Queue<int> q1;
    // Create a Queue of strings
    Queue<string> *q2 = new Queue<string>();

    // Test isEmpty() on empty Queue
    assert(q1.isEmpty() == true);
    assert(q2->isEmpty() == true);

    // Print out the Queue
    cout << "Printing out empty Queue: " << endl;
    cout << "Expected: {}" << endl;
    cout << "Actual: "; 
    q1.print();

    // Test enqueue() on empty Queue
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    int num4 = 4;
    int num5 = 5;
    q1.enqueue(num1);

    // Check that the Queue is not empty and that the element is correct
    assert(q1.isEmpty() == false);
    assert(q1.peek() == 1);

    q1.enqueue(num2);
    q1.enqueue(num3);
    q1.enqueue(num4);
    q1.enqueue(num5);

    // Print out the Queue
    cout << "Printing out Queue: " << endl;
    cout << "Expected: {1, 2, 3, 4, 5}" << endl;
    cout << "Actual: ";
    q1.print();

    // Check that the Queue is not empty and that the element is correct
    assert(q1.isEmpty() == false);
    assert(q1.peek() == 1);

    // Dequeue the Queue and check that the element is correct
    q1.dequeue();
    assert(q1.peek() == 2);

    // Dequeue the Queue and check that the element is correct
    q1.dequeue();
    assert(q1.peek() == 3);

    // Print out the Queue
    cout << "Printing out Queue: " << endl;
    cout << "Expected: {3, 4, 5}" << endl;
    cout << "Actual: ";
    q1.print();

    // Dequeue all the elements in the Queue and check that the Queue is empty
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    assert(q1.isEmpty() == true);

    // Test dequeue() on empty Queue
    try
    {
        q1.dequeue();
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Caught exception successfully: " << e.what() << endl;
    }

    // Try to peek() on empty Queue
    try
    {
        q1.peek();
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Caught exception successfully: " << e.what() << endl;
    }

    // Add elements to the Queue
    string str1 = "one";
    string str2 = "two";
    string str3 = "three";
    string str4 = "four";
    string str5 = "five";

    assert(q2->isEmpty() == true);

    // Try to peek() on empty Queue
    try
    {
        q2->peek();
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Caught exception successfully: " << e.what() << endl;
    }

    q2->enqueue(str1);
    q2->enqueue(str2);
    q2->enqueue(str3);

    // Print out the Queue
    cout << "Printing out Queue: " << endl;
    cout << "Expected: {one, two, three}" << endl;
    cout << "Actual: ";
    q2->print();

    // Check that the Queue is not empty and that the element is correct
    assert(q2->isEmpty() == false);
    assert(q2->peek() == "one");

    // Dequeue the Queue and check that the element is correct
    q2->dequeue();
    assert(q2->peek() == "two");

    // Delete the Queue
    delete q2;
    return 0;
}