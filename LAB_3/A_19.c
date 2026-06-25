#include<stdio.h>
int main()
{
    int n , min , max;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr[n];


    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == max)
        {
            printf("max number index is %d\n",i);
        }
        if(arr[i] == min)
        {
            printf("min number index is %d\n",i);
        }
    }


}