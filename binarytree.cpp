#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

    void insertNode(Node* currentNode, int value) {
        if (value < currentNode->data) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node(value);
            }
            else {
                insertNode(currentNode->left, value);
            }
        }
        else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node(value);
            }
            else {
                insertNode(currentNode->right, value);
            }
        }
    }

    Node* removeNode(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            return currentNode;
        }

        if (value < currentNode->data) {
            currentNode->left = removeNode(currentNode->left, value);
        }
        else if (value > currentNode->data) {
            currentNode->right = removeNode(currentNode->right, value);
        }
        else {
            if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            Node* minNode = findMinNode(currentNode->right);
            currentNode->data = minNode->data;
            currentNode->right = removeNode(currentNode->right, minNode->data);
        }
        return currentNode;
    }

    Node* findMinNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }