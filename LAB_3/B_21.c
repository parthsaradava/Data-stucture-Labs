#include<stdio.h>
int main()
{
    int n;

    printf("Enter a size of an array: ");
    scanf("%d",&n);


    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a element of an array:  ");
        scanf("%d",&arr[i]);
    }

    int array_num , new_num ;

    printf("Enter a number which contain a array to replace: ");
    scanf("%d",&array_num);

    printf("Enter a number to add in array: ");
    scanf("%d",&new_num);

    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == array_num)
        {
            arr[i] = new_num;
            printf("index : %d\n",i);
        }
    }


    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",arr[i]);
    }
}