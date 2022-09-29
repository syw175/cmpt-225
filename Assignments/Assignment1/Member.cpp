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

const string EMPTY_STR = "";
const string DEF_PHONE = "000-000-0000";

// Private Method:     
// Description: Sets the member's cell phone number
void Member::setPhone(const string aPhone)
{
    // Check if phone number is valid
    if (aPhone.length() == 12 && aPhone[3] == '-' && aPhone[7] == '-')
        phone = aPhone;
    else
        phone = DEF_PHONE;
}

// Description: Create a member with a cell phone number of "000-000-0000". 
// Postcondition: All data members set to an empty string, 
//                except the cell phone number which is set to "000-000-0000".
Member::Member()
{
    // Set data members
    name = EMPTY_STR;
    phone = DEF_PHONE;
    email = EMPTY_STR;
    creditCard = EMPTY_STR;
}

// Parameterized Constructor
Member::Member(string aPhone)
{
    // Set data members
    name = EMPTY_STR;
    email = EMPTY_STR;
    creditCard = EMPTY_STR;
    setPhone(aPhone);
}

// Parameterized Constructor
Member::Member(string aName, string aPhone, string anEmail, string aCreditCard)
{
    name = aName;                     
    email = anEmail;
    creditCard = aCreditCard;
    setPhone(aPhone);
}

// Description: Returns member's name.
string Member::getName() const
{
    return name;
}

// Description: Returns member's phone.
string Member::getPhone() const
{
    return phone;
}

// Description: Returns member's email.
string Member::getEmail() const
{
    return email;
}
	
// Description: Returns member's credit card.
string Member::getCreditCard() const
{
    return creditCard;
}

// Description: Sets the member's name.
void Member::setName(const string aName)
{
    name = aName;
}

// Description: Sets the member's email.
void Member::setEmail(const string anEmail)
{
    email = anEmail;
}

// Description: Sets the member's credit card number.
void Member::setCreditCard(const string aCreditCard)
{
    creditCard = aCreditCard;
}

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
