/* 
 * hashDataCollection.h
 *
 * Description: Generic Data Collection based on Hashing for the
 *              purpose of testing the goodness of hash functions
 *
 * Author: AL
 * Date: Nov. 2022
 * 
 */

#ifndef HASH_DATA_COLLECTION_H
#define HASH_DATA_COLLECTION_H

#include <string>

using std::string;

class hashDataCollection {

private:
  string * hashTable = nullptr;             // HashTable - Underlying data structure (array) of our Data Collection

  unsigned int * collisions = nullptr;      // Record the number of time hash function produce a particular hash index
  unsigned int elementCount = 0;            // Current number of elements stored into Data Collection
  unsigned int (*hashFcn)(string name);     // Pointer to hash function

public:
  constexpr static unsigned int SIZE = 100; // Size of hashTable - underlying data structure (array) of our Data Collection

  // Constructor
  hashDataCollection(unsigned int (*hFcn)(string));   

  // Destructor
  ~hashDataCollection();  
  
  // Description: Inserts newElement into Data Collection.
  void insert(string newElement);	 

  // Description: Prints content of hash table.		
  void print();  
  
  // Description: Prints an histogram showing distribution of hash indices over the hash table.	
  void histogram();
  
  // Description: Prints various stats.	
  void printStats();          
};
#endif
