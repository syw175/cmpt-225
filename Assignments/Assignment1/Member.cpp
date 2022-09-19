/*
 * Member.cpp
 * 
 * Class Description: Models a Fitness Studio Registration System.
 * Class Invariant: Each member has a unique cell phone number.
 *                  This cell phone number must have 12 digits.
 *                  This cell phone number must have the following format: XXX-XXX-XXXX.
 *                  This cell phone number cannot be modified. 
 *
 * Author: AL
 * 
 * Completed by: Steven Wong
 * 
 * Last modified: Sept. 2022
 */


#include <iostream>
#include <string>
#include "Member.h"


// TODO 
// Private Method:     
// void setPhone(const string aPhone);

// Public Methods
// Default Constructor:     Member();
// Parameterized Constructor:     Member(string aName, string aPhone, string anEmail, string aCreditCard);

// Getters and setters
// Description: Returns member's name.
// string getName() const;

// Description: Returns member's phone.
// string getPhone() const;

// Description: Returns member's email.
// string getEmail() const;
	
// Description: Returns member's credit card.
// string getCreditCard() const;

// Description: Sets the member's name.
// void setName(const string aName);

// Description: Sets the member's email.
// void setEmail(const string anEmail);

// Description: Sets the member's credit card number.
// void setCreditCard(const string aCreditCard);


// Overloaded Operators
// Description: Comparison operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if both Member objects have the same cell phone number.
bool Member::operator == (const Member & rhs) {

    return this->phone == rhs.getPhone();
}
	
// Description: Greater than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is > the 
//              cell phone number of "rhs" Member object.
bool Member::operator > (const Member & rhs) {

    return this->phone > rhs.getPhone();
} 

// Description: Less than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is < the 
//              cell phone number of "rhs" Member object.
bool Member::operator < (const Member & rhs) {
	
    return this->phone < rhs.getPhone();
} 

// For testing purposes!
// Description: Prints the content of "this".
// Example: Louis Pace, 604-853-1423, louis@nowhere.com, 1234 5678 9098 7654 
ostream & operator<<(ostream & os, const Member & p) {
	
    os << p.name << ", " << p.phone << ", " << p.email << ", " << p.creditCard << endl;  
	     
    return os;
} 

// end of Member.cpp
