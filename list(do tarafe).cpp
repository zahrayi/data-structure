#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(NULL), tail(NULL), size(0) {}

    void InsertAtIndex(int data, int index) {
        Node* newNode = new Node();
        newNode->data = data;

        if (index == 0) {
            newNode->next = head;
            newNode->prev = NULL;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            if (newNode->next == NULL) {
                tail = newNode;
            }
        }
        size++;
    }
    
    
    void UpdateNode(int data, int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = data;
    }

    void InsertAtEnd(int data) {
        InsertAtIndex(data, size);
    }

    void InsertAtBegin(int data) {
        InsertAtIndex(data, 0);
    }

    

    int RemoveNodeAtIndex(int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp == head) {
            head = temp->next;
        }
        if (temp == tail) {
            tail = temp->prev;
        }
        int data = temp->data;
        delete temp;
        size--;
        return data;
    }
    
    
    
    int SizeOfList() {
        return size;
    }
    
    
    
     int RemoveNodeAtEnd() {
        return RemoveNodeAtIndex(size - 1);
    }

    int RemoveNodeAtBegin() {
        return RemoveNodeAtIndex(0);
    }

    

    void Concatenate(DoublyLinkedList* list) {
    if (list->head != NULL) {
        if (head == NULL) {
            head = list->head;
        } else {
            tail->next = list->head;
            list->head->prev = tail;
        }

        tail = list->tail;
        size += list->size;
    }
}


    void Invert() {
        Node* temp = head;
        Node* nextNode;
        while (temp != NULL) {
            nextNode = temp->next;
            temp->next = temp->prev;
            temp->prev = nextNode;
            if (nextNode == NULL) {
                tail = head;
                head = temp;
            }
            temp = nextNode;
        }
    }
   
};

