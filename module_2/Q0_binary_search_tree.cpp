#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int x = -1)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// Insertion
void insert(node *&head, int n)
{
    if (head == NULL)
    {
        head = new node(n);
    }
    else if (n < head->data)
    {
        insert(head->left, n);
    }
    else
    {
        insert(head->right, n);
    }
}
// Traverse Right
node *traverse_right(node *curr)
{
    if (curr->right == NULL)
        return curr;
    return traverse_right(curr->right);
}
// Deletion
void delete_node(node *&root, int key)
{
    if (root == NULL)
        return;
    if (key < root->data)
    {
        delete_node(root->left, key);
    }
    else if (key > root->data)
    {
        delete_node(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            node *temp = traverse_right(root->left);
            root->data = temp->data;
            delete_node(root->left, temp->data);
        }
    }
}
// In-order traversal
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Pre-order traversal
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void search(node *&head, int n)
{
    if (head == NULL)
    {
        cout << "Not found" << endl;
        return;
    }
    if (head->data == n)
    {
        cout << "Present\n";
        return;
    }
    else if (head->data < n)
    {
        search(head->right, n);
    }
    else
    {
        search(head->left, n);
    }
    return;
}
int main()
{
    node *head = new node(5);
    insert(head, 2);
    insert(head, 7);
    insert(head, 3);
    inorder(head);
}