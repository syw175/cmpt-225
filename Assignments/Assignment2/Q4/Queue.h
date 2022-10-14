/* 
 * Queue.h
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Steven Wong and Chen Min
 * Date: October 2022
 */
 
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue {

/* You cannot remove/modify the data members below, but you can add to them. */
	
    private:
        static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
        int *elements;

        unsigned int elementCount = 0;                  // Number of elements in the Queue - if you need it!
        unsigned int capacity = INITIAL_CAPACITY;       // Actual capacity of the data structure (number of cells in the array)
        unsigned int frontindex = 0;                    // Index of front element (next dequeued/peeked element)
        unsigned int backindex = 0;                     // Index of where the next element will be enqueued                     

/* You can add private methods. */


    public:
 
/* You cannot remove/modify the public methods below. This also applies to their documentation. */

        // Description: Constructor
        Queue();

        // Description: Destructor
        ~Queue();

        // Description: Inserts element x at the back of Queue
        // Time Efficiency: O(1)
        void enqueue(int x);

        // Description: Removes the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        void dequeue();

        // Description: Returns a copy of the frontmost element
        // Precondition: Queue not empty
        // Time Efficiency: O(1)
        int peek() const;

        // Description: Returns true if and only if Queue empty
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Returns the current capacity of the Queue
        // Time Efficiency: O(1)
        unsigned int getCapacity() const;

        // Description: Returns the number of elements in the Queue
        // Time Efficiency: O(1)
        unsigned int getElementCount() const;

        // Description: Testing function used to print out the Queue
        // Time Efficiency: O(n)
        friend std::ostream &operator<<(std::ostream &os, const Queue &q);
};
#endif


