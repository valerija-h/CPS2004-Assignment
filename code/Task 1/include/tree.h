#ifndef ANIMALS_TREE_H
#define ANIMALS_TREE_H

#include "header.h"

//Node generic class template.
template <class T> class Node{
    Node<T> *left;
    Node<T> *right;
    T animal;
public:
    explicit Node(T animal);
    void setLeft(Node<T> *left);
    void setRight(Node<T> *right);
    void setAnimal(T animal);
    Node<T>* getLeft();
    Node<T>* getRight();
    bool hasLeft();
    bool hasRight();
    T getAnimal();
    //Getting from Animal Class Functions
    float getLength();
    string getName();
    string displayAnimal();
    string displayFeatures();
};

//Tree generic class template.
template <class T> class Tree{
    Node<T>* root;
public:
    Tree();
    Node<T>* getRoot();
    //------------- Printing the Tree -------------------
    void inOrder(Node<T> * root);
    void postOrder(Node<T> *root);
    void preOrder(Node<T> *root);
    //------------- Inserting/Deleting/Finding the Tree -------------------
    void insertNode(T animal);
    Node<T>* findNode(Node<T> *current, string name);
    void deleteNode(T animal);
};

#endif
