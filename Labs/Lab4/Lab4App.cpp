/*
 * test.cpp - Lab 4
 * 
 * Class Description: Test Driver for our Lab 4
 *
 * Modified on: Oct. 2022
 * Author: AL
 */

#include <iostream>
#include <sstream>
#include "Queue.h"
#include "Member.h"


#include "EmptyDataCollectionException.h"

using namespace std;


int main () { 

  // Create an empty Queue
  Queue* aQueue = new Queue();
  string aLine = "";
  string name = "";
  string firstName = "";
  string lastName = "";
  string phone = "";  
  string email = "";
  string creditCard = "";
  string creditCard1 = "";
  string creditCard2 = "";
  string creditCard3 = "";
  string creditCard4 = "";

  cout << "\nTest Driver - Start" << endl << endl;
    
  // Trying to peek before enqueuing
  // Member peekedMember;
  // cout << "Peeking before enqueuing:" << endl;
  // peekedMember = aQueue->peek();
  // cout << "Now, let's have a look at the peeked Member:" << endl;  
  // cout << peekedMember << endl;

  // Trying to peek before enqueing and catching it
  Member peekedMember;
  try
  {
    cout << "Peeking before enqueuing:" << endl;
    peekedMember = aQueue->peek();
    cout << "Now, let's have a look at the peeked Member:" << endl;  
    cout << peekedMember << endl;
  }
  catch ( EmptyDataCollectionException& anException ) 
  {
    cout << "peek() unsuccessful because " << anException.what() << endl;
    // Place recovery code here!
  }

  while(getline(cin >> ws, aLine)) {   // while (there is data)
      stringstream ss(aLine);
      ss >> firstName >> lastName >> phone >> email >> creditCard1 >> creditCard2 >> creditCard3 >> creditCard4;
      name = firstName + " " + lastName; 
      creditCard = creditCard1 + " " + creditCard2 + " " + creditCard3 + " " + creditCard4;     
      cout << "Read: " << name << ", " << phone << ", " <<  email << ", " <<  creditCard << endl;  
      Member newMember(name, phone, email, creditCard);
      if ( !aQueue->enqueue(newMember) )  return 1;
      cout << newMember << endl;
  }
 
  cout << *aQueue << endl;

  try 
  {
    cout << "Peeking after enqueuing:" << endl;
    peekedMember = aQueue->peek();
    cout << "Now, let's have a look at the peeked Member:" << endl;  
    cout << peekedMember << endl;
  }
  catch (EmptyDataCollectionException&anException )
  {
    cout << "peek() unsuccessful because " << anException.what() << endl;
    // Place recovery code here!
  }
  cout << "Test Driver - End" << endl << endl;
  
  delete aQueue;
  aQueue = nullptr;
  
  return 0;
}
