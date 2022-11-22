/*
 * File: AVL-Tree.h
 *
 * Description: Implementation of a link based AVL-Tree ADT class
 * 
 * Date: November 2022
 * Name: Steven Wong
*/

#include <iostream>

template <class T>
class AVL
{
    private:
        class AVLNode
        {
            public:
                <T> data;
                int height;
                AVLNode<T> *left;
                AVLNode<T> *right;
                AVLNode(<T> element) : data(element), height(0), left(nullptr), right(nullptr) {}
        }

        AVLNode<T> *root;
        AVLNode<T> *leftRotate(AVLNode<T> *node);
        AVLNode<T> *leftRightRotate(AVLNode<T> *node);
        AVLNode<T> *rightRotate(AVLNode<T> *node);
        AVLNode<T> *rightLeftRotate(AVLNode<T> *node);
        unsigned int getTreeHeight(AVLNode<T> *node);
        void preOrderPrint(AVLNode<T> *node);
        void inOrderPrint(AVLNode<T> *node);
        void postOrderPrint(AVLNode<T> *node);
        void insert(AVLNode<T> &node);
        void remove(AVLNode<T> &node);

    public:
        AVL();
        void insert(AVLNode<T> &element);
        bool search(AVLNode<T> &element);
        bool remove(AVLNode<T> &element);
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();
};
