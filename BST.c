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

int sumBST(struct Node *root)
{
    if (root == NULL)
        return 0;

    return root->key + sumBST(root->left) + sumBST(root->right);
}

bool search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (key > root->key)
        return search(root->right, key);
    return search(root->left, key);
}

struct Node *insert(struct Node *root, int item)
{
    if (root == NULL)
        return newNode(item);

    if (item < root->key)
    {
        root->left = insert(root->left, item);
    }
    if (item > root->key)
    {
        root->right = insert(root->right, item);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(8);
    insert(root, 9);
    insert(root, 18);
    insert(root, 3);
    insert(root, 23);
    insert(root, 6);
    insert(root, 25);

    int key = 4;
    // struct Node *result = search(root, key);
    // if(result!=NULL){
    //     printf("Found %d in the BST\n", key);
    // }
    // else
    // {
    //     printf("%d not found in the BST\n", key);
    // }

    if (search(root, key))
    {
        printf("Found %d in the BST\n", key);
    }
    else
    {
        printf("%d not found in the BST\n", key);
    }

    int sum = sumBST(root);
    printf("SUM is: %d\n", sum);

    return 0;
}
