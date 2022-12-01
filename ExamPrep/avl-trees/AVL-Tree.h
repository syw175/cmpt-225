/*
 * File: AVL-Tree.h
 *
 * Description: Implementation of a link based AVL-Tree ADT class
 *
 * Date: November 2022
 * Name: Steven Wong
*/

#include <iostream>

// Template declaration
template <class T>
class AVL
{
    private:
        class AVLNode
        {
            public:
                T &data;
                unsigned int height;
                AVLNode *left;
                AVLNode *right;
                AVLNode(T &element) : data(element), height(0), left(nullptr), right(nullptr) {}
        };

        AVLNode *root;
        unsigned int elementCount;

        AVLNode *leftRotate(AVLNode *node);
        AVLNode *leftRightRotate(AVLNode *node);
        AVLNode *rightRotate(AVLNode *node);
        AVLNode *rightLeftRotate(AVLNode *node);
        unsigned int getTreeHeightR(AVLNode *node) const;
        void preOrderPrintR(AVLNode *node) const;
        void inOrderPrintR(AVLNode *node) const;
        void postOrderPrintR(AVLNode *node) const;
        void insertR(AVLNode &node);
        void removeR(T &element, AVLNode *node);

    public:
        AVL();
        ~AVL();
        AVL(const AVL &src);
        void insert(T &element);
        bool search(T &element) const;
        bool remove(T &element);
        void preOrderPrint() const;
        void inOrderPrint() const;
        void postOrderPrint() const;
        unsigned int getElementCount() const;
};

// Template Definition
// Note to self, starting with public wrapper methods
template <class T>
AVL<T>::AVL() : root(nullptr), elementCount(0) {}

// Destructor
template <class T>
AVL<T>::~AVL()
{

}

// Copy Constructor
template <class T>
AVL<T>::AVL(const AVL &src) 
{

}

// Insert an element into the AVL, maintaining the balanced structure of the tree
template <class T>
void AVL<T>::insert(T &element)
{
    AVLNode *newNode = new AVLNode(element);
    insertR(*newNode);
    elementCount++;
}

template <class T>
bool AVL<T>::search(T &element) const
{
    if (getElementCount() == 0) 
        return false;
    else
        return search(element, this->root);
}

template <class T>
unsigned int AVL<T>::getElementCount() const
{
    return this->elementCount;
}

template <class T>
void AVL<T>::preOrderPrint() const
{

}

template <class T>
void AVL<T>::inOrderPrint() const
{

}

template <class T>
void AVL<T>::postOrderPrint() const
{

}