#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;
struct Node *first_copy = NULL;

void display(struct Node *first);

void insert_at_last(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->info = x;
    newnode->link = NULL;

    if(first == NULL)
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

void display(struct Node *first_nodes)
{
    struct Node *temp;

    temp = first;

    while(temp != NULL)
    {
        printf("%d ",temp->info);
        temp = temp->link;
    }
}

void copy_list()
{
    struct Node *temp , *save;
    temp = first;

    first_copy = (struct Node *)malloc(sizeof(struct Node));
    first_copy->info = temp->info;
    first_copy->link = NULL;

    save = first_copy;
    temp = temp->link;

    while(temp != NULL)
    {
        struct Node *newnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->info = temp->info;
        newnode->link = NULL;
        save->link = newnode;
        save = newnode;
        temp = temp->link;
    }
}



int main()
{
    int x , n;

    printf("Enter a number of node: ");
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a info portion of a node: ");
        scanf("%d",&x);

        insert_at_last(x);
    }

    printf("Original Linked list\n");
    display(first);
    printf("\n");
    printf("Copy linked list\n");
    copy_list();
    display(first_copy);
   
}