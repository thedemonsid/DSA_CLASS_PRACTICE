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

int deleteMax(vector<int>&heap){
    int n=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    heapify(heap,0);
    return n;
}
void heapSort(vector<int>heap){
    while(!empty(heap)){
        cout<<deleteMax(heap)<<" ";
    }
    cout<<endl;
}
int main(){
   vector<int>heap;
     insert(heap,1);
     insert(heap,22);
     insert(heap,13);
     insert(heap,42);
     insert(heap,5);
     displayHeap(heap); 
     heapSort(heap); 
}