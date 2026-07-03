#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;


void insertAtFirst(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->info = x;
    newnode->link = first;
    first = newnode;
}

void Display()
{
    struct Node *save;
    save = first;

    if(first == NULL)
    {
        printf("Linked list Empty");
        return;
    }

    while (save != NULL)
    {
        printf("%d ",save->info);
        save = save -> link;
    }
}

void deleteFirstNode()
{
    struct Node *save;

    save = first;
    first = save->link;
    free(save);
}

void insertAtEnd(int x)
{
    struct Node *newnode;
    struct Node *save;

    newnode->info = x;
    newnode->link = NULL;


    save = first;

    if(first == NULL)
    {
        printf("Linked list Empty");
        return;   
    }
    
    while(save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;

}

void DeleteAtEnd()
{
    struct Node *save;
    struct Node *pred;

    if(first == NULL)
    {
        printf("Linked list is empty");
        return;
    }

    save = first;
    pred = NULL;

    while (save -> link != NULL)
    {
        pred = save;
        save = save -> link;
    }

    pred -> link = NULL;

    free(save);
}


void DeleteAtSpecificPosition(int x)
{
    struct Node *save;
    struct Node *pred;

    if(first == NULL)
    {
        printf("Linked list is empty");
        return;
    }

    save = first;
    pred = NULL;

    while (save -> info != x && save -> link != NULL)
    {
        pred = save;
        save = save -> link;
    }

    if(save -> info != x)
    {
        printf("Node is not found!");
    }
    else
    {
        pred->link = save->link;
    }
    free(save);
}

int CountNodes()
{
    struct Node *save;
    int count=0;

    save = first;

    if(first == NULL)
    {
        count = 0;
        return count;
    }

    while (save->link != NULL)
    {
        count += 1;
        save = save->link;
    }

    return count;

}


void main()
{
    int i , x , n;

    printf("Enter a number: ");
    scanf("%d",&n);

    struct Node *temp;
    temp = first;
    

    for(i = 1 ; i <= n ; i++)
    {
        printf("Enter a node info portion : ");
        scanf("%d",&x);
        insertAtFirst(x);
    }
    printf("Before deletation...\n");
    Display();




    // deleteFirstNode();
    // printf("\n");
    // printf("After deletation...\n");
    // Display();





    printf("\n");
    printf("After insert at last...\n");
    insertAtEnd(10);
    Display();


    // printf("\n");
    // printf("After delete last node...\n");
    // DeleteAtEnd();
    // Display();
    printf("\n");

    // printf("AFter deletation any node by user...\n");
    // DeleteAtSpecificPosition(3);
    // Display();
    // printf("\n");


    printf("Total Number of Nodes...\n");
    int TotalNodes = CountNodes();

    printf("Total Number of Nodes is %d",TotalNodes);
}
