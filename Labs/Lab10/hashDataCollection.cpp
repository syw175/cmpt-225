/* 
 * hashDataCollection.cpp
 *
 * Description: Generic Data Collection based on Hashing for the
 *              purpose of testing the goodness of hash functions
 *
 * Author: AL
 * Date: Nov. 2022
 * 
 */

#include "hashDataCollection.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor
hashDataCollection::hashDataCollection(unsigned int (*hFcn)(string)) : hashFcn(hFcn) {} // Save hash function address

// Destructor
hashDataCollection::~hashDataCollection( ) {

  // Release all heap memory
  if ( hashTable != nullptr ) { 
    delete [] hashTable;
	hashTable = nullptr;
  }

  if ( collisions != nullptr ) { 
    delete [] collisions;
	collisions = nullptr;
  }	
  
  hashFcn = nullptr; // Do I need to release this pointer ??? Check with valgrind!

}  

// Description: Inserts newElement into Data Collection.
void hashDataCollection::insert(string newElement) {
  
  if ( elementCount == 0 ) {
    hashTable = new string[SIZE];  // Allocate heap memory for the hashTable
    if ( hashTable == nullptr ) return; //throw 
    collisions = new unsigned int[SIZE]; // Allocate heap memory for the collisions
    if ( collisions == nullptr ) return; //throw 
    for ( unsigned int i = 0; i < SIZE; i++ ) {
      hashTable[i] = "";  // Initialize array hashTable
      collisions[i] = 0;  // Initialize array collisions
    }
  }
  
  // If hashTable full, expand ... 
  
  // Call hash function using indexing key to get hash index
  unsigned int hashIndex = (*hashFcn)(newElement);

  // Insert newElement in hashTable at hashIndex
  hashTable[hashIndex] = newElement;
  
  // Record the "hit" hence keep track of number of collisions
  collisions[hashIndex]++; 

  // One more element inserted!
  elementCount++;
  
  return;  
}  

// Description: Prints content of hash table.			
void hashDataCollection::print() {
  
  cout << endl << "Printing Hash Data Collection with " << this->elementCount << " elements: " << endl;
  for ( unsigned int i = 0; i < SIZE; i++ ) {
    if ( hashTable[i] != "" ) cout << "HashTable[" << i << "] = " << hashTable[i] << endl; 
  }
  return;
}  

// Description: Prints an histogram showing distribution of hash indices over the hash table.	
void hashDataCollection::histogram() {

  cout << endl << "Histogram showing distribution of hash indices over the hash table: " << endl;
  for ( unsigned int i = 0; i < SIZE; i++ ) {
    cout << "At hashTable[" << i << "]: ";
    for ( unsigned int j = 0; j < collisions[i]; j++ ) 
       cout << "*";
    cout << endl;
  } 
  return;
}
 


// Description: Prints various stats.	
void hashDataCollection::printStats() {
  unsigned int emptyCell = 0;
  unsigned int oneProbe = 0;
  unsigned int moreProbes = 0;

  cout << endl << "In the process of inserting " << this->elementCount << " elements, number of collisions ... " << endl;
  for ( unsigned int i = 0; i < SIZE; i++ ) {
    if ( collisions[i] == 0 ) emptyCell++;
    else
      if ( collisions[i] == 1 ) oneProbe++;
      else {
        if ( collisions[i] > 1 ) {
          moreProbes++;
          cout << "at hashTable[" << i << "] = " << collisions[i] << endl;
        } 
      }
  }
    
  cout << endl << "There are " << emptyCell << " empty cells." << endl;
  cout << oneProbe << " elements inserted without collisions." << endl;
  cout << "There were " << moreProbes << " collisions." << endl;
  
  return;
}