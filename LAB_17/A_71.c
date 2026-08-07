#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *F = NULL;
struct Node *R = NULL;

void Enqueue(int x)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }
    newnode->info = x;
    newnode->link = NULL;

    if (F == NULL)
    {
        F = newnode;
        R = newnode;
    }
    else
    {
        R->link = newnode;
        R = newnode;
    }
}
int Dqueue()
{
    struct Node *temp;
    int x;

    if (F == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }

    temp = F;
    x = F->info;

    F = F->link;

    if (F == NULL)
        R = NULL;

    free(temp);

    return x;
}

void Display()
{
    struct Node *save;
    save = F;

    if (F == NULL)
    {
        printf("Queue is underflow!");
    }

    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->link;
    }
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n1.Enqueue\n");
        printf("2.Dqueue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &x);
            Enqueue(x);
            break;
        case 2:
            printf("DQueue Element is :%d\n", Dqueue());
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}
