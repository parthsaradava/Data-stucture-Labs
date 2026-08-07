#include <stdio.h>
#include <stdlib.h>

int R = -1;
int F = -1;

void Enqueue_in_last(int arr[], int x, int N)
{
    
    if ((F == 0 && R == N - 1) || (F == R + 1))
    {
        printf("Queue is overflow!");
        return;
    }

    if (F == -1)
    {
        F = 0;
        R = 0;
    }
   
    else if (R == N - 1)
    {
        R = 0;
    }
    
    else
    {
        R++;
    }

    arr[R] = x;
}

void Enqueue_in_front(int arr[], int x, int N)
{
  
    if ((F == 0 && R == N - 1) || (F == R + 1))
    {
        printf("Queue is overflow!");
        return;
    }

  
    if (F == -1)
    {
        F = 0;
        R = 0;
    }
    else if (F == 0)
    {
        F = N - 1;
    }
    else
    {
        F--;
    }

    arr[F] = x;
}

int Dequeue_at_first(int arr[], int N)
{
    if (F == -1)
    {
        printf("Queue is underflow!");
        return -1;
    }

    int X = arr[F];

    if (F == R)
    {
        F = -1;
        R = -1;
    }
    else if (F == N - 1)
    {
        F = 0;
    }
    else
    {
        F++;
    }

    return X;
}

int Dequeue_at_last(int arr[], int N)
{
    if (R == -1)
    {
        printf("Queue is underflow!");
        return -1;
    }

    int x = arr[R];

    if (F == R)
    {
        F = -1;
        R = -1;
    }
    else if (R == 0)
    {
        R = N - 1;
    }
    else
    {
        R--;
    }

    return x;
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
    int choice, n, x;

    printf("Enter a size of an array: \n");
    scanf("%d", &n);

    int arr[n];

    while (1)
    {
        printf("\n1.Enqueue in last\n");
        printf("2.Enqueue in front\n");
        printf("3.Dequeue in fisr\n");
        printf("4.Dequeue in last\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter Your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a number to enqueue: ");
            scanf("%d", &x);
            Enqueue_in_last(arr, x, n);
            break;

        case 2:
            printf("Enter a number to add in first: ");
            scanf("%d",&x);
            Enqueue_in_front(arr,x,n);
            break;

        case 3:
            printf("Dequeue number is: %d",Dequeue_at_first(arr , n));
            break;
        
        case 4:
            printf("Dequeue_in_last number is: %d",Dequeue_at_last(arr,n));
            break;

        case 5:
            Display(arr);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid");
            break;
        }
    }
}