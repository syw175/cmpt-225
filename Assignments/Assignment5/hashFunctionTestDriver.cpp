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
#include <fstream>
#include "List.h"
#include "Member.h"
#include <stdlib.h> // for rand()
#include <time.h>   // for time()

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::__cxx11::stoul;

// START HASH FUNCTIONS
// --------------------------------------------------------------------------------------------
// Time efficiency: O(1)
// Space efficiency: O(1)
// In the process of inserting 103 elements... There were 43 elements inserted without probing and the average number of probes was 1.5.
// No empty cells in the hash table. Same data used for all hash functions.
// Hash Function 1: A simple modulo hashing method that takes the phone number and divides it by the capacity M; taking
//                  the remainder as our hash index through the modulo operator.
unsigned int hashSimpleModulo(string phone);

// Time efficiency: O(1)
// Space efficiency: O(1)
// In the process of inserting 103 elements... There were 32 elements inserted without probing and the average number of probes was 1.75.
// No empty cells in the hash table. Same data used for all hash functions.
// Hash Function 2: Sum of the 1-3th digits, 4-6th digits, and 7-10th digits of the phone number modulo M           
unsigned int hashSimpleShift(string phone);

// Time efficiency: O(1)
// Space efficiency: O(1)
// In the process of inserting 103 elements... There were 51 elements inserted without probing, making this the most efficient hash function.
// No empty cells in the hash table. Same data used for all hash functions.
// Hash Function 3: Breaks up components of phone into XXX-YYY-ZZZZ, reversing Xs and Ys. Take the sum the components
//                  and divide by capacity M; taking the remainder as our hash index.
unsigned int hashBoundaryFolding(string phone);
// END HASH FUNCTIONS
// --------------------------------------------------------------------------------------------
// Description: Create a number of indexing keys (phone numbers) and print each out as it is generated.
void createRandomTestData(unsigned int size, unsigned int digitCount);
// Description: Reverse the digits of a given number
unsigned int reverseDigits(unsigned int number);

// Start program
int main(int argc, char *argv[])
{
    // Initialize variables
    List *testHashFunc1 = new List(hashSimpleModulo);
    List *testHashFunc2 = new List(hashSimpleShift);
    List *testHashFunc3 = new List(hashBoundaryFolding);
    string aPhoneNumber = "";

    // If you enter the command: ./hftd 100 16
    // createRandomTestData( 100, 16 ) is called
    // and will create 100 elements and 
    // print each element on its own line on stdout.
    // Each of these elements will be made of 16 digits.
    // Each digit will be randomly selected from the range [0..9].
    // If you enter the command: ./hftd 100 16 > dataFile_100_16.txt
    // all of these 100 elements will be stored into 
    // the file dataFile_100_16.txt, which can be read later.
    if (argc == 3)
        createRandomTestData(stoul(argv[1]), stoul(argv[2]));
    // If you enter the command: ./hftd dataFile_100_16.txt
    // each element of dataFile_100_16.txt is read as 
    // an indexing key, which is then inserted into "testingModulo",
    // which is an object of the hashDataCollection class.
    // As part of inserting this newElement (i.e., anIndexingKey),
    // anIndexingKey is hashed and the produced hash index is
    // used to insert anIndexingKey into the hashTable. 
    // See the implementation of insert(...) in hashDataCollection.cpp.
    else
    {
        if (argc == 2)
        {
            ifstream myfile(argv[1]);
            if (myfile.is_open())
            {
                while (getline(myfile, aPhoneNumber))
                {
                    Member *newMember = new Member(aPhoneNumber);
                    testHashFunc1->insert(*newMember);
                    testHashFunc2->insert(*newMember);
                    testHashFunc3->insert(*newMember);
                }
                myfile.close();
                
                // Print out the results of our hash functions
                cout << "Hash Function 1: " << endl;
                testHashFunc1->printList();
                cout << "Hash Function 2: " << endl;
                testHashFunc2->printList();
                cout << "Hash Function 3: " << endl;
                testHashFunc3->printList();
            }
            else
                cout << "Unable to open file";
        }
        else
            cout << "Usage: " << argv[0] << " <dataFileName>" << endl;
    }

    delete testHashFunc1;
    delete testHashFunc2;
    delete testHashFunc3;
    testHashFunc1 = nullptr;
    testHashFunc2 = nullptr;
    testHashFunc3 = nullptr;
    return 0;
}

// A simple modular arithmetic hashing method
unsigned int hashSimpleModulo(string phone)
{
    unsigned int hashCode = stoul(phone.substr(0, 3) + phone.substr(4, 3) + phone.substr(8, 4));
    return hashCode % List::CAPACITY;
}

// A simple shift hashing method
unsigned int hashSimpleShift(string phone)
{
    unsigned int firstThree = stoul(phone.substr(0, 3));
    unsigned int secondThree = stoul(phone.substr(4, 3));
    unsigned int lastFour = stoul(phone.substr(8, 4));
    // Add all three components and modulo by capacity to get hashcode
    unsigned int hashcode = firstThree + secondThree + lastFour;
    return hashcode % List::CAPACITY;
}

// A simple boundary folding hashing method
unsigned int hashBoundaryFolding(string phone)
{
    unsigned int firstThree = stoul(phone.substr(0, 3));
    unsigned int secondThree = stoul(phone.substr(4, 3));
    unsigned int lastFour = stoul(phone.substr(8, 4));

    // Reverse first three digits and second three digits
    unsigned int reversedFirstThree = reverseDigits(firstThree);
    unsigned int reversedSecondThree = reverseDigits(secondThree);
    unsigned int hashcode = reversedFirstThree + reversedSecondThree + lastFour;

    // Sum all three components and modulo by capacity to get hashcode
    return hashcode % List::CAPACITY;
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
    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 0; j < digitCount; j++)
        {
            // If we are at the 4th digit or 7th digit, add a dash
            if (j == 3 || j == 6)
            {
                cout << "-";
            }
            cout << rand() % 10;
        }
        cout << endl;
    }
    return;
}