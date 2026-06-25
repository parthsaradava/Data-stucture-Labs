#include<stdio.h>
int main()
{
    int n;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr[n+1];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    int idx , num;
    

    printf("Enter a index where you are enter a number: ");
    scanf("%d",&idx);

    printf("Enter a number to add in index: ");
    scanf("%d",&num);

    for(int i = n  ; i >= idx ; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[idx] = num;

    for(int i = 0 ; i < n+1 ; i++)
    {
        printf("%d ",arr[i]);
    }

}
