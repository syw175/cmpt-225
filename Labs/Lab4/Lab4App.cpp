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
 
  aQueue->printQueue();
  
  cout << "Test Driver - End" << endl << endl;
  
  delete aQueue;
  aQueue = nullptr;
  
  return 0;
}
