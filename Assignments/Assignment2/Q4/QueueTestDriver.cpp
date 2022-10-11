/* 
 * QueueTestDriver.cpp
 *
 * Description: Queue test driver.
 *
 * Author: Steven Wong + YOUR NAME
 * Date: October 2022
 */

#include <iostream>
#include <cassert>
#include "Queue.h"

using std::cout;
using std::endl;


int main()
{
    // Starting test driver
    cout << "Starting test driver..." << endl;
    Queue * Q = new Queue();
    assert(Q->isEmpty());

    // Testing enqueue
    Q->enqueue(1);
    assert(Q->peek() == 1);
    Q->enqueue(2);
    assert(Q->peek() == 1);
    Q->enqueue(3);
    assert(Q->peek() == 1);
    assert(Q->getCapacity() == 6);
    assert(Q->getElementCount() == 3);
    assert(!Q->isEmpty());

    // Testing printQueue
    cout << "Testing printQueue..." << endl;
    cout << "Expected: 1 2 3" << endl;
    cout << "Actual: ";
    cout << *Q << endl;

    // Testing dequeue
    cout << "Testing dequeue..." << endl;
    Q->dequeue();
    assert(Q->peek() == 2);
    Q->dequeue();
    assert(Q->peek() == 3);

    // Testing isEmpty
    cout << "Testing isEmpty..." << endl;
    assert(!Q->isEmpty());
    Q->dequeue();
    assert(Q->isEmpty());

    // Testing printQueue
    cout << "Testing printQueue..." << endl;
    cout << "Expected: " << endl;
    cout << "Actual: ";
    cout << *Q << endl;

    // Adding elements to test resize
    cout << "Testing resize..." << endl;
    for (int i = 0; i < 50; i++)
    {
        Q->enqueue(i);
    }

    assert(Q->peek() == 0);
    assert(Q->getCapacity() == 96);
    assert(Q->getElementCount() == 50);


    // Testing printQueue
    cout << "Testing printQueue..." << endl;
    cout << "Expected: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49" << endl;
    cout << "Actual: ";
    cout << *Q << endl;

    // Check that the queue was resized properly (Halves everytime elementCount is less than 1/4 of capacity)
    cout << "Testing dequeue..." << endl;
    for (int i = 0; i < 35; i++)
    {
        Q->dequeue();
    }

    assert(Q->peek() == 35);
    assert(Q->getCapacity() == 48);
    assert(Q->getElementCount() == 15);

    // Check that queue does not resize to less than 6
    for (int i = 0; i < 14; i++)
    {
        Q->dequeue();
    }

    assert(Q->getCapacity() == 6);
    assert(Q->getElementCount() == 1);

    // Testing isEmpty
    Q->dequeue();
    assert(Q->isEmpty());

    // Deleting queue and ending test driver
    delete Q;
    Q = nullptr;
    assert(Q == nullptr);
    cout << "All tests passed!" << endl;
    return 0;
}

