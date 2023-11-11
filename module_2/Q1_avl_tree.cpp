#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    int height;
};
//function to return height
int height(node*a){
   if(a==NULL)return -1;
   else return a->height;
}
//function to calculate balance factor
int balance_factor(node*a){
    if(a==NULL)return 0;
    return height(a->left)-height(a->right);
}

int main()
{
}