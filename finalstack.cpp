#include<iostream>
using namespace std;
class stack1{
	int arr[100];
	public:
		int top;
		int x;
		int maxsize=100;
		stack1(){
			top=-1;
		}
		bool isempty()
		{
			if(top==-1)
			{
				return true;
			}
			else {
				return false;
			}
		}
		void push(int x)
		{
			if(top==maxsize-1)
			{
					return;
			}
			else{
				arr[++top]=x;
			}
		
		}
		int pop()
    {
      if(isempty())
      {
        return -1;
      }
      else
      {
        x=arr[top--];
        return x;
      }
    }
    int peek()
    {
      if(isempty())
      {
        return -1;
      }
      else
      {
        return arr[top];
      }
    }
	
};
