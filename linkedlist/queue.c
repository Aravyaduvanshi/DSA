#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* Enqueue */
void enqueue() {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", value);
}

/* Dequeue */
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow.\n");
        return;
    }

    struct Node *temp = front;

    printf("%d deleted from queue.\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

/* Display */
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("\nQueue:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    int choice;

    do {

        printf("\n===== QUEUE USING LINKED LIST =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
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