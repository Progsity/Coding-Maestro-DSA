#include<bits/stdc++.h>
using namespace std;

// c++
struct Node{
	int data;
	struct Node *left, *right;
	Node(int data){
		this -> data = data;
		left = NULL;
		right = NULL;
	}
};

typedef struct Node sn;

void preorderTraversal(sn *node)
{
	if (node == NULL)
		return;

	printf("%d -> ", node->data);
	preorderTraversal(node->left);
	preorderTraversal(node->right);
}

void postorderTraversal(sn *node)
{
	if (node == NULL)
		return;

	postorderTraversal(node->left);
	postorderTraversal(node->right);
	printf("%d -> ", node->data);

}
void inorderTraversal(sn *node)
{
	if (node == NULL)
		return;

	inorderTraversal(node->left);
	printf("%d -> ", node->data);
	inorderTraversal(node->right);
}

int main()
{
	sn *root = new Node(1);
	root -> left = new Node(3);
	root -> right = new Node(2);
	root -> left -> left = new Node(5);
	root -> left -> right = new Node(6);
	root -> right -> left = new Node(4);

	printf("Pre-order Traversal: \n");
	preorderTraversal(root);

	printf("In Order Traversal:\n");
	inorderTraversal(root);

	printf("Post Order Traversal:\n");
	postorderTraversal(root);

	return 0;
}

// c
// struct Node {
//     int data;
//     Node *left;
//     Node *right;
// };
