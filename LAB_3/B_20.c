#include<stdio.h>
int main()
{
    int n , isduplicate=0;

    printf("Enter a number: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a element: ");
        scanf("%d",&arr[i]);
    }

    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[i] == arr[j])
            {
                isduplicate = 1;
                break;
            }
        }
    }

    if(isduplicate)
    {
        printf("Array contains a duplicate number\n");
    }
    else
    {
         printf("Array is not contains a duplicate number");
    }
    
}