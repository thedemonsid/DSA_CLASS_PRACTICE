#include<bits/stdc++.h>
using namespace std;
struct node{
    int coef;
    int exp;
    node * next;
   node(int x=0,int y=0){
      coef=x;
      exp=y;
      next=NULL;
   }
};
// Adding new elements to node
/*In simple terms, this function adds a new node to a linked list in a way that maintains 
the list in sorted order based on the exponents. If a node with the same exponent already exists,
 it combines their coefficients.*/
void addElement(node* &head, int coef, int exp) {
    node* newNode = new node(coef, exp);
    if (head == NULL) {
        head = newNode;
    } 
    else if(head->exp==exp){
        head->coef+=coef;
    }
        
    else {
        node* curr = head;
        if(curr->exp<exp){
            newNode->next=curr;
            head=newNode;
        }
        else{
       while (curr->next != NULL && curr->next->exp >exp) {
            curr = curr->next;
        }
        if(curr->next!=NULL&&curr->next->exp==exp){
            curr->next->coef+=coef;
            return;
        }else{
            newNode->next=curr->next;
            curr->next = newNode;
        }
        
        }
       
    }
}
//function to add two polynomials
/* In simple terms, this function combines the nodes from the second linked list (head2) 
into the first linked list (head1) by adding nodes with the same exponent and inserting 
new nodes in the correct sorted position based on exponent.*/
node* add(node* head1, node* head2) {
    node* curr1 = head1;
    node* curr2 = head2;
    while(curr2!=NULL){
        addElement(head1,curr2->coef,curr2->exp);
        curr2=curr2->next;
    }
    return head1;
}
//function to derive derivative of polynomial
/*
this function calculates the derivative of a polynomial represented by a linked list. 
It applies the power rule of differentiation to each term in the polynomial.
*/
node* derivative(node* head) {
    node* curr = head;
    while (curr != NULL) {
        curr->coef = curr->coef * curr->exp;
        curr->exp = curr->exp - 1;
        curr = curr->next;
    }
    return head;
}
//function to multiply two polynomials
node* multiply(node* head1, node* head2) {
    node* curr1 = head1;
    node* curr2 = head2;
    node* head3 = NULL;
    while (curr1 != NULL) {
        while (curr2 != NULL) {
            addElement(head3, curr1->coef * curr2->coef, curr1->exp + curr2->exp);
            curr2 = curr2->next;
        }
        curr2 = head2;
        curr1 = curr1->next;
    }
    return head3;
}
//function to display linked list
void display(node* head) {
    node* curr = head;
    while (curr != NULL) {
        if (curr->coef != 0) {
            cout << curr->coef << "x^" << curr->exp;
            if (curr->next != NULL && curr->next->coef > 0) {
                cout << " + ";
            } else if (curr->next != NULL && curr->next->coef < 0) {
                cout << " - ";
            }
        }
        curr = curr->next;
    }
    cout << endl;
}
int main(){
node * p1 = new node(2,3);
addElement(p1,23,4);
addElement(p1,45,1);
addElement(p1,56,2);
display(p1);
node * p2 = new node(2,3);
addElement(p2,23,4);
addElement(p2,45,5);
addElement(p2,56,3);
display(p2);

node * p3 = add(p1,p2);
display(p3);
p3=multiply(p1,p2);
display(p3);
}