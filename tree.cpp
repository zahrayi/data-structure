#include <iostream>

class Node {
public:
    int value;
    Node* firstChild;
    Node* nextSibling;

    Node(int val) : value(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
public:
    Node* root;

    void Insert(Node* parent, int value) {
        Node* newNode = new Node(value);
        if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        } else {
            Node* current = parent->firstChild;
            while (current->nextSibling != nullptr) {
                current = current->nextSibling;
            }
            current->nextSibling = newNode;
        }
    }