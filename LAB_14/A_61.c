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
int check(char x[])
{
    int i = 0;
    char ch, topChar;

    
  

    while (x[i] != '\0')
    {
        ch = x[i];

    
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
       
        else if (ch == ')' || ch == '}' || ch == ']')
        {
           
            if (top == -1)
                return 0;

            topChar = pop();

           
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '['))
            {
                return 0;
            }
        }

        i++;
    }

    
    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    int result = check(s);

    if(result)
    {
        printf("String is balanced");
    }
    else
    {
        printf("String is not balanced");
    }
}