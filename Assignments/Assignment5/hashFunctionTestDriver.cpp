/*
 * hashFunctionTestDriver.cpp
 *
 * Class Description: Test hashing strategies and the ability of our List
 *                    ADT class to address collisions by generating a sequence
 *                    of random phone numbers and testing the efficiency of our List
 *                    class. Our List ADH does not permit duplicate phone numbers.
 * 
 * Author: Steven Wong
 * Date: Last modified: Dec 2022
 */

#include <iostream>
#include <string>
#include "List.h"
#include "Member.h"

// Function prototypes: 
// Let's record our results as comments above each hash function. More specifically
// Supply a description of the spread of the hash table indices.
// Indicate the number of empty cells in the hash table once all elements have been inserted.
// State the number of elements that were inserted into the hash table using one probe, the number of elements that were inserted into the hash table using more than one probe and the number of probes done in each hash table cell.
// Any other results we wish to report on.

// If we do not have enough space to report our results as comments above each hash function, we can add them as comments at the bottom of our file.
// Finally, conclude which hash function best spreads over the whole hash table the hash table indices it produces.

// Time efficiency: O(1)
// Space efficiency: O(1)
// Hash Function 1: A simple modulo hashing method that takes the phone number and divides it by the capacity M; taking
//                  the remainder as our hash index through the modulo operator.
unsigned int hashSimpleModulo(string phone);

// Time efficiency: O(1)
// Space efficiency: O(1)
// Hash Function 2: Sum of the 1-3th digits, 4-6th digits, and 7-10th digits of the phone number modulo M           
unsigned int hashSimpleShift(string phone);

// Time efficiency: O(1)
// Space efficiency: O(1)
// Hash Function 3: Breaks up components of phone into XXX-YYY-ZZZZ, reversing Xs and Ys. Take the sum the components
//                  and divide by capacity M; taking the remainder as our hash index.
unsigned int hashBoundaryFolding(string phone);

// Create a number of indexing keys (phone numbers)
void createRandomTestData(unsigned int size, unsigned int digitCount);

// Reverse the digits of a given number
unsigned int reverseDigits(unsigned int number);

// Start program
int main(int argc, char *argv[])
{
    // Initialize variables
    List *testHashFunc1 = new List(hashSimpleModulo);
    List *testHashFunc2 = new List(hashSimpleShift);
    List *testHashFunc3 = new List(hashBoundaryFolding);
    string aPhoneNumber = "";

    // INCOMPLETE
    return 0;
}

// A simple modular arithmetic hashing method
unsigned int hashSimpleModulo(string phone)
{
    unsigned int hashcode = stoul(phone);
    return hashcode % List::CAPACITY;
}

// A simple shift hashing method
unsigned int hashSimpleShift(string phone)
{
    unsigned int firstThree = stoul(phone.substr(0, 3));
    unsigned int secondThree = stoul(phone.substr(3, 3));
    unsigned int lastFour = stoul(phone.substr(6, 4));
    // Add all three components and modulo by capacity to get hashcode
    unsigned int hashcode = (firstThree + secondThree + lastFour) % List::CAPACITY;
}

// A simple boundary folding hashing method
unsigned int hashBoundaryFolding(string phone)
{
    unsigned int firstThree = stoul(phone.substr(0, 3));
    unsigned int secondThree = stoul(phone.substr(3, 3));
    unsigned int lastFour = stoul(phone.substr(6, 4));

    // Reverse first three digits and second three digits
    unsigned int reversedFirstThree = reverseDigits(firstThree);
    unsigned int reversedSecondThree = reverseDigits(secondThree);

    // Sum all three components and modulo by capacity to get hashcode
    return (reversedFirstThree + reversedSecondThree + lastFour) % List::CAPACITY;
}

// Simple function to reverse the digits of a number
unsigned int reverseDigits(unsigned int number)
{
    int reversed = 0;
    // While number is not 0, keep dividing by 10 to get the last digit 
    while (number > 0)
    {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}

// Create a number of indexing keys (phone numbers)
void createRandomTestData(unsigned int size, unsigned int digitCount)
{
    // Incomplete
}