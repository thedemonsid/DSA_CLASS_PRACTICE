// Write a C program for construction of min heap using heapify algorithm.
// Solution for question number-2.
#include <bits/stdc++.h>
using namespace std;

void heapify(int heap[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (smallest <= n && heap[smallest] > heap[left])
    {
        smallest = left;
    }
    else if (smallest <= n && heap[smallest] > heap[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(heap[smallest], heap[i]);
        heapify(heap, n, smallest);
    }
}

void print(int heap[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void heap_sort(int heap[], int n)
{
    int size = n;

    while (size > 0)
    {
        swap(heap[size], heap[1]);
        size--;
        heapify(heap, size, 1);
    }
}

int main()
{
    int heap[6] = {-1, 50, 54, 52, 60, 53};
    int n = sizeof(heap) / sizeof(int) - 1;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(heap, n, i);
    }
    print(heap, n);

    heap_sort(heap, n);

    print(heap, n);
}