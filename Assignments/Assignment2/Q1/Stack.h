/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Steven Wong and Chen Min
 * Date: October 2022
 */
 
class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };

        StackNode *head = nullptr;
        unsigned int elementCount = 0;
                
    public:
        // Default Constructor
        Stack();

        // Destructor
        ~Stack();

        // Insert an element onto the top of the stack and return true if successful, false otherwise
        bool push(int newElement);

        // Retrieve and return the top most element of the stack 
        int peek() const;

        // Remove the top most element of the stack, return true if successful, false otherwise
        bool pop();

        // Returns the number of elements in the stack
        unsigned int size() const;

        // Returns true if the Stack is empty and false otherwise
        bool isEmpty() const;

        // Overloaded << operator
        friend std::ostream & operator<<(std::ostream& os, const Stack &stack);
};
// End header file
