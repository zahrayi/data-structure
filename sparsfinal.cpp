#include<iostream>
#include<string>
using namespace std;

const int maxsize = 100;

void sparse_matrix(int array[maxsize][maxsize], int n) {
	
    int c = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] != 0) {
                c++;
            }
        }
    }
    
    int sparse[maxsize][3];
     
    int index = 0;
     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] != 0) {
                sparse[index][0] = i;
                sparse[index][1] = j;
                sparse[index][2] = array[i][j];
                index++;
            }
        }
    }
    array[0][0]=n;
    array[0][1]=n;
	array[0][2]=c;
}