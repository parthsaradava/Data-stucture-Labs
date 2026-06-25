// #include<stdio.h>
// int main()
// {
//     int n;

//     printf("Enter a size of an array: ");
//     scanf("%d",&n);

//     int arr[n];

//     for(int i = 0 ; i < n ; i++)
//     {
//         printf("Enter a element: ");
//         scanf("%d",&arr[i]);
//     }

//     int idx;

//     printf("Enter a index to delete a number: ");
//     scanf("%d",&idx);

//     for(int i = idx ; i < n-1 ; i++)
//     {
//         int temp = arr[i];
//         arr[i] = arr[i+1];
//         arr[i+1] = temp;
//     }

//     n--;

//     for(int i = 0 ; i < n ; i++)
//     {
//         printf("%d ",arr[i]);
//     }

// }



#include<stdio.h>
int main()
{
    int n;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    int idx;

    printf("Enter a index to delete a number: ");
    scanf("%d",&idx);

    for(int i = idx ; i < n ; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    for(int i = 0 ; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

}