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


bool search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key > root->key)
        return search(root->right, key);
    return search(root->left, key);
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
    root->left->right->left = newNode(4);

    int key = 4;
    // struct Node *result = search(root, key);
    // if(result!=NULL){
    //     printf("Found %d in the BST\n", key);
    // }
    // else
    // {
    //     printf("%d not found in the BST\n", key);
    // }
    
    if (search(root,key))
    {
        printf("Found %d in the BST\n", key);
    }
    else
    {
        printf("%d not found in the BST\n", key);
    }

    return 0;
}
