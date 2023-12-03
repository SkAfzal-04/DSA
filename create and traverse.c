#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to traverse the tree recursively using a switch statement
void traverseTree(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);

        // Choose the traversal order using a switch statement
        int choice;
        printf("\nEnter traversal choice (1: Preorder, 2: Inorder, 3: Postorder): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverseTree(root->left);
                traverseTree(root->right);
                break;
            case 2:
                traverseTree(root->left);
                printf("%d ", root->data);
                traverseTree(root->right);
                break;
            case 3:
                traverseTree(root->left);
                traverseTree(root->right);
                printf("%d ", root->data);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}

// Function to free the allocated memory of the tree
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes into the tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Traverse the tree
    traverseTree(root);

    // Free the allocated memory
    freeTree(root);

    return 0;
}

