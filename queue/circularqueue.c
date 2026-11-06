#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = value;
    printf("%d inserted: ", value);
}
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n....CIRCULAR QUEUE ....\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("ARAV Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
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
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}