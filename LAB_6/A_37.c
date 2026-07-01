#include<stdio.h>
void main()
{
    int n , max;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr[n] , *ptr;

    ptr = arr;

  

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",(ptr + i));
    }
      
    max = *ptr;

    for(int i = 0 ; i < n ; i++)
    {
        if(*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }

    printf("Largest element of an array: %d", max);


}