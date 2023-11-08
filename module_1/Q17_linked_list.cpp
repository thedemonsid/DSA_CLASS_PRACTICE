#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *child;
    node(int x)
    {
        data = x;
        next = NULL;
        child = NULL;
    }
};
void traverse(node *head)
{
    node *temp = head;
    cout << temp->data << " ";
    if (temp->child != NULL)
        traverse(temp->child);
    if (temp->next != NULL)
        traverse(temp->next);
}
int main()
{
    int t = 1;
    while (t--)
    {
        int n;
        cout << "Enter the number of nodes ";
        cin >> n;
        int u[n - 1], v[n - 1], type[n - 1];
        for (int i = 0; i < n - 1; i++)
        {
            cout << i + 1 << ". ";
            cin >> u[i] >> v[i] >> type[i];
        }
        node *head[n];
        for (int i = 0; i < n; i++)
        {
            head[i] = new node(i + 1);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (type[i] == 0)
            {
                head[u[i] - 1]->next = head[v[i] - 1];
            }
            else
            {
                head[u[i] - 1]->child = head[v[i] - 1];
            }
        }
        int sum = n * (n + 1) / 2, s = 0;
        for (int i = 0; i < n - 1; i++)
        {
            s += v[i];
        }
        int start = sum - s - 1;
        traverse(head[start]);
        cout << endl;
    }
}