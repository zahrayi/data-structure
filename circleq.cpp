#include <iostream>
#define SIZE 5 

using namespace std;

class Queue {
private:
  int items[SIZE], front, rear;

public:
  Queue() {
    front = -1;
    rear = -1;
  }
  
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  void enQueue(int element) {
    if (isFull()) {
      return;
    }

    else {
      if (front == -1)
        front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
    }
  }
  int deQueue() {
    int element;
    if (isEmpty()) {
      return (-1);
    }
    else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      
      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }
}
int peek()
  {
    int element;
    if (isEmpty()) {
      return (-1);
    }
    else
    {
      element = items[front];
    }
    return element;

  }

  void reverse() {
    int i, j;
    while (front != rear) {
      i = front;
      j = rear;
      Int temp=items[i];
items[i]=items[j];
items [j]=temp;
      front = (front + 1) % SIZE;
      rear = (rear - 1 + SIZE) % SIZE;
    }
  }

};
