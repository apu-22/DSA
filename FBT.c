#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int item;
    struct node *left, *right;
};

// void inorderTraversal(struct node *root)
// {
//     if (root == NULL)
//         return;

//     inorderTraversal(root->left);
//     printf("%d-> ", root->item);
//     inorderTraversal(root->right);
// }

// void preorderTraversal(struct node *root)
// {
//     if (root == NULL)
//         return;

//     printf("%d-> ", root->item);
//     preorderTraversal(root->left);
//     preorderTraversal(root->right);
// }

// void postorderTraversal(struct node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     postorderTraversal(root->left);
//     postorderTraversal(root->right);
//     printf("%d-> ", root->item);
// }

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

bool isBinaryTreeFull(struct node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left == NULL && root->right == NULL)
    {
        /* code */ return true;
    }

    if (root->left != NULL && root->right != NULL)
    
        return isBinaryTreeFull(root->left) && isBinaryTreeFull(root->right);
    

    return false;
}

int main()
{
    struct node *root = createNode(1);

    root->left = createNode(3);
    root->right = createNode(5);
    root->left->left = createNode(8);
    root->left->right = createNode(9);
    root->left->left->left = createNode(2);
    root->left->left->right = createNode(2);

    // printf("Inorder Traversal: \n");
    // inorderTraversal(root);

    // printf("\n\nPreorder Traversal: \n");
    // preorderTraversal(root);

    // printf("\n\nPostorder Traversal: \n");
    // postorderTraversal(root);

    if (isBinaryTreeFull(root))
    {
        printf("the tree is full binary tree.");
    }
    else
    {
        printf("the tree is not full binary tree.");
    }
}
