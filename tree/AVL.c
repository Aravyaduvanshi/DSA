#include <stdio.h>
#include <stdlib.h>

// Structure of an AVL Tree node
struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// Get maximum of two numbers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Get height of a node
int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}
// Create a new node
struct Node* createNode(int value)
{
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Calculate balance factor
int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Right Rotation
struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update heights
    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));
    return x;
}
// Left Rotation
struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    // Perform rotation
    y->left = x;
    x->right = T2;
    // Update heights
    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));
    return y;
}
// Insertion
struct Node* insert(struct Node *node, int value)
{
    // Normal BST insertion
    if (node == NULL)
        return createNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);

    else if (value > node->data)
        node->right = insert(node->right, value);

    else
    {
        printf("Duplicate value not allowed!\n");
        return node;
    }
    // Update height
    node->height = 1 + max(height(node->left),
                            height(node->right));

    // Calculate balance factor
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL Case
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
// Find minimum node
struct Node* minValueNode(struct Node *node)
{
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Deletion
struct Node* deleteNode(struct Node *root, int value)
{
    // Normal BST deletion
    if (root == NULL)
    {
        printf("Value not found!\n");
        return root;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;

            free(root);

            return temp;
        }

        // Case 3: Only left child
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;

            free(root);

            return temp;
        }

        // Case 4: Two children
        else
        {
            struct Node *temp =
                minValueNode(root->right);

            root->data = temp->data;

            root->right =
                deleteNode(root->right, temp->data);
        }
    }
    // Update height
    root->height = 1 + max(height(root->left),
                            height(root->right));
    // Calculate balance factor
    int balance = getBalance(root);
    // LL Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    // LR Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RR Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    // RL Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// Inorder traversal
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// Preorder traversal
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
// Postorder traversal
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// Display tree traversals
void display(struct Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }

    printf("\nInorder   : ");
    inorder(root);

    printf("\nPreorder  : ");
    preorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\n");
}

// Main function
int main()
{
    struct Node *root = NULL;

    int choice, value, n, i;

    while (1)
    {
        printf("\n<------AVL TREE------>\n");
        printf("1. Creation\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Display Traversals\n");
        printf("5. Exit\n");
        printf("---------------\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter number of nodes: ");
                scanf("%d", &n);

                root = NULL;

                printf("Enter %d values:\n", n);

                for (i = 0; i < n; i++)
                {
                    scanf("%d", &value);
                    root = insert(root, value);
                }

                printf("AVL Tree created successfully!\n");

                break;

            case 2:

                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("%d inserted successfully!\n",
                       value);

                break;

            case 3:

                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                break;

            case 4:

                display(root);

                break;

            case 5:

                printf("Program terminated.\n");
                exit(0);

            default:

                printf("Invalid choice!\n");
        }
    }

    return 0;
}