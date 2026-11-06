#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;

/* Insert at beginning */
void insertBeginning() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at beginning.\n");
}
/* Insert at end */
void insertEnd() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    printf("Node inserted at end.\n");
}

/* Insert at position */
void insertPosition() {
    int value, position;
    printf("Enter value: ");
    scanf("%d", &value);
    printf("Enter position: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Node inserted at position %d.\n", position);
}

/* Delete from beginning */
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);

    printf("Node deleted from beginning.\n");
}

/* Delete from end */
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    if (head->next == NULL) {
        head = NULL;
        free(temp);
        printf("Node deleted from end.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    free(temp);

    printf("Node deleted from end.\n");
}

/* Delete from position */
void deletePosition() {
    int position;
    printf("Enter position: ");
    scanf("%d", &position);
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteBeginning();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    temp->prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}
/* Display */
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("\nDoubly Linked List:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    do {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertPosition();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deletePosition();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}