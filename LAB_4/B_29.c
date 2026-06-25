#include<stdio.h>
int main()
{
    int size1  , size2;

    printf("Enter a size of a first array: ");
    scanf("%d",&size1);

    printf("Enter a size of a second array: ");
    scanf("%d",&size2);

    int sum = size1 + size2 , k = 0;

    int arr1[size1] , arr2[size2];
    int arr[sum];

    for(int i = 0 ; i < size1 ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr1[i]);
    }

    for(int i = 0 ; i < size2 ; i++)
    {
        printf("Enter a second array number: ");
        scanf("%d",&arr2[i]);
    }

    for(int i = 0 ; i < sum ; i++)
    {
        if(i < size1)
        {
            arr[i] = arr1[i];
        }
        else
        {
            arr[i] = arr2[k];
            k++;
        }
    }

    for(int i = 0 ; i < sum ; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}