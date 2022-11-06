// Used to test the Queue class
// Some basic tests for << operator
// Author: SW
// Date Last modified: November 2022

#include <iostream>
#include <string>
#include "EmptyDataCollectionException.h"
#include "Queue.h"
// #include "Event.h"
// #include "WordPair.h"

using namespace std;

int main(void)
{
    // Declare some integers
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    // Declare reference variables
    int &aRef = a;
    int &bRef = b;
    int &cRef = c;
    int &dRef = d;
    int &eRef = e;
    int &fRef = f;

    // Declare a Queue of integers
    Queue<int> *q = new Queue<int>();

    cout << "Test 0: Dequeue from empty queue" << endl;
    try
    {
        q->dequeue();
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    cout << "Test 1: Print an empty queue" << endl;
    cout << "Expected: {}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 2: Print a queue with one element" << endl;
    q->enqueue(aRef);
    cout << "Expected: {1}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 3: Print a queue with two elements" << endl;
    q->enqueue(bRef);
    cout << "Expected: {1, 2}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 4: Print a queue with five elements" << endl;
    q->enqueue(cRef);
    q->enqueue(dRef);
    q->enqueue(eRef);
    cout << "Expected: {1, 2, 3, 4, 5}" << endl;
    cout << "Actual: " << *q << endl << endl;

    // Making a copy of the queue
    Queue<int> *qCopy = new Queue<int>(*q);

    cout << "Test 5: Print a copy of the queue" << endl;
    cout << "Expected: {1, 2, 3, 4, 5}" << endl;
    cout << "Actual: " << *qCopy << endl << endl;

    cout << "Test 6: Add an element to the original queue" << endl;
    q->enqueue(fRef);
    cout << "Expected: {1, 2, 3, 4, 5, 6}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 7: Print the copy of the queue" << endl;
    cout << "Expected: {1, 2, 3, 4, 5}" << endl;
    cout << "Actual: " << *qCopy << endl << endl;

    // Test dequeue
    cout << "Test 8: Dequeue from the original queue" << endl;
    q->dequeue();
    cout << "Expected: {2, 3, 4, 5, 6}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "Test 9: Dequeue from the copy of the queue" << endl;
    qCopy->dequeue();
    qCopy->dequeue();
    qCopy->dequeue();
    cout << "Expected: {4, 5}" << endl;
    cout << "Actual: " << *qCopy << endl << endl;

    cout << "Test 10: Print the original queue" << endl;
    cout << "Expected: {2, 3, 4, 5, 6}" << endl;
    cout << "Actual: " << *q << endl << endl;

    cout << "*********************************" << endl << "*********************************" << endl << endl;
    cout << "Testing with strings" << endl;

    // Going with strings now
    string s1 = "one";
    string s2 = "two";
    string s3 = "three";
    string s4 = "four";
    string s5 = "five";

    // Declare a Queue of strings
    Queue<string> *q2 = new Queue<string>();

    cout << "Test 1: Print an empty queue of strings" << endl;
    cout << "Expected: {}" << endl;
    cout << "Actual: " << *q2 << endl << endl;

    cout << "Test 2: Print a queue with one element" << endl;
    q2->enqueue(s1);
    cout << "Expected: {one}" << endl;
    cout << "Actual: " << *q2 << endl << endl;

    cout << "Test 3: Print a queue with five elements" << endl;
    q2->enqueue(s2);
    q2->enqueue(s3);
    q2->enqueue(s4);
    q2->enqueue(s5);

    cout << "Expected: {one, two, three, four, five}" << endl;
    cout << "Actual: " << *q2 << endl << endl;

    // Test with WordPair objects
    // cout << "*********************************" << endl << "*********************************" << endl << endl;
    // cout << "Testing with WordPair objects" << endl;

    // Declare some wordpairs
    // WordPair *wp1 = new WordPair("one", "uno");
    // WordPair *wp2 = new WordPair("two", "dos");
    // WordPair *wp3 = new WordPair("three", "tres");
    // WordPair *wp4 = new WordPair("four", "cuatro");
    // WordPair *wp5 = new WordPair("five", "cinco");

    // Declare a Queue of WordPairs
    // Queue<WordPair> *q3 = new Queue<WordPair>();

    // cout << "Test 1: Print an empty queue of WordPairs" << endl;
    // cout << "Expected: {}" << endl;
    // cout << "Actual: " << *q3 << endl << endl;

    // cout << "Test 2: Print a queue with one element" << endl;
    // q3->enqueue(*wp1);
    // cout << "Expected: {one: uno}" << endl;
    // cout << "Actual: " << *q3 << endl << endl;

    // cout << "Test 3: Print a queue with five elements" << endl;
    // q3->enqueue(*wp2);
    // q3->enqueue(*wp3);
    // q3->enqueue(*wp4);
    // q3->enqueue(*wp5);

    // cout << "Expected: {one: uno, two: dos, three: tres, four: cuatro, five: cinco}" << endl;
    // cout << "Actual: " << *q3 << endl << endl;

    // // Test with Event objects
    // cout << "*********************************" << endl << "*********************************" << endl << endl;
    // cout << "Testing with Event objects" << endl;


    // // Declare some events
    // Event *e1 = new Event('A', 1);
    // Event *e2 = new Event('B', 2);
    // Event *e3 = new Event('C', 3);

    // // Declare a Queue of Events
    // Queue<Event> *q4 = new Queue<Event>();

    // cout << "Test 1: Print an empty queue of Events" << endl;
    // cout << "Expected: {}" << endl;
    // cout << "Actual: " << *q4 << endl << endl;

    // cout << "Test 2: Print a queue with one element" << endl;
    // q4->enqueue(*e1);
    // cout << "Expected: {A1}" << endl;
    // cout << "Actual: " << *q4 << endl << endl;

    // Free memory
    delete q;
    delete qCopy;
    delete q2;
    // delete q3;
    // delete q4;

    return 0;
}