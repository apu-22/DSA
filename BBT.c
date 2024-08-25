#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tree node structure
struct Node {
    int key;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Utility function to get the height of the tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

// Function to check if the tree is balanced
bool isBalanced(struct Node* root) {
    if (root == NULL)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main() {
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);

    if (isBalanced(root))
        printf("The tree is balanced\n");
    else
        printf("The tree is not balanced\n");

    return 0;
}
