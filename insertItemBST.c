#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tree node structure
struct Node
{
    int key;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int item)
{
    if (root == NULL)
        return newNode(item);

    if (item < root->key)
        root->left = insert(root->left,item);
    if (item > root->key)
        root->right = insert(root->right,item);

    return root;
}

void inOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d-> ", root->key);
    inOrderTraversal(root->right);
}

int main()
{
    struct Node *root = NULL;
    root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->left = newNode(9);

    printf("Inorder traversal before insert item:\n");
    inOrderTraversal(root);

    insert(root, 4);

    printf("\n\nInorder traversal after insert item:\n");
    inOrderTraversal(root);

    return 0;
}
