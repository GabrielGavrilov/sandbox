#include "bst.h"

int main(int argc, const char* argv[])
{
    Node* root = new_node(8);

    bst_insert(root, 9);
    bst_insert(root, 4);
    bst_insert(root, 6);
    bst_insert(root, 2);
    bst_insert(root, 1);
    bst_insert(root, 3);
    bst_insert(root, 7);
    bst_insert(root, 5);

    bst_display(root);
    printf("\n%d\n", bst_search(root, 5));

    bst_delete(root, 6);
    bst_delete(root, 5);

    bst_display(root);
    printf("\n%d\n", bst_search(root, 5));

    return 0;
}