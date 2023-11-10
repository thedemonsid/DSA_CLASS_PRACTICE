#include <bits/stdc++.h>
using namespace std;

void Max_heapify(int heap[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (largest <= n && heap[largest] < heap[left])
    {
        largest = left;
    }
    else if (largest <= n && heap[largest] < heap[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(heap[largest], heap[i]);
        Max_heapify(heap, n, largest);
    }
}

void print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int heap[6] = {-1, 54, 53, 55, 52, 50};
    n = sizeof(heap) / sizeof(int) - 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> heap[i];
    }
    for (int i = n / 2; i > 0; i--)
    {
        Max_heapify(heap, n, i);
    }
    print(heap, n);
}