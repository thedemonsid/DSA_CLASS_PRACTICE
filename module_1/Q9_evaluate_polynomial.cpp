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

/*
This function efficiently maintains a sorted linked list representing
 a polynomial, ensuring that nodes with the same exponent are combined
  by adding their coefficients. The time complexity is determined by the
   traversal of the linked list, which is O(n) in the worst case, where
    n is the number of nodes in the list.
*/


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

/*
This function, named add, takes two linked lists representing polynomials
 (head1 and head2). It iterates through the second polynomial (head2), 
 and for each term, it adds or updates the corresponding term in the
  first polynomial (head1) using the addElement function. Finally, it 
  returns the modified head1. The purpose is to add the terms of the 
  second polynomial to the first polynomial
*/


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
This function, named derivative, takes a linked list representing
 a polynomial (head). It iterates through each term in the polynomial
  and computes the derivative by updating the coefficient and exponent 
  of each term accordingly. The coefficient is multiplied by the exponent,
   and the exponent is then decremented by 1. The modified linked list is 
   returned, representing the derivative of the original polynomial.
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

/*
This function, named multiply, takes two linked lists representing polynomials
 (head1 and head2). It multiplies each term of the first polynomial with each
  term of the second polynomial, and the results are added or updated in a new
   linked list (head3). The addElement function is used to handle the addition
    or updating of terms in the result polynomial. Finally, the function returns
     the linked list representing the product of the two input polynomials.
*/


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
//function to evaluate the polynomial
long long int evaluate(node *head){
    node* curr = head;
    long long int sum =0;
    while(curr!=NULL){
        sum+=(pow(curr->coef,curr->exp));
        curr=curr->next;
    }
    return sum;
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
addElement(p1,1,4);
addElement(p1,4,1);
addElement(p1,6,2);
display(p1);
cout<<evaluate(p1)<<endl;
}