
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

void Revearse_Node()
{
    struct Node *save = first , *pred=NULL , *next=NULL;

    while (save != NULL)
    {
        next = save->link;
        save->link = pred;
        pred = save;
        save = next;
    }

    first = pred;
    
}

void display()
{
    struct Node *temp;

    temp = first;

    while(temp != NULL)
    {
        printf("%d ",temp->info);
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

    Revearse_Node();

    display();

}