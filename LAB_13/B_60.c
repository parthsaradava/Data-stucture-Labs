#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        return ;
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


// void checkstr(char str[])
// {
//     char ch , counta = 0 , countb = 0;
    
//     for(int i = 0 ; i < strlen(str) ; i++)
//     {
//         ch = str[i];
//         push(ch);
//     }

//     for(int i = 0 ; i < strlen(str) ; i++)
//     {
//         ch = pop();

//         if(ch == 'a')
//         {
//             counta += 1;
//         }
//         else if(ch == 'b')
//         {
//             countb += 1;
//         }
//     }

//     if(counta == countb)
//     {
//         printf("String is valid");
//     }
//     else
//     {
//         printf("String is invalid");
//     }

// }

void checkstr(char str[])
{
    char ch;

    for(int i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        if(ch == 'a')
        {
            push('a');              
        }
        else if(ch == 'b')
        {
            if(top != -1)           
            {
                pop();           
            }
            else
            {
                push('b');          
            }
        }
    }

    if(top == -1)
        printf("String is valid");
    else
        printf("String is invalid");
}


int main()
{
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    checkstr(s);
}