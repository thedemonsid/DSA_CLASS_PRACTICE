#include<bits/stdc++.h>
using namespace std;
//max heap impletetion
void heapify(vector<int>& heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

void displayHeap(vector<int>& heap) {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void siftUp(vector<int>& heap, int n) {
    while (n > 0 && heap[n] > heap[(n - 1) / 2]) {
        swap(heap[n], heap[(n - 1) / 2]);
        n = (n - 1) / 2;
    }
}

void insert(vector<int>& heap, int n) {
    heap.push_back(n);
    siftUp(heap, heap.size() - 1);
}

void deleteMax(vector<int>&heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heapify(heap,0);
}
int main(){
   vector<int>heap;
     insert(heap,1);
     insert(heap,2);
     insert(heap,3);
     insert(heap,4);
     insert(heap,5);
     deleteMax(heap);
     displayHeap(heap);  
}