#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/' || ch == '%')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

void reverse(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    char reversed[MAX];
    char postfix[MAX];

    int i;
    int j = 0;

    strcpy(reversed, infix);

    /* Step 1: Reverse */
    reverse(reversed);

    /* Step 2: Swap brackets */
    for (i = 0; reversed[i] != '\0'; i++)
    {
        if (reversed[i] == '(')
            reversed[i] = ')';

        else if (reversed[i] == ')')
            reversed[i] = '(';
    }

    top = -1;

    /* Step 3: Infix to Postfix */
    for (i = 0; reversed[i] != '\0'; i++)
    {
        char ch = reversed[i];

        /* Operand */
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        /* Opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }

        /* Closing bracket */
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();
        }

        /* Operator */
        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) > precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    /* Step 4: Reverse postfix */
    reverse(postfix);

    strcpy(prefix, postfix);
}

int main()
{
    char infix[MAX];
    char prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}