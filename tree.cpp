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
    void Remove(Node* parent, int value) {
        Node* current = parent->firstChild;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->value == value) {
                if (prev == nullptr) {
                    parent->firstChild = current->nextSibling;
                } else {
                    prev->nextSibling = current->nextSibling;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->nextSibling;
        }
    };