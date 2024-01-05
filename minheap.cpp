#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]); 
        heapify(arr, n, smallest);
    }
}
void deleteRoot(int arr[], int& n)
{
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    heapify(arr, n, 0);
}

void insert(int arr[], int& n, int key)
{
    n = n + 1;
    int i = n - 1;
    arr[i] = key;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}



