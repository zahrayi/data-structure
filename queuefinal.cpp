#include<iostream>
#include<string>
using namespace std;
const int maxsize=100;
class Queue{
	public:
		int front;
		int rear;
		int arr[maxsize];
	
	Queue()
	{
		front=-1;
		rear=-1;
	}
	
	bool isEmpty()
	{
		if(front==-1 && rear==-1)
		{
			return true;	
		}
		else
		{
			return false;
		}
	}
 
	bool isFull()
	{
		if (rear == maxsize - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
 
	
	
	int enqueue(int a)
	{
		if(isFull())
		{
			return -1;
		}
		else if(isEmpty())
		{
			front=rear=0;
		}
		else{
			rear++;
		}
		arr[rear]=a;
	}
 
	int dequeue()
	{
		if (isEmpty())
		{
			return -1;
		}
		else if (front == rear)
		{
			int temp = arr[front];
			front = rear = -1;
			return temp;
		}
		else{
			int temp = arr[front];
			front++;
			return temp;
		}
	}
	int peek()
	{
		if (isEmpty())
		{
			return -1;
		}
		else{
			return arr[front];
		}
	}
 
	
	Queue reverseQueue()
	{
		if(isEmpty())
		{
			return *this;
		}
		else
		{
			Queue reQueue;
			int temp[maxsize];
			int i=0;
			for(int j=rear;j>=front;j--)
			{
				temp[i]=arr[j];
				i++;
			}
			for(int k=0;k<i;k++)
			{
				reQueue.enqueue(temp[k]);
			}
			return reQueue;
		}
	}
		
};