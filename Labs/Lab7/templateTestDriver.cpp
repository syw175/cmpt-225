/*
 * templateTestDriver.cpp
 * 
 * Description: Test driver for the List ADT class as we convert it into a template ADT class.
 *
 * Author: AL
 * Date: Last modified: Oct. 2022
 */ 
 
#include <iostream>
#include "UnableToInsertException.h"
#include "EmptyListException.h"
#include "ElementDoesNotExistException.h"
#include "List.h"

using std::cout;
using std::endl;

int main() {

  int anInt = 3;
  List<int> *intList = new List<int>();
  
/* Test Case 1
 * An empty 'int' List has already been instantiated - the default constructor was executed.
 * Confirm this by calling getElementCount() and printing the List.
 */
  cout << "Test Case 1: Creating an empty List of int's." << endl;
  cout << "Expected Result: The List is empty." << endl; 
  cout << "Actual Result: Is the List empty (has 0 elements)? Answer -> elementCount = " << intList->getElementCount() << endl;
  cout << "Actual Result: Is the List empty (has 0 elements)? Answer -> " ;
  intList->printList(); 
  cout << endl << endl;

  
// Test Case 2
// Removing an element from an empty List.
  cout << "Test Case 2: Removing the element " << anInt << "from an empty 'int' List." << endl;
  try
  {
    intList->remove(anInt);
  }
  catch(EmptyListException &e)
  {
    cout << "Caught expected result: ... " << endl;
    cout << "intList->remove(" << anInt << ") unsuccessful because " << e.what() << endl;
    cout << endl << endl;
  }

/* Test Case 3
 * Appending the element 3 to our empty 'int' List.
 * Confirm append(3) was successful by calling getElementCount() which should return 1 
 * and printing the List.
 */
  cout << "Test Case 3: Appending the element " << anInt << " to our empty 'int' List." << endl;
  try {
     intList->append(anInt);     
  }
  catch (UnableToInsertException & anException) {
     cout << "intList->append(" << anInt << ") unsuccessful because " << anException.what() << endl;
  }
  cout << "Expected Result: The List has one element: " << anInt << "." << endl;
  cout << "Actual Result: Does the List contain one element? Answer -> elementCount = " << intList->getElementCount() << endl;
  cout << "Actual Result: Does the List contain the element " << anInt << "? Answer -> " ; 
  intList->printList();
  cout << endl << endl;

  // Test Case 4
  // Removing element 8 from a List that currently has 1 element: 3.
  cout << "Test Case 4: Removing the element " << anInt << "from a 'int' List." << endl;
  try
  {
    int k = 8;
    intList->remove(k);
  }
  catch(ElementDoesNotExistException &e)
  {
    cout << e.what() << endl;
  }
  cout << "Expected Result: The list has still has 1 elements. " << endl;
  cout << "Actual Result: The List contains " << intList->getElementCount() << "elements." << endl;
  cout << "Actual Result: The list now contains the elements: " << endl;
  intList->printList();
  cout << endl << endl;

  // Test Case 5
  // Removing an element a list containing the element
  cout << "Test Case 5: Removing the element " << anInt << "from a 'int' List." << endl;
  try
  {
    intList->remove(anInt);
  }
  catch(EmptyListException &e)
  {
    cout << e.what() << endl;
  }
  cout << "Expected Result: The list has 0 elements. " << endl;
  cout << "Actual Result: The List contains " << intList->getElementCount() << "elements." << endl;
  cout << "Actual Result: The list now contains the elements: " << endl;
  intList->printList();
  cout << endl << endl;


  // Test Case 6
  // Adding elements to the list
  cout << "Test Case 6: Now adding the elements 6, 7, 8, 9, and 11 to the list" << endl;
  int a = 6;
  int b = 7;
  int c = 8;
  int d = 9;
  int e = 11;
  intList->append(a);
  intList->append(b);
  intList->append(c);
  intList->append(d);
  intList->append(e);
  cout << "Expected Result: The list has 5 elements. " << endl;
  cout << "Actual Result: The List contains " << intList->getElementCount() << "elements." << endl;
  cout << "Actual Result: The list now contains the elements: " << endl;
  intList->printList();
  cout << endl << endl;


  // Test Case 7
  // Constructing a new List using an already existing List.
  cout << "Test Case 7: Now making a copy of intList and printing it out, should match test case 6 " << endl;
  List<int> *myCopy = new List<int>(*intList);
  cout << "Expected Result: MyCopy list has 5 elements. " << endl;
  cout << "Actual Result: MyCopy List contains " << intList->getElementCount() << "elements." << endl;
  cout << "Actual Result: MyCopy list now contains the elements: " << endl;
  myCopy->printList();
  cout << endl << endl;


  // Test Case 8
  // Appending element Hello World! to an empty List.
  cout << "Test Case 8: Now appending element Hello World! into an empty List" << endl;
  List<string> *stringList = new List<string>();
  string hello = "Hello World!";
  stringList->append(hello);
  cout << "Expected Result: The list has 1 elements. " << endl;
  cout << "Actual Result: The List contains " << intList->getElementCount() << "elements." << endl;
  cout << "Actual Result: The list now contains the elements: " << endl;
  stringList->printList();
  cout << endl << endl;


  // Test Case 9
  // Appending element Bye Bye! to a List that currently has 1 element: Hello World!
  cout << "Test Case 9: Now appending element Bye Bye! to a List with 1 element: " << endl;
  string bye = "Bye Bye!";
  stringList->append(bye);
  cout << "Expected Result: The list has 2 elements. " << endl;
  cout << "Actual Result: The List contains " << intList->getElementCount() << "elements." << endl;
  cout << "Actual Result: The list now contains the elements: " << endl;
  stringList->printList();
  cout << endl << endl;
  return 0;
}
