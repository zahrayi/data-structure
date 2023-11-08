#include<iostream>
using namespace std;
int comb(int n, int r)
{
	if (r == 0 || r == n)
		return 1;
	return comb(n - 1, r) + comb(n - 1, r - 1);
}
int main()
{
	cout << comb(4,2);
	system("pause");
	return 0;
}