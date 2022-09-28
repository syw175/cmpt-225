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
void add(List *members);
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
            case 'a': add(Members); break;
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
void add(List *members)
{
    // Initialize variables
    string name, phone, email, creditCard;

    // Prompt user for input
    cout << "Enter the name of the new member: ";
    cin >> name;

    cout << "Enter the phone number of the new member: ";
    cin >> phone;

    cout << "Enter the email of the new member: ";
    cin >> email;

    cout << "Enter the credit card number of the new member: ";
    cin >> creditCard;

    // Create new member
    Member *newMember = new Member(name, phone, email, creditCard);

    // Verify that memory was allocated
    if (newMember == NULL)
    {
        cout << "Error: Memory could not be allocated." << endl;
        return;
    }

    // Insert new member into list
    if (members->insert(*newMember))
        cout << "Member successfully added!" << endl;
    else
        cout << "Error: Member could not be added." << endl;
}

// CREATING A NEW MEMBER OBJECT ISSUES WITH DEFAULT PHONE # REMOVING A MEMBER
// Remove a member from the list
void remove(List *members)
{
    string phone; 

    // Prompt user for input
    cout << "Enter the phone number of the member to remove: ";
    cin >> phone;

    // Create new member
    Member *newMember = new Member(phone);

    // Verify that memory was allocated
    if (newMember == NULL)
    {
        cout << "Error: Memory could not be allocated." << endl;
        return;
    }

    // Remove member from list
    if (members->remove(*newMember))
        cout << "Member successfully removed!" << endl;
    else
        cout << "Error: Member could not be removed." << endl;
}

void search(List *members)
{
    string phone;

    // Prompt user to enter the phone number of the member to search for
    cout << "Enter the phone number of the member to search for: ";
    cin >> phone;

    // Create a new member with the phone number
    Member* member = new Member(phone);

    // Search for the member in the list
    Member* foundMember = members->search(*member);

    // Print the member's information if found
    if (foundMember != NULL)
    {
        cout << "Member found!" << endl;
        cout << foundMember << endl;
    }
    else
    {
        cout << "Member not found." << endl;
    }


}
void modify(List *members)
{
    string phone;
    string response;
    char input;

    // Prompt user to enter the phone number of the member to search for
    cout << "Enter the phone number of the member to modify: ";
    cin >> phone;

    // Get the member from the list
    Member* member = new Member(phone);
    Member* foundMember = members->search(*member);

    // Prompt the user for which field to modify, n for name, p for phone, e for email, c for credit card
    cout << "n --> to change the name" << endl;
    cout << "m -> to change the email" << endl;
    cout << "c -> to change the credit card" << endl;
    cout << "x -> to cancel" << endl;

    cin >> input;
    input = tolower(input);

    switch(input) 
    {
        case 'n': cout << "Enter the new name: "; cin >> response; foundMember->setName(response); break;
        case 'm': cout << "Enter the new email: "; cin >> response; foundMember->setEmail(response); break;
        case 'c': cout << "Enter the new credit card number: "; cin >> response; foundMember->setCreditCard(response); break;
        case 'x': cout << "Modification cancelled." << endl; break;
        default: cout << "Not sure what you mean! Returning to main menu..." << endl;
    }

    return;
}
// Print all members in the list
void print(List *members)
{
    cout << "Now printing the list containing " << members->getElementCount() << " elements" << endl;
    members->printList();
}