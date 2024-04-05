#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "node.h"

Node* new_node(int value);
void bst_display(Node* root);
int bst_search(Node* root, int value);
Node* bst_insert(Node* root, int value);
int successor(Node* root);
int predecessor(Node* root);
Node* bst_delete(Node* root, int value);

#endif