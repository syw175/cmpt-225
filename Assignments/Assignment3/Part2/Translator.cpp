/*
 * Translator.cpp
 * 
 * Description: Translator Application which utilizes our Dictionary data collection class.
 * 
 * Implemented by: Steven Wong
 * Date of last modification: Oct. 2022
 */
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "Dictionary.h"

using std::cin;
using std::cout;
using std::ifstream;

// Function prototypes
void display(WordPair &anElement);


// Translation Algorithm:
// While not EOF  (typing <CTRL+D> at the command line creates an <EOF> signal)
//   Your Translator Application allows the user to enter one English word at a time (on one line).
//   It reads the English word entered.
//   It gets its translation from the dictionary object and prints it on the computer monitor screen.
//   If the English word is not found, ***Not Found!*** is printed instead.
int main (int argc, char** argv)
{
    Dictionary *dict = new Dictionary();

    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "dataFile.txt";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;

    // Code from AL, Part1 TestDriver.cpp
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        while (getline(myfile,aLine))
        {
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            translationW = aLine;
            WordPair aWordPair(englishW, translationW);
            // insert aWordPair into "testing" using a try/catch block??
            dict->put(aWordPair);
        }
     }
     myfile.close();

    // If user entered "display" at the command line, display the contents of the Dictionary
    if ((argc > 1) && (strcmp(argv[1], "display") == 0))
        dict->displayContent(display);
    
    // else if (argc == 1)
    // {
    //     // While not EOF...
    //     while (getline(cin, aWord))
    //     {
    //         // The user enters one English word at a time (on one line).
    //         WordPair aWordPair(aWord);
    //         try
    //         {
    //             translated = dict->get(aWordPair);
    //             cout << translated << endl;
    //         }
    //         catch (const ElementDoesNotExistException &e)
    //         {
    //             cout << "***Not Found!***" << endl;
    //         }
    //         catch (const EmptyDataCollectionException &e)
    //         {
    //             cout << e.what() << endl;
    //         }
    //     }
    // }
    // else
    //     cout << "Unable to open the file" << endl;

    delete dict;
    return 0;
}

// Display the elements in our dictionary
void display(WordPair &anElement)
{
  cout << anElement;
} 