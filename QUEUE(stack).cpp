#include<iostream>
#include <stack>
using namespace std;

class QueueWithTwoStacks {
private:

    stack<int> enqueueStack;  // Stack for enqueue operation
    stack<int> dequeueStack; // Stack for dequeue operation



public:
    void enqueue(int value) {
        enqueueStack.push(value);
    }


    int dequeue() {
        if (dequeueStack.empty()) {
            while (!enqueueStack.empty()) {
                dequeueStack.push(enqueueStack.top());
                enqueueStack.pop();
            }
        }

        if (dequeueStack.empty()) {
            return -1;
        }

        int frontElement = dequeueStack.top();
        dequeueStack.pop();

        return frontElement;
    }


    bool isEmpty() {
        return enqueueStack.empty() && dequeueStack.empty();
    }
};



   
