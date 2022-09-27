/*
 * ListTestDriver.cpp
 * 
 * Description: Test the methods of the List collection ADT. 
 *
 * Author: Steven Wong
 * 
 * Last modified: Sept. 2022
 */

#include <cassert>
#include <iostream>

#include "List.h"
#include "Member.h"

using namespace std;

int main(void)
{
    // Create random new members objects
    Member* member1 = new Member("Steven", "123-456-7890", "1234 123 Street", "4516 1234 1234 1234");
    Member* member2 = new Member("John", "123-456-3320", "1234 Steve Street", "4516 1234 1234 1234");
    Member* member3 = new Member("Jane", "123-456-1111", "1234 Steve Street", "4516 1234 1234 1234");
    Member* member4 = new Member();
    Member* member5 = new Member("778-709-3575");
    Member* member6 = new Member("778-709-5183");
    Member* member7 = new Member("778-709-1111");

    // Create a List object
    List* list = new List();

    // Check that the new list was successfully created
    assert(list != NULL);

    // Check that the initial element count is 0
    assert(list->getElementCount() == 0);

    // Try to remove an element from an empty list
    assert(list->remove(*member1) == false);

    // Try to search for an element in an empty list
    assert(list->search(*member1) == NULL);

    // Print an empty list [should print nothing]    
    list->printList();

    // Insert a new element into the list
    assert(list->insert(*member1) == true);

    // Check that the element count is now 1
    assert(list->getElementCount() == 1);

    // Try to insert a duplicate element into the list
    assert(list->insert(*member1) == false);

    // Check that the element count is still 1
    assert(list->getElementCount() == 1);

    // Insert a new element into the list
    assert(list->insert(*member2) == true);

    // Check that the element count is now 2
    assert(list->getElementCount() == 2);

    // Insert a new element into the list
    assert(list->insert(*member3) == true);

    // Check that the element count is now 3
    assert(list->getElementCount() == 3);

    // Print the list [should print 3 elements]
    list->printList();

    // Try to remove an element that is not in the list
    assert(list->remove(*member4) == false);

    // Check that the element count is still 3
    assert(list->getElementCount() == 3);

    // Try to remove an element that is in the list
    assert(list->remove(*member2) == true);

    // Check that the element count is now 2
    assert(list->getElementCount() == 2);

    // Print the list [should print 2 elements]
    list->printList();

    // Fill the list to capacity
    assert(list->insert(*member4) == true);
    assert(list->insert(*member5) == true);
    assert(list->insert(*member6) == true);
  
    // Check that the element count is now 5
    assert(list->getElementCount() == 5);

    // Try to insert an element into a full list
    assert(list->insert(*member7) == false);

    // Check that the element count is still 5
    assert(list->getElementCount() == 5);

    // Print the list [should print 5 elements]
    list->printList();
    



    return 0;
}