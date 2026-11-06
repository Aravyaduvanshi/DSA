#include <stdio.h>
#define MAX 5

int queue[MAX];
int priority[MAX];
int count = 0;

void enqueue(int value, int p) {
    if (count == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    int i = count - 1;
    while (i >= 0 && priority[i] > p) {
        queue[i + 1] = queue[i];
        priority[i + 1] = priority[i];
        i--;
    }
    queue[i + 1] = value;
    priority[i + 1] = p;
    count++;

    printf("%d inserted with priority %d.\n", value, p);
}
void dequeue() {
    if (count == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    printf("Deleted: %d (Priority: %d)\n",
           queue[0], priority[0]);

    for (int i = 0; i < count - 1; i++) {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }
    count--;
}
void display() {
    if (count == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("\nElement\tPriority\n");

    for (int i = 0; i < count; i++)
        printf("%d\t%d\n", queue[i], priority[i]);
}

int main() {
    int choice, value, p;

    do {
        printf("\n .... PRIORITY QUEUE ....\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Arav Enter the  value: ");
                scanf("%d", &value);

                printf("Enter priority (smaller = higher): ");
                scanf("%d", &p);

                enqueue(value, p);
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