/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: AL
 * Last modified: Sept. 2022
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;

// Function prototypes
void add(List &members);
void remove(List *members);
void search(List *members);
void modify(List *members);
void print(List *members);

int main() {

    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
		switch(input) {
            case 'a': add(*Members); break;
            case 'r': remove(Members); break;
            case 's': search(Members); break;
            case 'm': modify(Members); break;
            case 'p': print(Members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}

// TODO: Implement methods
void add(List &members)
{
    // Initialize variables
    string name, phone, email, creditCard;

    // Prompt user
    cout << "You have chosen to add a new member" << endl; 
    cout << "Enter the full name of the new member: "; 
    cin >> name; 

    cout << "Enter the phone number of the new member in the format 'XXX-XXX-XXXX': ";
    cin >> phone; 

    cout << "Enter the email of the new member: ";
    cin >> email;

    cout << "Enter the credit card number of the new member: ";
    cin >> creditCard; 

    // Create a new member with the given information
    Member *newMember = new Member(name, phone, email, creditCard);

    if (!members.insert(*newMember))
    {
        cout << "Adding new member failed!" << endl;
        delete newMember;
    }
    else 
    {
        cout << "Success!" << endl;
    }
}


// Remove a member from the list
void remove(List &members)
{
    // Ask user for member's phone number
  

    // Search for the member in the list

}

void search(List *members)
{

}
void modify(List *members)
{

}
// Print all members in the list
void print(List *members)
{
    cout << "Now printing the list containing " << members->getElementCount() << " elements" << endl;
    members->printList();
}