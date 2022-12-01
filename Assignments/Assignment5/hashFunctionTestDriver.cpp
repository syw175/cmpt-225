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

// Time efficiency: ...
// Space efficiency: ...
// Hash Function 1: A simple modulo hashing method that takes the phone number and divides it by the capacity M; taking
//                  the remainder as our hash index. 
unsigned int hashSimpleModulo(string phone);

// Time efficiency: ...
// Space efficiency: ...
// Hash Function 2: Breaks up components of phone into XXX-YYY-ZZZZ, reversing Xs and Zs. Take the sum the components
//                  and divide by capacity M; taking the remainder as our hash index.
unsigned int hashBoundaryFolding(string phone);

// Time efficiency: ...
// Space efficiency: ...
// Hash Function 3:
unsigned int hashToBeNamed(string phone);

// Create a number of indexing keys (phone numbers)
void createRandomTestData(unsigned int size, unsigned int digitCount);

// Start program
int main(int argc, char *argv[])
{
    // Initialize variables
    List *testHashFunc1 = new List(hashSimpleModulo);
    List *testHashFunc2 = new List(hashBoundaryFolding);
    List *testHashFunc3 = new List(hashToBeNamed);
    string aPhoneNumber = "";

    // Read input from stdin
    if ()








    return 0;
}