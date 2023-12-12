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
int RemoveNodeAtIndex(int index) {
        Node* temp = head;
        if (index == 0) {
            while (temp->next != head) {
                temp = temp->next;
            }
            int data = head->data;
            if (head->next == head) {
                delete head;
                head = NULL;
            } else {
                Node* temp2 = head;
                head = head->next;
                temp->next = head;
                delete temp2;
            }
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

    int SizeOfList() {
        return size;
    }

    void Concatenate(CircularLinkedList* list) {
        if (head == NULL) {
            head = list->head;
        } else if (list->head != NULL) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = list->head;
            Node* temp2 = list->head;
            while (temp2->next != list->head) {
                temp2 = temp2->next;
            }
            temp2->next = head;
        }
        size += list->size;
    }

    void Invert() {
        Node* prev = head;
        Node* current = head->next;
        Node* next;
        while (current != head) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        next->next = prev;
        head = prev;
    }
    

};
