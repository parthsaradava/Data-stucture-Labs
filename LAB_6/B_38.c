#include<stdio.h>
void main()
{
    int n;

    printf("Enter a size of an array: ");
    scanf("%d",&n);


    int arr[n] , *ptr;

    ptr = arr;

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",(ptr + i));
    }

    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(*(ptr + i) > *(ptr + j))
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",*(ptr + i));
    }

}