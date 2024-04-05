#include "bst.h"

Node* new_node(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void bst_display(Node* root)
{
    if(root != NULL)
    {
        bst_display(root->left);
        printf("%d ", root->value);
        bst_display(root->right);
    }
}

int bst_search(Node* root, int value)
{
    if(root == NULL)
        return 0;

    else if(root->value == value)
        return 1;

    else if(root->value > value)
        return bst_search(root->left, value);

    else
        return bst_search(root->right, value);
}

Node* bst_insert(Node* root, int value)
{
    if(root == NULL)
    {
        root = new_node(value);
        return root;
    }

    if(value < root->value)
        root->left = bst_insert(root->left, value);

    else
        root->right = bst_insert(root->right, value);
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

Node* bst_delete(Node* root, int value)
{
    if(root == NULL)
        return root;

    else if(value < root->value)
        root->left = bst_delete(root->left, value);

    else if(value > root->value)
        root->right = bst_delete(root->right, value);

    else
    {
        if(root->left == NULL && root->right == NULL)
            root = NULL;

        else if(root->right != NULL)
        {
            root->value = successor(root);
            root->right = bst_delete(root->right, root->value);
        }

        else
        {
            root->value = predecessor(root);
            root->left = bst_delete(root->left, root->value);
        }
    }
}