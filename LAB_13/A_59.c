#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char info;
    struct Node *link;
};

int top = -1;
struct Node *last = NULL;
struct Node *first = NULL;

void push(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    top += 1;
    newnode->info = x;
    newnode->link = NULL;

    if (first == NULL)
    {
        first = newnode;
        return;
    }

    struct Node *save;
    save = first;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;
    last = newnode;
}

int pop()
{
    char value;
    struct Node *save;
    struct Node *pred;

    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return '\0';
    }

    save = first;
    pred = NULL;

    while (save->link != NULL)
    {
        pred = save;
        save = save->link;
    }

    value = save->info;

    if (pred == NULL)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        pred->link = NULL;
        last = pred;
    }

    top--;

    free(save);

    return value;
}

void recognize(char str[])
{
    char ch, p;
    int i = 0;

    push('c');

    ch = str[i];

    while (ch != 'c')
    {
        if (ch == '\0')
        {
            printf("Invalid");
            return;
        }

        push(ch);

        i++;
        ch = str[i];
    }

    i++;

    p = pop();

    while (p != 'c')
    {
        ch = str[i];

        if (ch == '\0')
        {
            printf("Invalid");
            return;
        }

        if (ch != p)
        {
            printf("Invalid");
            return;
        }

        i++;
        p = pop();
    }

    if (str[i] == '\0')
    {
        printf("Valid");
    }
    else
    {
        printf("Invalid");
    }
}

int main()
{
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    recognize(s);
}
