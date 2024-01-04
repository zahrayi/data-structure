#include <iostream>
using namespace std;


struct Node {
    float data;
    Node* next;
};


void insertNode(Node*& head, float value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


void insertionSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;

        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* search = sorted;
            while (search->next != nullptr && search->next->data < current->data) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    head = sorted;
}