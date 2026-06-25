#include<stdio.h>
int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    for(int i = 0 ; i < n ;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}