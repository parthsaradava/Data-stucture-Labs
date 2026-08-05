#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int top = -1;
int arr[MAX];

void push(int x)
{
    if (top >= MAX - 1)
    {
        printf("Stack is overflow\n");
        return;
    }

    top += 1;

    arr[top] = x;
}

int pop()
{
    int delete;
    if (top == -1)
    {
        printf("Stake is underflow\n");
        return 0;
    }

    top = top - 1;
    delete = arr[top + 1];

    return delete;
}

int solution(int arr1[], int arr2[], int n)
{
    int i = 0 , j = 0;
    for (i = 0; i < n ; i++)
    {
        if (arr1[i] < arr1[i + 1])
        {
            arr2[j] = arr1[i];
            j++;
        }
        else if(i == n-1)
        {
            push(arr1[i]);
        }
        push(arr1[i]);
    }

    while(top != -1)
    {
        int x = pop();
        arr2[j] = x;
        j++;
    }

    for(int j = 0 ; j < n-1 ; j++)
    {
        if(arr2[j] > arr2[j+1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr1[n] , arr2[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr1[i]);
    }

    if(solution(arr1 , arr2 , n))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
