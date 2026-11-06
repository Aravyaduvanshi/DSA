#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

/* Create Binary Tree */
struct Node* createTree() {

    int value;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    printf("Enter left child of %d:\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = createTree();

    return newNode;
}

/* Preorder */
void preorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);

    preorder(root->left);

    preorder(root->right);
}

/* Inorder */
void inorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

/* Postorder */
void postorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);
}

int main() {

    struct Node *root = NULL;
    int choice;

    printf("....BINARY TREE.... \n");

    printf("\nCreate the tree:\n");

    root = createTree();

    do {

        printf("\n\n----TREE MENU--- \n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nPreorder: ");
                preorder(root);
                break;

            case 2:
                printf("\nInorder: ");
                inorder(root);
                break;

            case 3:
                printf("\nPostorder: ");
                postorder(root);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}