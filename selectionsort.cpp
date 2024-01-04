#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void selectionSort(int arr[], int n)
{
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
            swap(&arr[min], &arr[i]);
    }
}


