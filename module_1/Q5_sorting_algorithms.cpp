#include<bits/stdc++.h>
using namespace std;

//function to display array
void display(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//insertion sort

/*
The key idea behind Insertion Sort is to build the sorted portion of the array
 one element at a time by inserting each element into its correct position 
 within the sorted part of the array.
*/

 
 
void insertion_sort(int a[],int n){
   for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i])swap(a[i],a[j]);
        }
   }
cout<<endl;
}

//function to bubble sort

/*
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list,
 compares adjacent elements, and swaps them if they are in the wrong order.
 The algorithm gets its name because smaller elements "bubble" to the top of
  the array with each pass. However, it is not the most efficient sorting
   algorithm, especially for large datasets, as it has a time complexity
    of O(n^2) in the worst case.
*/


void bubble_sort(int  a[],int n){
   for(int j=0;j<n-1;j++){
    for(int i=0;i<n-j-1;i++){
        if(a[i]>a[i+1])swap(a[i],a[i+1]);
    }
   }
   cout<<endl;
}

//function to selection sort

/*
Selection Sort works by dividing the array into a sorted and an 
unsorted region. In each iteration of the outer loop, it finds
 the minimum element in the unsorted region and swaps it with
  the first element of the unsorted region, expanding the
   sorted region. The time complexity of Selection Sort is
    O(n^2), making it inefficient for large datasets.
*/


void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
    cout << endl;
}

// cpmpare function for custom made stl sort
bool compare(int a, int b) {
    //for descending order
    return a > b;
}

//function to merge two sorted arrays

/*
This function efficiently merges two sorted arrays into a single
 sorted array, which is a crucial step in the Merge Sort algorithm.
  The time complexity of the merging step is O(a1 + b1),
   where a1 and b1 are the sizes of arrays a and b, respectively.
*/


int * merge(int *a,int a1,int *b,int b1){
    int i=0,j=0,k=0;
    int *ans=new int[a1+b1];
    while(i<a1&&j<b1){
       if(a[i]<=b[j]){
        ans[k]=a[i];
        i++;
        k++;
       }
       else{
        ans[k]=b[j];
        j++;
        k++;
       }
    }
    for(i;i<a1;i++){
        ans[k]=a[i];
        k++;
    }
    for(j;j<b1;j++){
        ans[k]=b[j];
        k++;
    }
    return ans;
}

//merge function using maps nlog(n) time complexity

/*
This function effectively combines the unique elements of two 
arrays using a map to ensure that each element appears only once
 in the merged array. The time complexity of this function 
 is O(a1 + b1) due to the iteration over the elements of both arrays.
*/

int * merge_maps(int a[],int a1,int b[],int b1){
    map<int,bool>mp;
    for(int i=0;i<a1;i++){
       mp[a[i]]=true;
    }
    for(int i=0;i<b1;i++){
       mp[b[i]]=true;
    }
    int *ans=new int[a1+b1];
    int i=0;
    for(auto & str : mp){
        ans[i++]= str.first;
    }
    return ans;
}
//function to merge the array for mergeSort

/*
This function efficiently merges two sorted subarrays into a
 single sorted array, which is a crucial step in the Merge
  Sort algorithm. The time complexity of the merging step is
   O(n), where n is the total number of elements being merged.
*/


void merge(int *arr,int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i] = arr[m+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

//functoin for merge sort

/*
Merge Sort divides the array into smaller subarrays, sorts them independently,
 and then merges them to achieve a fully sorted array. The time complexity
  of Merge Sort is O(n log n), where n is the number of elements in the array,
   making it a highly efficient sorting algorithm for large datasets.
*/


void mergeSort(int *arr,int l,int r){
    if(l<r){
     int m = (l+r)/2;
     mergeSort(arr,l,m);
     mergeSort(arr,m+1,r);
     merge(arr,l,m,r);
    }
}

//function for countSort

/*
Counting Sort is a non-comparative sorting algorithm that works well 
when the range of numbers (difference between the maximum and minimum values) 
is not significantly greater than the number of elements to be sorted.
 The time complexity of Counting Sort is O(n + k), where n is the number
  of elements in the input array and k is the range of input values.
*/


void countSort(int arr[], int n) {
    int max = *max_element(arr, arr+n);
    int countArr[max+1] = {0};

    for(int i = 0; i < n; i++)
        countArr[arr[i]]++;

    for(int i = 1; i <= max; i++)
        countArr[i] += countArr[i-1];

    int output[n];
    for(int i = n-1; i >= 0; i--) {
        output[countArr[arr[i]]-1] = arr[i];
        countArr[arr[i]]--;
    }

    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

//function to find maximum number in array

/*
This function efficiently determines the maximum value in an array 
by comparing each element to the current maximum, updating it if
 a larger element is found. The time complexity of this function
  is O(n), where n is the number of elements in the array.
*/


int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//function for radix sort

/*
The overall idea of Radix Sort is to sort numbers based on individual
 digits, starting from the least significant digit and moving towards
  the most significant digit. This process ensures that the numbers 
  are sorted in each pass and eventually results in a fully sorted
   array. The time complexity of Radix Sort is O(d * (n + k)), 
   where d is the number of digits, n is the number of elements,
 and k is the base of the number system (usually 10 for decimal numbers).
*/

void radixSort(int arr[],int n){
    int mx = findMax(arr,n);
    for(int i=0;i<mx;i++){
        vector<vector<int>>bucket(10);
        for(int j=0;j<n;j++){
            bucket[(int)(arr[j]/pow(10,i))%10].push_back(arr[j]);    
        }
        int k = 0;
        for(int j=0;j<10;j++){
            for(int l=0;l<bucket[j].size();l++){
                arr[k++] = bucket[j][l];
            }
        }
    }
}

/*<------------------------------------------------------------------------------>*/


// Test cases for radixSort function
void testRadixSort() {
    // Test case 1
    {
        int arr[8] = {170, 45, 75, 90, 802, 24, 2, 66};
        int sorted[8] = {2, 24, 45, 66, 75, 90, 170, 802};
        radixSort(arr, 8);
        for (int i = 0; i < 8; i++) {
            assert(arr[i] == sorted[i]);
        }
    }

    // Test case 2
    {
        int arr[5] = {5, 3, 2, 1, 4};
        int sorted[5] = {1, 2, 3, 4, 5};
        radixSort(arr, 5);
        for (int i = 0; i < 5; i++) {
            assert(arr[i] == sorted[i]);
        }
    }

    // Test case 3
    {
        int arr[3] = {3, 2, 1};
        int sorted[3] = {1, 2, 3};
        radixSort(arr, 3);
        for (int i = 0; i < 3; i++) {
            assert(arr[i] == sorted[i]);
        }
    }

    cout << "All test cases passed for radixSort.\n";
}

//Test cases for merge function
void testMerge() {
    // Test case 1
    {
        int a[5] = {1, 2, 3, 4, 5};
        int b[5] = {6, 7, 8, 9, 10};
        int* merged = merge(a, 5, b, 5);
        for (int i = 0; i < 10; i++) {
            assert(merged[i] == i + 1);
        }
        delete[] merged;
    }

    // Test case 2
    {
        int a[3] = {1, 3, 5};
        int b[3] = {2, 4, 6};
        int* merged = merge(a, 3, b, 3);
        for (int i = 0; i < 6; i++) {
            assert(merged[i] == i + 1);
        }
        delete[] merged;
    }

    // Test case 3
    {
        int a[0] = {};
        int b[3] = {1, 2, 3};
        int* merged = merge(a, 0, b, 3);
        for (int i = 0; i < 3; i++) {
            assert(merged[i] == i + 1);
        }
        delete[] merged;
    }
      cout << "All test cases passed for merge.\n";
}

//function to test merge_maps function
void testMergeMaps() {
    // Test case 1
    {
        int a[5] = {1, 2, 3, 4, 5};
        int b[5] = {3, 4, 5, 6, 7};
        int* merged = merge_maps(a, 5, b, 5);
        int expected[7] = {1, 2, 3, 4, 5, 6, 7};
        for (int i = 0; i < 7; i++) {
            assert(merged[i] == expected[i]);
        }
        delete[] merged;
    }

    // Test case 2
    {
        int a[3] = {1, 3, 5};
        int b[3] = {2, 4, 6};
        int* merged = merge_maps(a, 3, b, 3);
        int expected[6] = {1, 2, 3, 4, 5, 6};
        for (int i = 0; i < 6; i++) {
            assert(merged[i] == expected[i]);
        }
        delete[] merged;
    }

    // Test case 3
    {
        int a[0] = {};
        int b[3] = {1, 2, 3};
        int* merged = merge_maps(a, 0, b, 3);
        int expected[3] = {1, 2, 3};
        for (int i = 0; i < 3; i++) {
            assert(merged[i] == expected[i]);
        }
        delete[] merged;
    }

    cout << "All test cases passed for merge_maps.\n";
}

// Test function for insertion sort
void testInsertionSort() {
    // Test case 1
    {
        int a[5] = {5, 4, 3, 2, 1};
        insertion_sort(a, 5);
        for (int i = 0; i < 5; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 2
    {
        int a[3] = {3, 1, 2};
        insertion_sort(a, 3);
        for (int i = 0; i < 3; i++) {
            assert(a[i] == i + 1);
        }
    }
    cout << "All test cases passed for insertion_sort.\n";
}

// Test function for bubble sort
void testBubbleSort() {
    // Test case 1
    {
        int a[5] = {5, 4, 3, 2, 1};
        bubble_sort(a, 5);
        for (int i = 0; i < 5; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 2
    {
        int a[3] = {3, 1, 2};
        bubble_sort(a, 3);
        for (int i = 0; i < 3; i++) {
            assert(a[i] == i + 1);
        }
    }
    cout << "All test cases passed for bubble_sort.\n";
}

// Test function for merge sort
void testMergeSort() {
    // Test case 1
    {
        int a[5] = {5, 4, 3, 2, 1};
        mergeSort(a, 0, 4);
        for (int i = 0; i < 5; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 2
    {
        int a[3] = {3, 1, 2};
        mergeSort(a, 0, 2);
        for (int i = 0; i < 3; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 3
    {
        int a[6] = {100, 200, 300, 400, 500, 600};
        mergeSort(a, 0, 5);
        for (int i = 0; i < 6; i++) {
            assert(a[i] == (i+1)*100);
        }
    }

    cout << "All test cases passed for mergeSort.\n";
}

// Test function for selection sort
void testSelectionSort() {
    // Test case 1
    {
        int a[5] = {5, 4, 3, 2, 1};
        selection_sort(a, 5);
        for (int i = 0; i < 5; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 2
    {
        int a[3] = {3, 1, 2};
        selection_sort(a, 3);
        for (int i = 0; i < 3; i++) {
            assert(a[i] == i + 1);
        }
    }
    cout << "All test cases passed for selection_sort.\n";
}

//test cases for countSort
void testCountSort() {
    // Test case 1
    {
        int a[5] = {5, 4, 3, 2, 1};
        countSort(a, 5);
        for (int i = 0; i < 5; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 2
    {
        int a[3] = {3, 1, 2};
        countSort(a, 3);
        for (int i = 0; i < 3; i++) {
            assert(a[i] == i + 1);
        }
    }

    // Test case 3
    {
        int a[6] = {100, 200, 300, 400, 500, 600};
        countSort(a, 6);
        for (int i = 0; i < 6; i++) {
            assert(a[i] == (i+1)*100);
        }
    }

    cout << "All test cases passed for countSort.\n";
}

int main(){
 testRadixSort();
 testBubbleSort();
 testCountSort();
 testInsertionSort();
 testMerge();
 testMergeMaps();
 testMergeSort();
 testSelectionSort(); 
}