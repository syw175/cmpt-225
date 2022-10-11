/* 
 * StackTestDriver.cpp
 *
 * Description: Test Driver for Stack class.
 *
 * Author: Steven Wong
 * Date: October 2022
 *
 */

#include <cassert>
#include <iostream> 
#include "Stack.h"

using std::cout;
using std::endl;


int main () {
    Stack * stk = new Stack();

    // Test isEmpty() on an empty stack
    assert(stk->isEmpty() == true);
    assert(stk->size() == 0);

    // Try to print an empty stack
    cout << "Testing print on an empty stack: " << endl;
    cout << "Expected: EMPTY" << endl;
    cout << "Actual: ";
    cout << *stk;

    // Try to pop an empty stack
    assert(stk->pop() == false);
    assert(stk->size() == 0);

    // Test push()
    assert(stk->push(1) == true);
    assert(stk->push(2) == true);
    assert(stk->push(3) == true);
    assert(stk->push(4) == true);
    assert(stk->push(5) == true); 

    // Try to print an stack with elements
    cout << "Testing print on a stack with elements: " << endl;
    cout << "Expected: 5 4 3 2 1" << endl;
    cout << "Actual: ";
    cout << *stk << endl;

    // Test isEmpty() on a non-empty stack and size()
    assert(stk->isEmpty() == false);
    assert(stk->size() == 5);
    assert(stk->peek() == 5);

    // Test pop()
    assert(stk->pop() == true);
    assert(stk->peek() == 4);

    // Test pop() to insure Stack is correctly emptied
    assert(stk->pop() == true);
    assert(stk->peek() == 3);

    // Print out the stack and check the output
    cout << "Testing print after popping: " << endl;
    cout << "Expected: 3 2 1" << endl;
    cout << "Actual: ";
    cout << *stk << endl;
    
    assert(stk->pop() == true);
    assert(stk->peek() == 2);

    // Test pop() on a stack with one element
    assert(stk->pop() == true);
    assert(stk->peek() == 1);

    // Test pop() on a stack with no elements
    assert(stk->pop() == true);
    assert(stk->isEmpty() == true);

    // Test pop() on an empty stack
    assert(stk->pop() == false);

    delete stk;
    stk = nullptr;

    // End of test driver
    return 0;
}