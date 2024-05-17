#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *left, *right;
};

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d-> ", root->item);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d-> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d-> ", root->item);
}

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}

struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}

int main()
{
    struct node *root = createNode(1);

    insertLeft(root, 5);
    insertRight(root, 2);

    insertLeft(root->left, 4);
    insertRight(root->left, 9);

    insertLeft(root->right, 15);
    insertRight(root->right, 11);

    printf("Inorder Traversal: \n");
    inorderTraversal(root);

    printf("\n\nPreorder Traversal: \n");
    preorderTraversal(root);

    printf("\n\nPostorder Traversal: \n");
    postorderTraversal(root);

    return 0;
}
