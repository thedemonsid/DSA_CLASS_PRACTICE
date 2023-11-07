#include<bits/stdc++.h>
using namespace std;

// Define a structure to represent a hash table node.
struct hash_table {
    int key;
    int value;
    hash_table* next;

    // Constructor to initialize a hash table node with key, value, and next pointer.
    hash_table(int k, int v) {
        key = k;
        value = v;
        next = NULL;
    }
};

// Function to insert a new element into the hash table.
void insert(hash_table* &head, int key, int value) {
    // Create a new node with the provided key and value.
    hash_table* temp = new hash_table(key, value);
    
    // Make the new node point to the current head of the linked list.
    temp->next = head;
    
    // Update the head of the linked list to be the new node.
    head = temp;
}

// Function to search for a specific key in the hash table and return its associated value.
int search(hash_table* head, int key) {
    hash_table* temp = head;
    while (temp) {
        // If the current node's key matches the target key, return its value.
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    // If the key is not found, return -1 to indicate that it doesn't exist in the hash table.
    return -1;
}

// Function to display the contents of the hash table.
void display(hash_table* head) {
    hash_table* temp = head;
    while (temp) {
        // Print the key and value of each node in the linked list.
        cout << temp->key << " " << temp->value << endl;
        temp = temp->next;
    }
}

int main() {
    // Create an initial hash table node with key 1 and value 2.
    hash_table* head = new hash_table(1, 2);
    
    // Insert additional key-value pairs into the hash table.
    insert(head, 2, 3);
    insert(head, 3, 4);
    insert(head, 4, 5);
    
    // Display the contents of the hash table.
    display(head);

    // Search for a key (e.g., key 3) in the hash table and print its associated value.
    cout << search(head, 3) << endl;
}