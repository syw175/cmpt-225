/*
 * ListTestDriver.cpp
 *
 * Class Description: Verifies the functionality of the List ADT class.
 * 
 * Author: Steven Wong
 * Date: Last modified: Dec 2022
 */

#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "Member.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using namespace std;

// Function prototypes
unsigned int hashSimpleModulo(string phone);

int main(void)
{
    // Note: Capacity of List is 103
    // Create some members to test our List ADT
    Member *member1 = new Member("777-777-7777");
    Member *member2 = new Member("888-888-8888");
    Member *member3 = new Member("999-999-9999");
    Member *member4 = new Member();
    Member *member5 = new Member("Steven", "111-111-1111", "wonderlad@gmail.com", "1234567890123456");
    Member *member6 = new Member("Fred Zhang", "604-354-4759", "iamFredzhang@gmail.com", "1234567890123456");

    // Few members that result in the same hash value (modulo 103) as member1 with different phone numbers



    // Instantiate a List object with hashSimpleModulo as the hashing function
    List *test = new List(hashSimpleModulo);

    // Methods to be tested: Destructor, getElementCount, insert, search, and printList
    cout << "Testing destructor, getElementCount, insert, search, and printList..." << endl;
    cout << "---------------------------------------------------------------" << endl;

    // Test getElementCount on an empty list
    cout << "getElementCount on an empty list: " << test->getElementCount() << endl;
    assert(test->getElementCount() == 0);

    // Test search on an empty list
    try
    {
        test->search(*member1);
    }
    catch (EmptyDataCollectionException &e)
    {
        cout << "Caught EmptyDataCollectionException: " << e.what() << endl;
    }

    cout << "---------------------------------------------------------------" << endl;

    // Test insert on an empty list
    cout << "Inserting member1 into the list..." << endl;
    test->insert(*member1);
    cout << "getElementCount on a list with 1 element: " << test->getElementCount() << endl;
    assert(test->getElementCount() == 1);

    // Try to insert member1 again
    try
    {
        cout << "Inserting member1 into the list again..." << endl;
        test->insert(*member1);
    }
    catch (ElementAlreadyExistsException &e)
    {
        cout << "Caught ElementAlreadyExistsException: " << e.what() << endl;
    }

    // Test printList on a list with 1 element
    cout << "Printing the list..." << endl;
    test->printList();
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;

    // Test search on a list with 1 element
    cout << "Searching for member1 in the list..." << endl;
    Member *found = test->search(*member1);
    cout << "Found member1: " << found->getName() << endl;
    assert(found->getName() == member1->getName());

    // Test search on a list with 1 element (not found)
    try
    {
        cout << "Searching for member2 in the list..." << endl;
        test->search(*member2);
    }
    catch (ElementDoesNotExistException &e)
    {
        cout << "Caught ElementDoesNotExistException: " << e.what() << endl;
    }
    cout << "---------------------------------------------------------------" << endl;

    // Insert a bunch of elements
    cout << "Inserting member2 into the list..." << endl;
    test->insert(*member2);
    cout << "Inserting member3 into the list..." << endl;
    test->insert(*member3);

    // Test getElementCount on a list with 3 elements
    cout << "getElementCount on a list with 3 elements: " << test->getElementCount() << endl;
    assert(test->getElementCount() == 3);
    cout << "---------------------------------------------------------------" << endl;

    // Test printList on a list with 3 elements
    cout << "Printing the list..." << endl;
    test->printList();
    cout << endl;

    cout << "Inserting member4 into the list..." << endl;
    test->insert(*member4);
    cout << "Inserting member5 into the list..." << endl;
    test->insert(*member5);
    cout << "Inserting member6 into the list..." << endl;
    test->insert(*member6);

    // Test getElementCount on a list with 6 elements
    cout << "getElementCount on a list with 6 elements: " << test->getElementCount() << endl;
    assert(test->getElementCount() == 6);
    cout << "---------------------------------------------------------------" << endl;

    // Test printList on a list with 6 elements
    cout << "Printing the list..." << endl;
    test->printList();
    cout << endl;

    // Clear memory
    delete test;
}

// Simple modulo hashing function
unsigned int hashSimpleModulo(string phone)
{
    unsigned int firstThree = stoul(phone.substr(0, 3));
    unsigned int secondThree = stoul(phone.substr(4, 3));
    unsigned int lastFour = stoul(phone.substr(8, 4));
    return (firstThree + secondThree + lastFour) % List::CAPACITY;
}