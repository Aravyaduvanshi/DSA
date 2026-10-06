#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top < MAX - 1)
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    return 0;
}

int main()
{
    char expression[MAX];
    int i;
    char ch, popped;

    printf("Enter expression: ");
    scanf("%s", expression);

    for (i = 0; expression[i] != '\0'; i++)
    {
        ch = expression[i];

        
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }

       
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            popped = pop();

            if (popped == '\0' || !isMatching(popped, ch))
            {
                printf("Parentheses are NOT balanced.\n");
                return 0;
            }
        }
    }

    if (top == -1)
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are NOT balanced.\n");

    return 0;
}