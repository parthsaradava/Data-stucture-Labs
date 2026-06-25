#include<stdio.h>
int main()
{
    int n , idx = 0;

    printf("Enter a size: ");
    scanf("%d",&n);

    int arr[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a element in an array: ");
        scanf("%d",&arr[i]);
    }

    int number;

    printf("Enter a number to enter in an array: ");
    scanf("%d",&number);

    while (arr[idx] < number)
    {
        idx++;
    }

    // printf("%d",idx);

    for(int i = n ; i >= idx ; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[idx] = number; 

    for(int i = 0 ; i <= n ; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
    
}