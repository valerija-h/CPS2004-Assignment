#include "../include/tree.h"

//------------------- Node Functions -------------------
template <class T>
Node<T>::Node(T animal) {
    this->animal = animal;
    left = right = nullptr;
}
template <class T>
void Node<T>::setLeft(Node<T> *left) {
    this->left = left;
}
template <class T>
void Node<T>::setRight(Node<T> *right) {
    this->right = right;
}
template <class T>
void Node<T>::setAnimal(T animal) {
    this->animal = animal;
}
template <class T>
Node<T>* Node<T>::getLeft() {
    return left;
}
template <class T>
Node<T>* Node<T>::getRight() {
    return right;
}
template <class T>
T Node<T>::getAnimal() {
    return animal;
}
template <class T>
float Node<T>::getLength() {
    return animal->getLength();
}
template <class T>
string Node<T>::getName() {
    return animal->getName();
}
template <class T>
string Node<T>::displayAnimal() {
    return animal->displayAnimal();
}
template <class T>
string Node<T>::displayFeatures() {
    return animal->displayFeatures();
}
template <class T>
bool Node<T>::hasLeft() {
    if(!left)
        return false;
    return true;
}
template <class T>
bool Node<T>::hasRight() {
    if(!right)
        return false;
    return true;
}

//------------------- Tree Functions -------------------

template <class T>
Tree<T>::Tree(){
    root = nullptr;
}
template <class T>
Node<T>* Tree<T>::getRoot(){
    return root;
}
//------------------- Printing Nodes -------------------
//Recursively print the left subtree, then the root, then the right subtree of each node.
template <class T>
void Tree<T>::inOrder(Node<T> * root){
    if (root != NULL) {
    inOrder(root->getLeft());
    cout << root->displayAnimal() << '\n';
    inOrder(root->getRight());
    }
}
//Recursively print the root, then the left subtree, then the right subtree of each node.
template <class T>
void Tree<T>::preOrder(Node<T> *root){
    if (root != nullptr) {
        cout << root->displayAnimal() << '\n';
        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}
//Recursively print the left subtree, then the right subtree, then the root of each node.
template <class T>
void Tree<T>:: postOrder(Node<T> *root){
    if (root != nullptr) {
        postOrder(root->getLeft());
        postOrder(root->getRight());
        cout << root->displayAnimal() << '\n';
    }
}
//------------------- Inserting Nodes -------------------
//Inserts an new node into a tree given a node.
template <class T>
void Tree<T>:: insertNode(T animal){
    //Creates a pointer to a new animal node.
    Node<T> *node = new Node<T>(animal);
    //If the tree is empty, set the root of the tree to the new node.
    if(root == nullptr){
        root = node;
        return;
    }
    //Iterates through each node in the tree to find a suitable position for the new node.
    Node<T> *current = root;
    while(current != nullptr){
        //Comparing the new animals length with the current nodes length.
        if(animal->getLength() < current->getLength()){
            //If the current node has no left children, set the new node as the left child of the current node.
            if(!current->hasLeft()){
                current->setLeft(node);
                break;
            }
            //Otherwise, keep searching for a free position in the left children of current node.
            current = current->getLeft();
        } else if (animal->getLength() > current->getLength()){
            //If the current node has no right children, set the new node as the right child of the current node.
            if(!current->hasRight()){
                current->setRight(node);
                break;
            }
            //Otherwise, keep searching for a free position in the right children of current node.
            current = current->getRight();
        } else {
            //If the new animal has the same length as current node, item won't be added.
            cerr << "Item already exists.\n";
            delete node;
            break;
        }
    }
}
//------------------- Finding Nodes -------------------
//Finds a node with the same name and returns a pointer to it.
template <class T>
Node<T>* Tree<T>:: findNode(Node<T> *current, string name) {
    //Base case, return null if current node is empty.
    if(current == nullptr){ return nullptr; }
    //If the current node has the same name, return the node.
    if(current->getName() == name){
        return current;
    } else {
        Node<T> * found;
        //Searches for the node in the left and right children of the current node.
        if((found = findNode(current->getLeft(),name)) != nullptr){
            return found;
        } else if ((found = findNode(current->getRight(),name)) != nullptr){
            return found;
        } else {
            //If node wasn't found in the left or right children, null is returned.
            return nullptr;
        }
    }
}
//Deletes a node from the tree given a node.
template <class T>
void Tree<T>:: deleteNode(T animal) {
    //If the root is null, function returns since tree must be empty.
    if(root == nullptr){cerr << "Tree is empty - can't delete node.\n"; return;}
    //Enters a while loop to set the current node as the node to be deleted and keep track of it's parent.
    Node<T> *current = root;
    Node<T> *parent = nullptr;
    while(current){
        //Searches in the left or right children of current node based on the length of the node to be deleted.
        if(animal->getLength() > current->getLength()){
            parent = current;
            current = current->getRight();
        } else if (animal->getLength() < current->getLength()) {
            parent = current;
            current = current->getLeft();
        } else {
            //Breaks when current node matches the node to be deleted.
            break;
        }
    }
    //If the current node is null, node couldn't be found so functions returns.
    if(!current){ return;}

    //If the node has no children.
    if(!current->hasLeft() && !current->hasRight()){
        //If it is the root, set the root to null.
        if(parent == nullptr){root = nullptr; delete current; return;}
        //If it is the left node of the parent node, set left node of parent to null.
        if(parent->getLeft() == current){
            parent->setLeft(nullptr);
        //If it is the right node of the parent node, set right node of parent to null.
        } else {
            parent->setRight(nullptr);
        }
        delete current;
        return;
    }
    //If the node only has right children.
    if(!current->hasLeft()){
        //If it is the root, set the root to the right children.
        if(parent == nullptr){root = current->getRight(); delete current; return;}
        //If it is the left node of the parent node, set left node of parent to the deleted node's right children.
        if(parent->getLeft() == current){
            parent->setLeft(current->getRight());
        //If it is the right node of the parent node, set right node of parent to the deleted node's right children.
        } else {
            parent->setRight(current->getRight());
        }
        delete current;
        return;
    }

    //If the node only has left children.
    if(!current->hasRight()){
        //If it is the root, set the root to the left children.
        if(parent == nullptr){root = current->getLeft(); delete current; return;}
        //If it is the left node of the parent node, set left node of parent to the deleted node's left children.
        if(parent->getLeft() == current){
            parent->setLeft(current->getLeft());
        //If it is the right node of the parent node, set right node of parent to the deleted node's left children.
        } else {
            parent->setRight(current->getLeft());
        }
        delete current;
        return;
    }

    //If the node has left and right children - get the inorder successor.
    Node<T> *nextParent = current->getRight();
    Node<T> *next = current->getRight();
    //Gets the smallest value (next) in the right branch of the node to be deleted and its parent (nextParent).
    while(next->hasLeft()){
        nextParent = next;
        next = next->getLeft();
    }
    //Removes the successor node from it's parent.
    nextParent->setLeft(nullptr);
    //Replacing the data of node to be deleted with the successor node.
    current->setAnimal(next->getAnimal());
    delete next;
}


