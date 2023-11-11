#include <bits/stdc++.h>
using namespace std;
struct node
{
    vector<int> keys;     // keys in array form
    vector<node *> child; // multiple pointers to different children nodes
    int t;                // minimum order (order/2)
    int no_keys;
    node(int T)
    {
        t = T;
        keys = vector<int>(2 * T - 1);
        child = vector<node *>(2 * T);
        no_keys = 0;
    }
};
int main()
{
    int order;
    cout << "Enter the order of btree";
    cin >> order;
    node *B = new node(order / 2);
}