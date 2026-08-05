#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insert_at_last(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

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
}


void swap_node()
{
    struct Node *temp, *temp2, *prev;

    if (first == NULL || first->link == NULL)
        return;

    temp = first;
    temp2 = first->link;

    first = temp2;
    prev = NULL;

    while (temp != NULL && temp2 != NULL)
    {
        temp->link = temp2->link;
        temp2->link = temp;

        if (prev != NULL)
            prev->link = temp2;

        prev = temp;

        
        temp = temp->link;

        if (temp != NULL)
            temp2 = temp->link;
        else
            temp2 = NULL;
    }
}


void display()
{
    struct Node *temp;

    temp = first;

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
}


int main()
{

    int x, n;

    printf("Enter a number of node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a info portion of a node: ");
        scanf("%d", &x);
        insert_at_last(x);
    }

    printf("Original list: \n");
    display();
    printf("\n");

    swap_node();

    printf("after swap nodes\n");
    display();
    printf("\n");
}