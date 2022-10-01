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

    // Try to removeAll elements from an empty list
    list->removeAll();

    // Check that the initial element count is 0 and the array is now NULL after removeAll()
    assert(list->getElementCount() == 0);

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
    cout << "Printing the list with 3 elements" << endl;
    list->printList();
    cout << endl;

    // Try to remove an element that is not in the list
    assert(list->remove(*member4) == false);

    // Check that the element count is still 3
    assert(list->getElementCount() == 3);

    // Try to remove an element that is in the list
    assert(list->remove(*member2) == true);

    // Check that the element count is now 2
    assert(list->getElementCount() == 2);

    // Print the list [should print 2 elements]
    cout << "Printing the list with 2 elements" << endl;
    list->printList();
    cout << endl;

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
    cout << "Printing the list with 5 elements" << endl;
    list->printList();
    cout << endl;

    // Remove an element from a full list
    assert(list->remove(*member5) == true);

    // Check that the element count is now 4
    assert(list->getElementCount() == 4);

    // Print the list [should print 4 elements]
    cout << "Printing the list with 4 elements" << endl;
    list->printList();
    cout << endl;

    // Remove all elements from the list
    list->removeAll();

    // Check that the element count is now 0
    assert(list->getElementCount() == 0);

    // Print the list [should print nothing]
    cout << "Printing the list with 0 elements" << endl;
    list->printList();

    // Delete the list and members
    delete list;
    delete member1;
    delete member2;
    delete member3;
    delete member4;
    delete member5;
    delete member6;
    delete member7;

    return 0;
}


// // Google Test Framework
// #include "gtest/gtest.h"

// // List ADT
// #include "List.h"
// #include "Member.h"

// // Test fixture
// class ListTest : public ::testing::Test {
// protected:
//     ListTest() : list() {}
//     virtual ~ListTest() {}
//     virtual void SetUp() {}
//     virtual void TearDown() {}
//     List list;
// };

// // Test the default constructor
// TEST_F(ListTest, DefaultConstructor) {
//     EXPECT_EQ(0, list.getElementCount());
//     EXPECT_EQ(NULL, list.elements);    
// }

// // Test the insert method
// TEST_F(ListTest, Insert) {
//     Member* member1 = new Member("Steven", "123-456-7890", "1234 123 Street", "4516 1234 1234 1234");
//     Member* member2 = new Member("John", "123-456-3320", "1234 Steve Street", "4516 1234 1234 1234");
//     Member* member3 = new Member("Jane", "123-456-1111", "1234 Steve Street", "4516 1234 1234 1234");
//     Member* member4 = new Member();
//     Member* member5 = new Member("778-709-3575");
//     Member* member6 = new Member("778-709-5183");
//     Member* member7 = new Member("778-709-1111");

//     EXPECT_EQ(true, list.insert(*member1));
//     EXPECT_EQ(true, list.insert(*member2));
//     EXPECT_EQ(true, list.insert(*member3));
//     EXPECT_EQ(true, list.insert(*member4));
//     EXPECT_EQ(true, list.insert(*member5));
//     EXPECT_EQ(false, list.insert(*member6));
//     EXPECT_EQ(5, list.getElementCount());
//     EXPECT_EQ(false, list.insert(*member1));
//     EXPECT_EQ(5, list.getElementCount());
// }

// // Test the remove method
// TEST_F(ListTest, Remove) {
//     Member* member1 = new Member("Steven", "123-456-7890", "1234 123 Street", "4516 1234 1234 1234");
//     Member* member2 = new Member("John", "123-456-3320", "1234 Steve Street", "4516 1234 1234 1234");
//     Member* member3 = new Member("Jane", "123-456-1111", "1234 Steve Street", "4516 1234 1234 1234");
//     Member* member4 = new Member();
//     Member* member5 = new Member("778-709-3575");
//     Member* member6 = new Member("778-709-5183");
//     Member* member7 = new Member("778-709-1111");

//     EXPECT_EQ(true, list.insert(*member1));
//     EXPECT_EQ(true, list.insert(*member2));
//     EXPECT_EQ(true, list.insert(*member3));
//     EXPECT_EQ(true, list.insert(*member4));
//     EXPECT_EQ(true, list.insert(*member5));
//     EXPECT_EQ(false, list.insert(*member6));
//     EXPECT_EQ(5, list.getElementCount());
//     EXPECT_EQ(true, list.remove(*member1));
//     EXPECT_EQ(4, list.getElementCount());
//     EXPECT_EQ(true, list.remove(*member2));
//     EXPECT_EQ(3, list.getElementCount());
//     EXPECT_EQ(true, list.remove(*member3));
//     EXPECT_EQ(2, list.getElementCount());
//     EXPECT_EQ(true, list.remove(*member4));
//     EXPECT_EQ(1, list.getElementCount());
//     EXPECT_EQ(true, list.remove(*member5));
//     EXPECT_EQ(0, list.getElementCount());
//     EXPECT_EQ(false, list.remove(*member6));
//     EXPECT_EQ(0, list.getElementCount());
// }

// // Test the search method
// TEST_F(ListTest, Search) {
//     Member* member1 = new Member("Steven", "123-456-7890", "1234 123 Street", "4516 1234 1234 1234");
//     Member* member2 = new Member("John", "123-456-3320", "1234 Steve Street", "4516 1234 1234 1234");
//     Member* member3 = new Member("Jane", "123-456-1111", "1234 Steve Street", "4516 1234 1234 1234");
//     Member* member4 = new Member();
//     Member* member5 = new Member("778-709-3575");
//     Member* member6 = new Member("778-709-5183");
//     Member* member7 = new Member("778-709-1111");

//     EXPECT_EQ(true, list.insert(*member1));
//     EXPECT_EQ(true, list.insert(*member2));
//     EXPECT_EQ(true, list.insert(*member3));
//     EXPECT_EQ(true, list.insert(*member4));
//     EXPECT_EQ(true, list.insert(*member5));
//     EXPECT_EQ(false, list.insert(*member6));
//     EXPECT_EQ(5, list.getElementCount());
//     EXPECT_EQ(true, list.search(*member1));
//     EXPECT_EQ(true, list.search(*member2));
//     EXPECT_EQ(true, list.search(*member3));
//     EXPECT_EQ(true, list.search(*member4));
//     EXPECT_EQ(true, list.search(*member5));
//     EXPECT_EQ(false, list.search(*member6));
//     EXPECT_EQ(5, list.getElementCount());
// }

// // Test the print method with 1 member
// TEST_F(ListTest, Print1) {
//     Member* member1 = new Member("Steven", "123-456-7890", "1234 123 Street", "4516 1234 1234 1234");
//     EXPECT_EQ(true, list.insert(*member1));
//     EXPECT_EQ(1, list.getElementCount());

//     std::stringstream ss;
//     list.print(ss);
//     EXPECT_EQ("Steven 123-456-7890 1234 123 Street 4516 1234 1234 1234");
// }

// // Test the print method with 2 members
// TEST_F(ListTest, Print2) {
//     Member* member1 = new Member("Steven", "123-456-7890", "1234 123 Street", "4516 1234 1234 1234");
//     Member* member2 = new Member("John", "123-456-3320", "1234 Steve Street", "4516 1234 1234 1234");
//     EXPECT_EQ(true, list.insert(*member1));
//     EXPECT_EQ(true, list.insert(*member2));
//     EXPECT_EQ(2, list.getElementCount());

//     std::stringstream ss;
//     list.print(ss);
//     EXPECT_EQ("Steven 123-456-7890 1234 123 Street 4516 1234 1234 1234");
//     EXPECT_EQ("John 123-456-3320 1234 Steve Street 4516 1234 1234 1234");
// }