/*
 * ListTestDriver.cpp
 * 
 * Description: Test the methods of the List collection ADT. 
 *
 * Author: Steven Wong
 * 
 * Last modified: Sept. 2022
 */

#include <cassert>
#include <iostream>

#include "List.h"
#include "Member.h"

using namespace std;

int main(void)
{
    // Create a new list 
    List *newList = new List();

    // Check that the new list was successfully created
    assert(newList != NULL);

    // Check that the initial element count is 0
    assert(newList->getElementCount() == 0);

    // Create a new member and try to remove that member from the empty list 
    Member *newMember = new Member();
    Member &refMember = *newMember;
    assert(newList->remove(refMember) == false);

    //











    return 0;
}