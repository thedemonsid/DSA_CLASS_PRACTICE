/*
Create a linked list with the given set of integer sequence. A K value would be given to you
to apply K-Zigzag folds of the linked list. In each fold you have to divide nodes in equal
numbers. Whenever you fold, take the product of values for the nodes which are overlapping
with each other and print the resultant linked list.
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x = 0)
    {
        data = x;
        next = NULL;
    }
};
// function to insert at end of linked list

/*
This function inserts a new node with a given value at the 
end of a linked list. It first creates a new node, then checks
 if the list is empty. If it's empty, the new node becomes the
  head. If not, it traverses to the current end of the list
   and appends the new node there.
*/


void insertAtEnd(node *&head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
}
// function to display linked list

/*
This function displays the elements of a linked list.
 It starts from the head of the list and iterates
  through each node, printing the data contained in
   each node, separated by a space. Once it reaches
    the end of the list (where the node points to NULL),
     it prints a new line to end the display.
*/

void display(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
// function to know size of linked list

/*
This function computes the size of a linked list by iterating 
through the nodes, counting each node encountered, and returning
 the total count of nodes in the list. It's quite similar to the 
 previous 'size' function, iterating through the list and
  incrementing a counter for each node found.
*/

int size(node *head)
{
    int count = 0;
    node *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// function to fold in zigzag way
node *zigzagFold(node *&head, int n)
{
    vector<int> fold;
    /*
    ##1
    The zigzagFold function takes a linked list head and an integer n as input.
    It then creates a vector fold and pushes the first n elements of the linked list 
    into it.

    ##2
    After that, it sets a pointer curr to the current head of the linked list. 
    Finally, it loops through the fold vector in reverse order and inserts the elements 
    into the linked list in a zigzag manner.The zigzagFold function takes a linked list head 
    and an integer n as input. 

    ##3
    It then creates a vector fold and pushes the first n elements of the linked list into it. 
    After that, it sets a pointer curr to the current head of the linked list. 
    
    ##4
    Finally, it loops through the fold vector in reverse order and inserts the elements into the 
    linked list in a zigzag manner.
    */
    for(int i=0;i<n;i++)
    {
        fold.push_back(head->data);
        head = head->next;
    }
    
    node *curr = head;
    for (int i = fold.size()-1; i >= 0; i--)
    {
        curr->data *= fold[i];
        curr = curr->next;
    }
    return head;
}
int main()
{
    cout << "Number of nodes and number of folds: ";
    int n, k;
    cin >> n >> k;
    cout << "Numbers: ";
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    node *head = new node(a[0]);
    for (int i = 1; i < n; i++)
    {
        insertAtEnd(head, a[i]);
    }
    display(head);
    int r = size(head) / k;
    for (int i = 0; i < k-1; i++)
    {
        head = zigzagFold(head, r);
    }
    display(head);
}