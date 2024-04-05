#ifndef NODE_H
#define NODE_H

typedef struct NODE_STRUCT Node;

struct NODE_STRUCT
{
    int value;
    Node* left;
    Node* right;
};

#endif