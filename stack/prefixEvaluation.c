#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int isOperator(char ch)
{
    return (ch == '+' ||
            ch == '-' ||
            ch == '*' ||
            ch == '/' ||
            ch == '%');
}

int calculate(int a, int b, char operator)
{
    switch (operator)
    {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;

        case '%':
            return a % b;
    }

    return 0;
}

int evaluatePrefix(char expression[])
{
    int i;
    int operand1, operand2, result;

    /* Scan from RIGHT to LEFT */
    for (i = strlen(expression) - 1; i >= 0; i--)
    {
        char ch = expression[i];

        /* Operand */
        if (isdigit(ch))
        {
            push(ch - '0');
        }

        /* Operator */
        else if (isOperator(ch))
        {
            operand1 = pop();
            operand2 = pop();

            result = calculate(operand1, operand2, ch);

            push(result);
        }
    }

    return pop();
}

int main()
{
    char expression[MAX];

    printf("Enter prefix expression: ");
    scanf("%s", expression);

    printf("Result = %d\n", evaluatePrefix(expression));

    return 0;
}