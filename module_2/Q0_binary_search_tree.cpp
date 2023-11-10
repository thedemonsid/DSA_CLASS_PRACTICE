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

/*
This function inserts a new node with a given value into
 a binary search tree. If the tree is empty, it creates
  the node as the root. If not, it traverses the tree,
   placing the node according to the rules of a binary
    search tree: smaller values go to the left, and 
    larger values go to the right.
*/

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

/*
This function navigates to the rightmost (or maximum) node of 
a given subtree within a binary search tree. It keeps moving
 to the right child of each node until it reaches the node with 
 no right child, indicating the maximum value in the subtree.
*/

node *traverse_right(node *curr)
{
    if (curr->right == NULL)
        return curr;
    return traverse_right(curr->right);
}
// Deletion

/*
This function deletes a node with a specified value from
 a binary search tree. It finds the node with the given 
 value, then handles three cases: if the node has no 
 children, if it has one child, or if it has two children.
  It manages node deletion accordingly, adjusting the tree
   structure to maintain the binary search tree properties.
*/


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

/*
This function performs an inorder traversal of a binary search 
tree. It recursively visits the nodes in the tree in the following
 order: left subtree, current node, right subtree. It prints the 
 data of each node in ascending order, following the principles
  of a binary search tree.
*/

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