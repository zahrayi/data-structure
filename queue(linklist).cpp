#include <iostream>
using namespace std;
#include "list1.cpp"
class Queue {
    LinkedList l;
    int max_size;

public:
    Queue(int size) : max_size(size) {}

    void Enqueue(int value) {
        if (!isfull()) {
            l.InsertAtEnd(value);
        }
    }

    int Dequeue() {
        if (!isempty()) {
            return l.RemoveNodeAtBegin();
        
        }
    }

    int Peek() {
        if (!isempty()) {
            return l.head->data;
        }
    }
