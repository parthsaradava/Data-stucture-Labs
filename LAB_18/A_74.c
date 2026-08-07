#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    int priority;
};

struct Node Q[10];
int F = -1;
int R = -1;

void Enqueue(int x, int pri)
{
    if (R >= 10 - 1)
    {
        printf("Queue is overflow");
        return;
    }

    R = R + 1;

    Q[R].priority = pri;
    Q[R].value = x;

    if (F == -1)
    {
        F = 0;
    }
}

int Dequeue()
{
    int remove_element, index;
    if (F == -1)
    {
        printf("Queue is underflow!");
        return 0;
    }

    int max_pri = Q[0].priority;

    for (int i = 0; i < 10; i++)
    {
        if (max_pri < Q[i].priority)
        {
            max_pri = Q[i].priority;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (max_pri == Q[i].priority)
        {
            remove_element = Q[i].value;
            index = i;
            break;
        }
    }

    for (int i = index; i < 10 - 1; i++)
    {
        Q[i] = Q[i+1];
    }

    R = R - 1;
    return remove_element;
}

void Display()
{
    if (F == -1)
    {
        printf("Queue is overflow!");
        return;
    }
    
    for (int i = F; i <= R; i++)
    {
        printf("[ %d %d ] , ", Q[i].value , Q[i].priority);
    }
    printf("\n");
}

int main()
{
    int value, priority;
    int choice;

    while (1)
    {
        printf("1.Enqueue\n");
        printf("2.dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d",&value);
            printf("Enter a priority: ");
            scanf("%d",&priority);
            Enqueue(value , priority);
            break;
        
        case 2:
            printf("Dqueue is element is: %d\n",Dequeue());
            break;

        case 3:
            Display();
            break;
        
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid\n");
            break;
        }

    }
}