#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct Node* insert(struct Node* root, int value) {

    if (root == NULL) {
        return createNode(value);
    }
    // Smaller values go to left
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Greater values go to right
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Duplicate value
    else {
        printf("Duplicate value not allowed!\n");
    }

    return root;
}
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
// Delete a node from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Value %d not found!\n", value);
        return root;
    }
    // Search in left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    // Search in right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // Node found
    else {
        // CASE 1: Node has no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // CASE 2: Node has only right child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        // CASE 2: Node has only left child
        else if (root->right == NULL) {
            struct Node* temp = root->left;

            free(root);

            return temp;
        }
        // CASE 3: Node has two children
        else {
            // Find inorder successor
            struct Node* temp = findMin(root->right);
            // Copy successor's value
            root->data = temp->data;
            // Delete successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {

        inorder(root->left);
        printf("%d ", root->data);

        inorder(root->right);
    }
}
// Preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {

        postorder(root->left);
        postorder(root->right);

        printf("%d ", root->data);
    }
}
// Main function
int main() {

    struct Node* root = NULL;

    int choice, value, n, i;

    while (1) {

        printf("\n\n----- BINARY SEARCH TREE-----\n");

        printf("1. Create BST\n");
        printf("2. Insert Node\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter number of nodes: ");
                scanf("%d", &n);
                root = NULL;
                printf("Enter %d values:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                printf("BST created successfully!\n");
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Node inserted successfully!\n");
                break;

            case 3:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                break;

            case 4:

                printf("Inorder Traversal: ");

                inorder(root);

                printf("\n");

                break;

            case 5:

                printf("Preorder Traversal: ");

                preorder(root);

                printf("\n");

                break;

            case 6:

                printf("Postorder Traversal: ");

                postorder(root);

                printf("\n");

                break;

            case 7:

                printf("Program terminated.\n");

                exit(0);

            default:

                printf("Invalid choice!\n");
        }
    }

    return 0;
}