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
        display(a,n);
   }
cout<<endl;
}
//function to bubble sort
void bubble_sort(int  a[],int n){
   for(int j=0;j<n-1;j++){
    for(int i=0;i<n-j-1;i++){
        if(a[i]>a[i+1])swap(a[i],a[i+1]);
    }
    display(a,n);
   }
   cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    int a[n];
    cout<<"Enter the numbers : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    insertion_sort(a,n);

}