/* 
 * circle_array.cpp
 *
 * Description: Working with Circle objects and dynamically allocated arrays
 * 
 * Author: Steven Wong
 * 
 * Date: September, 2022
 */

#include <iostream>
#include "Circle.h"
using namespace std;

// Function prototypes
void getCircleValues(int &xValue, int &yValue, double &radius);

int main(void)
{
    // Initialize variables
    Circle *array = NULL; 
    unsigned int arraySize = 0;
    unsigned int elementCount = 0;
    int xVal; 
    int yVal;
    double radius;


    // Prompt the user to enter the size of the array.
    cout << "Enter the size of your desired array: "; 
    cin >> arraySize;

    // Create a dynamically allocated array of that size.
    array = new Circle[arraySize];

    // Prompt the user to enter the centre coordinates (x,y) and the radius of a circle.
    cout << "Now getting the requried information to create a new circle..." << endl;
    getCircleValues(xVal, yVal, radius);
    
    // Instantiate a Circle object with these values, then store this Circle object in the array.
    Circle *circle = new Circle(xVal, yVal, radius);

    // Check that memory was correctly allocated
    if (!circle) return 1;

    // Increment the count of elements.
    elementCount++;

    // Print the size of the array.
    cout << "The size of the array is ... " << arraySize << endl;

    // Print the number of Circle objects entered into the array.
    cout << "The number of Circle objects entered into the array is... " << elementCount << endl;

    // Print the number of "empty" cell(s) in array, i.e., cells that do not contain Circle objects.
    cout << "The number of empty cells in the array is... " << arraySize - elementCount << endl;

    // Print the content of the entire array, i.e., for each cell:
    for (unsigned int i = 0; i < arraySize; i++)
    {
        // Print the value of the index of the cell.
        cout << "The current cell index is... " << i << endl; 

        // If there is a Circle object stored in this cell, print it using the appropriate Circle method for this purpose.
        if (i < elementCount)
        {
            array[i].displayCircle();
        }
        // If no Circle object is stored in this cell, print "This cell is empty.".
        else
        {
            cout << "This cell is empty." << endl;
        }
    }

    // Delete the dynamically allocated array before terminating the program.
    delete [] array;
    return 0;
}

// Prompt the user to enter the centre coordinates (x,y) and the radius of a circle.
void getCircleValues(int &xValue, int &yValue, double &radius)
{
    cout << "Please enter the x coordinate of your circle: "; 
    cin >> xValue;

    cout << "Please enter the y coordinate of your circle: "; 
    cin >> yValue; 

    cout << "Please enter the radius of your circle: "; 
    cin >> radius; 
}
