#include<iostream>
#include<string>
using namespace std;

const int maxsize = 5;

class Queue {
private:
    int stack1[maxsize];
    int stack2[maxsize];
    int top1; 
    int top2; 

public:
    Queue() {
        top1 = -1;
        top2 = -1;
    }

    bool isFull() {
    	if(top1 == maxsize - 1)
    	{
    		return true;
		}
        else
        {
        	return false;
		}
        
    }


    bool isEmpty() {
      if(top1 == -1 && top2 == -1)
      {
        return true;
    }
        else
        {
          return false;
    }
    }


    void enqueue(int x) {
        if (isFull()) {
            return;
        }
        else {
            top1++;
            stack1[top1] = x;
        }
    }

    int dequeue() {
        if (top1 == -1 && top2 == -1) {
            
            return -1;
        }
        else {
            if (top2 == -1) {
                while (top1 != -1) {
                    int temp = stack1[top1];
                    top1--;
                    top2++;
                    stack2[top2] = temp;
                }
            }

            int value = stack2[top2];
            top2--;

            return value;
        }
    }

     int peek() {
        if (top1 == -1 && top2 == -1) {
            
            return -1;
        }
        else {
            if (top2 == -1) {
                
                while (top1 != -1) {
                    int temp = stack1[top1];
                    top1--;
                    top2++;
                    stack2[top2] = temp;
                }
            }

            return stack2[top2];
        }
    }


    
};
