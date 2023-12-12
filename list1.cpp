#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    int size;

public:
    LinkedList() : head(NULL), size(0) {}

    void InsertAtIndex(int data, int index) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (index == 0) {
            newNode->next = head;
            head = newNode;
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

    int RemoveNodeAtIndex(int index) {
        Node* temp = head;
        if (index == 0) {
            head = temp->next;
            int data = temp->data;
            delete temp;
            size--;
            return data;
        } else {
            Node* prev = NULL;
            for (int i = 0; i < index; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            int data = temp->data;
            delete temp;
            size--;
            return data;
        }
    }

    int RemoveNodeAtEnd() {
        return RemoveNodeAtIndex(size - 1);
    }

    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }
    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }

    int sizeoflist() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void Concatenate(LinkedList* list) {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = list->head;
        size += list->size;
    }

    void Invert() {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
   
};