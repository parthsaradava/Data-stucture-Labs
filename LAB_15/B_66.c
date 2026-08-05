#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char info;
    struct Node *link;
};

struct Node *top = NULL;

void push(char x)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;
    newnode->link = top;
    top = newnode;
}

char pop()
{
    if (top == NULL)
        return '\0';

    struct Node *temp = top;
    char value = temp->info;
    top = top->link;
    free(temp);

    return value;
}

char peek()
{
    if (top == NULL)
        return '\0';
    return top->info;
}

int input_precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 2;     
    case '*':
    case '/':
        return 4;      
    case '^':
        return 5;     
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

int stack_precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;      
    case '*':
    case '/':
        return 3;      
    case '^':
        return 6;      
    case '(':
        return 0;
    default:
        return 8;
    }
}

int rank(char ch)
{
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9'))
        return 1;

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return -1;

    return 0;
}

void reverseString(char s[])
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

void infix_to_prifix(char infix[])
{
    char prifix[100];
    int i = 0, j = 0;
    int r = 0;

    push('(');
    strcat(infix, ")");

    while (infix[i] != '\0')
    {
        while (stack_precedence(peek()) > input_precedence(infix[i]))
        {
            char x = pop();
            prifix[j++] = x;
            r += rank(x);

            if (r < 1)
            {
                printf("Invalid Expression\n");
                return;
            }
        }

        if (stack_precedence(peek()) != input_precedence(infix[i]))
        {
            push(infix[i]);
        }
        else
        {
            pop();
        }

        i++;
    }

    prifix[j] = '\0';

    if (top != NULL || r != 1)
    {
        printf("Invalid Expression\n");
    }
    else
    {
        reverseString(prifix);
        printf("prifix Expression: %s\n", prifix);
    }
}

int main()
{
    char infix[100];

    printf("Enter Infix Expression: ");
    gets(infix);

    char revinfix[100];
    reverseString(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    infix_to_prifix(infix);

    return 0;
}