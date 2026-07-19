#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;
struct Node *last = NULL;

void insert_at_first(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->info = x;

    if(first == NULL)
    {
        newnode->link = newnode;
        first = newnode;
        last = newnode;
    }
    else
    {
        newnode->link = first;
        last->link = newnode;
        first = newnode;
    }
}

void insert_at_last(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;

    if(first == NULL)
    {
        newnode->link = newnode;
        first = newnode;
        last = newnode;
    }
    else
    {
        newnode->link = first;
        last->link = newnode;
        last = newnode;
    }
}

void delete_at_specific(int x)
{
    struct Node *save  , *pred;
    save = first;
    if(first == NULL)
    {
        printf("Linked list is empty");
    }

    while (save->info != x && save != last )
    {
        
        pred = save;
        save = save->link;
    }

    if(save->info != x)
    {
        printf("Node not found");
    }

    if(first == last)
    {
        first = NULL;
        last = NULL;
    }
    else if(first->info == x)
    {
        first = first->link;
        last->link = first;
    }
    else
    {
        pred->link = save->link;
    }   
    if(x == last->info)
    {
        last = pred;
    }

    free(save);

}

void display()
{
    struct Node *temp;

    temp = first;

    if(first == NULL)
    {
        printf("Linked list empty");
    }

    do
    {
        printf("%d ", temp->info);
        temp = temp->link;
    } while (temp != first);
    
}


int main()
{
    int n , del;

    printf("Enter a size of a linked list: ");
    scanf("%d",&n);

    int x;

    for(int i = 1 ; i <= n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&x);
        insert_at_last(x);
        // insert_at_first(x);
    }

    printf("Enter a number to delete in linked list: ");
    scanf("%d",&del);
    delete_at_specific(del);

    display();
}
