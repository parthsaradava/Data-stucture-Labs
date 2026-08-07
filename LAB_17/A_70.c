#include <stdio.h>
#include<stdlib.h>

int R = -1;
int F = -1;

void Enqueue(int arr[], int x, int N)
{
    if (R >= N - 1)
    {
        printf("Queue is overflow!");
        exit(0);
    }

    R = R + 1;

    arr[R] = x;

    if (F == -1)
    {
        F = 0;
    }
}

int Dequeue(int arr[])
{
    if (F == -1)
    {
        printf("Queue is underflow!");
        return 0;
    }
    int X = arr[F];
    if (F == R)
    {
        F = -1;
        R = -1;
    }
    else
    {
        F = F + 1;
    }

    return X;
}

void Display(int arr[])
{
    if (F == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = F; i <= R; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, n, x ;

    printf("Enter a size of an array: \n");
    scanf("%d", &n);

    int arr[n];

    while (1)
    {
        printf("Enqueue\n");
        printf("Dequeue\n");
        printf("Display\n");
        printf("Exit\n");
        printf("Enter Your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number to enqueue: ");
            scanf("%d", &x);
            Enqueue(arr, x, n);
            break;

        case 2:
            printf("DQueue Element is :%d\n",Dequeue(arr));
            break;

        case 3:
            Display(arr);
            break;
        
        case 4:
            exit(0);
        default:
            printf("Invalid");
            break;
        }
    }
}