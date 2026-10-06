#include<stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Create Stack */
void create()
{
    top = -1;
    printf("Stack created successfully.\n");
}

/* Push */
void push()
{
    int value;

    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    top++;
    stack[top] = value;

    printf("%d pushed into stack.\n", value);
}

/* Pop */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Popped element: %d\n", stack[top]);
    top--;
}

/* Peek */
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

/* Display */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

/* Main */
int main()
{
    int choice;

    while (1)
    {
        printf("\n--STACK MENU-- \n");
        printf("1. Create\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                push();
                break;

            case 3:
                pop();
                break;

            case 4:
                peek();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}