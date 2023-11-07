#include<bits/stdc++.h>
using namespace std;
struct hash_table{
    int key;
    int value;
    hash_table* next;
    hash_table(int k, int v){
        key = k;
        value = v;
        next = NULL;
    }

    
};
//inserting the element in the hash table
void insert(hash_table* &head, int key, int value){
    hash_table* temp = new hash_table(key, value);
    temp->next = head;
    head= temp;
}
//searching the element in the hash table
int search(hash_table* head, int key){
    hash_table* temp = head;
    while(temp){
        if(temp->key == key){
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}
//displaying the hash table
void display(hash_table* head){
    hash_table* temp = head;
    while(temp){
        cout<<temp->key<<" "<<temp->value<<endl;
        temp = temp->next;
    }
}
int main(){
    hash_table* head = new hash_table(1, 2);
    insert(head, 2, 3);
    insert(head, 3, 4);
    insert(head, 4, 5);
    display(head);
    cout<<search(head, 3)<<endl;
       
}