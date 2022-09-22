/* 
 * sum_array.cpp
 *
 * Description: Sums an array of integers and prints it on the command line. 
 * 
 * Author: Steven Wong 
 * 
 * Date Modified: September, 2022
 */ 

#include <iostream>
using namespace std;

// Function prototypes
int sumArray(int arr[], unsigned int arrSize);

int main(void)
{
    int * arr = NULL;        
    unsigned int arrSize = 0;    
    int sumTotal = 0; 

    // Get the array size from the user using cin:
    cout << "Enter the number of values to be summed: ";
    cin >> arrSize; 

    // Create a heap-allocated (dynamically allocated) array
    arr = new int[arrSize];

    // Ensure that memory was correctly allocated 
    if (arr != NULL)
    {
        // Prompt the user to enter each integer value, one at a time, until the array is full
        for (unsigned int i = 0; i < arrSize; i++)
        {
            cout << "Enter the integer value for array index " << i << ": ";
            cin >> arr[i];
        }
        // Print the sum of the values.
        sumTotal = sumArray(arr, arrSize);
        cout << "The sum of the values in the array is: " << sumTotal << endl;

        // Careful here! Make sure you know the difference between the delete[ ] operator and the delete operator.
        // Delete the dynamically allocated array before terminating the program.
        delete [] arr;

        // Return the sum of the values
        return sumTotal;
    }
    // Give error message
    cout << "Error: Failed to allocate memory..." << endl;
    return sumTotal;
}

// Loop through an array of size "arrSize" and return the sum of its integer values 
int sumArray(int arr[], unsigned int arrSize)
{
    // Counter variable
    int sum = 0;
    for (unsigned int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
    }
    return sum;
}


