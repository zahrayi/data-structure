#include<iostream>
#include<string>
using namespace std;

class array {
public:
    int find(int a[], int n, int key) {
        for (int i = 0; i < n; i++) {
            if (a[i]==key) {
                return i;
            }
        }
        return -1;
    }

    
    int insert(int a[],int add,int n,int c)
    {
      if(n>=c)
      {
        return n;
    }
    a[n]=add;
    
    return(n+1);
  }


    int delet(int a[],int n,int del)
    {
    	int p;
    	p=find(a,n,del);
    	if(p==-1)
    	{
    		return n;
		}
		
		for(int i=p;i<=n-2;i++)
		{
			a[i]=a[i+1];
		}
		return n-1;
	}
};
