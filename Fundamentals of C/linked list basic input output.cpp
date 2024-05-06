#include<bits/stdc++.h>
using namespace std;

// Define the Node struct
struct Node {
    int data;
    Node* next;
};
Node *root = nullptr;
void add_node(int data)
{
	if(root == nullptr) // if the whole list is empty
	{
		root = new Node();
		root->data = data;
		root -> next = nullptr;
	}
	else
	{
		Node *current_node = root;
		while(current_node -> next != nullptr)
		{
			current_node = current_node -> next;
		}
		Node *new_node = new Node();
		new_node->data =  data;
		new_node->next = nullptr;

		current_node->next = new_node;
	}
}
void delete_node(int data)
 {
 	Node *current_node = root;
 	Node *previous_node = nullptr;
 	while(current_node -> data != data)
 	{
 		previous_node = current_node;
 		current_node = current_node->next;
 	}
 	if(current_node == root) // to delete the node
 	{
 		Node *temp = root; //keep root in a temp node
 		root = root->next;
 		delete(temp); //free memory
 	}
 	else // to delete the non-root node/others node
 	{
 		previous_node->next = current_node -> next;
 		delete(current_node);
 	}
 }

int main()
{
	int node_data[5] = {1, 2, 4, 6, 8};
	for (int i = 0; i < 5; ++i)
	{
		add_node(node_data[i]);
	}
	delete_node(node_data[2]);
	printf("Data of each nodes: \n");
	Node *current_node = root;
	while(current_node != nullptr)
	{
		printf("%d ", current_node->data);
		current_node = current_node->next;
	}
	return 0;
}
