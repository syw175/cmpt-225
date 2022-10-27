/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 * 
 * Implemented by: Steven Wong
 * Date of last modification: Oct. 2022
 */

#include "Dictionary.h"


// CHECK INCLUDES,, WHERE TO PLACE...

// Default Constructor
Dictionary::Dictionary() {}

// Destructor
Dictionary::~Dictionary()
{
    delete keyValuePairs;
}

// Description: Return the number of elements contained in our dictionary
unsigned int Dictionary::getElementCount() const
{
    return keyValuePairs->getElementCount();
}

// Description: Puts "newElement" (association of key-value) into the Dictionary.
// Precondition: "newElement" does not already exist in the Dictionary.
//               This is to say: no duplication allowed.
// Exception: Throws ElementAlreadyExistsException if "newElement" already exists in the Dictionary.
void Dictionary::put(WordPair &newElement)
{
    // Ask: Ref cannot be initilized to nullptr right? Do not need to check for it?
    // Do I catch these exceptions or do I do it BELOW
    // try
    // {
    //     keyValuePairs->insert(newElement);
    // }
    // catch(const ElementAlreadyExistsException &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }    
    keyValuePairs->insert(newElement);
}

// Description: Gets "newElement" (i.e., the associated value of a given key) from the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws ElementDoesNotExistException if the key is not found in the Dictionary.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
WordPair& Dictionary::get(WordPair &targetElement) const
{
    // Or like this...
    return keyValuePairs->retrieve(targetElement);
}

// Description: Prints the content of the Dictionary.
void Dictionary::displayContent(void visit(WordPair&)) const
{
    keyValuePairs->traverseInOrder(visit);
}