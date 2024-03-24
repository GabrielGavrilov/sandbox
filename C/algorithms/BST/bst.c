#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct NODE_STRUCT Node;
typedef Node* (*MODIFIER)(Node* root, int value);

struct NODE_STRUCT
{
	int value;
	Node* left;
	Node* right;
};

Node* new_node(int value)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int successor(Node* root)
{
	root = root->right;
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->value;
}

int predecessor(Node* root)
{
	root = root->left;
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root->value;
}

void modify_bst(Node* root, int value, MODIFIER modify)
{
	modify(root, value);
}

Node* insert(Node* root, int value)
{
	if(root == NULL)
	{
		root = new_node(value);
		return root;
	}

	if(value < root->value)
		root->left = insert(root->left, value);

	else if(value > root->value)
		root->right = insert(root->right, value);

	return root;
}

Node* delete(Node* root, int value)
{
	if(root == NULL)
		return root;

	else if(value < root->value)
		root->left = delete(root->left, value);

	else if(value > root->value)
		root->right = delete(root->right, value);

	else
	{
		if(root->left == NULL && root->right == NULL)
		{
			root = NULL;
		}

		else if(root->right != NULL)
		{
			root->value = successor(root);
			root->right = delete(root->right, root->value);
		}

		else
		{
			root->value = predecessor(root);
			root->left = delete(root->left, root->value);
		}
	}
}

int search(Node* root, int value)
{
	if(root == NULL)
		return 0;
	
	else if(root->value == value)
		return 1;

	else if(root->value > value)
		return search(root->right, value);

	else
		return search(root->left, value);
}

void display(Node* root)
{
	if(root != NULL)
	{
		display(root->left);
		printf("%d ", root->value);
		display(root->right);
	}
}

int main()
{
	Node* root = new_node(34);

	modify_bst(root, 8, insert);
	modify_bst(root, 67, insert);
	modify_bst(root, 23, insert);
	modify_bst(root, 63, insert);
	modify_bst(root, 92, insert);
	modify_bst(root, 35, insert);
	modify_bst(root, 2, insert);
	modify_bst(root, 87, insert);

	display(root);
	printf("\n");

	modify_bst(root, 23, delete);
	modify_bst(root, 63, delete);
	modify_bst(root, 35, delete);

	display(root);
	printf("\n");

	return 0;
}