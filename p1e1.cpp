#include<iostream>
#include<string>
using namespace std;

int power(int a,int b){

if(b==0)
{
	return 1;
}
else
{
	return a * power(a,b-1);
}
}
int main()
{
	cout<<power(2,8);
}