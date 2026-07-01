#include<stdio.h>
void main()
{
    int n , sum = 0;;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr[n] , *ptr;

    ptr = arr;

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",(ptr + i));
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",*(ptr + i));
        sum = sum + *(ptr + i);
    }

    printf("\n");

    printf("sum : %d" , sum);



}