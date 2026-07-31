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

void pop()
{
    char value;
    struct Node *save;
    struct Node *pred;

    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return;
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

  
}

void display()
{
    struct Node *temp = first;

    if(temp == NULL)
    {
        printf("Stack is empty!");
        return;
    }

    while (temp != NULL)
    {
        printf("%c" , temp->info);
        temp = temp->link;
    }
    
}

void removestar(char x[])
{
    char ch;
    
    int i = 0 ;

    ch = x[i];


    if(ch == '\0')
    {
        printf("String is empty");
        return;
    }

    while (ch != '\0')
    {
        ch = x[i];
        if(ch != '*')
        {
            push(ch);
        }
        else
        {
           pop();
        }
        i++;
    }

    if(top == -1)
    {
        printf("Empty string after update");
        return;
    }

    display();


}


int main()
{
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    removestar(s);

}