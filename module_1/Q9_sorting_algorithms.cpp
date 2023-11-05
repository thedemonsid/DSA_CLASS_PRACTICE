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
void insertion_sort(int a[],int n){
   for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i])swap(a[i],a[j]);
        }
   }
cout<<endl;
}
//function to bubble sort
void bubble_sort(int  a[],int n){
   for(int j=0;j<n-1;j++){
    for(int i=0;i<n-j-1;i++){
        if(a[i]>a[i+1])swap(a[i],a[i+1]);
    }
   }
   cout<<endl;
}
//function to selection sort
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
//merge function using maps nlog(n) time complexity
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


int main(){
  testMerge();
  testMergeMaps();
}