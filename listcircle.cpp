#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* head;
    int size;

public:
    CircularLinkedList() : head(NULL), size(0) {}

    void InsertAtIndex(int data, int index) {
        Node* newNode = new Node();
        newNode->data = data;

        if (index == 0) {
            if (size == 0) {
                head = newNode;
                newNode->next = head;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                newNode->next = head;
                head = newNode;
                temp->next = head;
            }
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void InsertAtEnd(int data) {
        InsertAtIndex(data, size);
    }

    void InsertAtBegin(int data) {
        InsertAtIndex(data, 0);
    }

    void UpdateNode(int data, int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = data;
    }