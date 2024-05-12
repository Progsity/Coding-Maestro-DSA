#include<bits/stdc++.h>
using namespace std;

// Define the Node struct for a doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* root = nullptr;

// Function to add a node at the end of the doubly linked list
void add_node(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (root == nullptr) {
        root = new_node;
    } 
    else {
        Node* current_node = root;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        new_node->prev = current_node;
    }
}

// Function to insert a node at a specific index
void insert_node(int index, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    if (index == 0) {
        new_node->next = root;
        if (root != nullptr) {
            root->prev = new_node;
        }
        root = new_node;
    } else {
        Node* current = root;
        for (int i = 0; i < index && current != nullptr; ++i) {
            current = current->next;
        }
        if (current != nullptr) {
            new_node->next = current;
            new_node->prev = current->prev;
            if (current->prev != nullptr) {
                current->prev->next = new_node;
            }
            current->prev = new_node;
        } else {
            cout << "Index is out of bounds" << endl;
            delete new_node; // Clean up the allocated node
        }
    }
}



// Function to delete a node from the list
void delete_node(int data) {
    Node* current = root;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }
    if (current != nullptr) {
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            root = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

// Function to print the list from start to end
void print_forward() {
    Node* current = root;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void print_backward(Node* node) {
    if (node != nullptr) {
        print_backward(node->next);
        cout << node->data << " ";
    }
}


int main() {
    int node_data[5] = {1, 2, 4, 6, 8};
    for (int data : node_data) {
        add_node(data);
    }

    cout << "Forward Traversal: ";
    print_forward();

    cout << "Backward Traversal: ";
    print_backward(root);
    cout << endl;

    // Insert a node at position 2 with data 5
    insert_node(2, 5);
    cout << "After insertion: ";
    print_forward();

    // Delete a node with data 4
    // delete_node(4);
    // cout << "After deletion: ";
    // print_forward();

    // cout << "Final backward traversal: ";
    // print_backward();
    cout << "After Insert Backward Traversal: ";
    print_backward(root);
    cout << endl;

    return 0;
}
