#include<stdio.h>
int main()
{
    int r1 , c1;

   

    printf("Enter a number metrix row: ");
    scanf("%d",&r1);

    printf("Enter a number metrix column: ");
    scanf("%d",&c1);

    int arr1[r1][c1] , arr2[r1][c1] , arr[r1][c1];


    printf("============================\n");
    printf("\tFirst metrix\n");
    printf("============================\n");

    for(int i = 0 ; i < r1 ; i++)
    {
        for(int j = 0 ; j < c1 ; j++)
        {
            printf("Enter a element of first metrix: ");
            scanf("%d",&arr1[i][j]);
        }
    }


    printf("============================\n");
    printf("\tSecond metrix\n");
    printf("============================\n");

    for(int i = 0 ; i < r1 ; i++)
    {
        for(int j = 0 ; j < c1 ; j++)
        {
            printf("Enter a element of first metrix: ");
            scanf("%d",&arr2[i][j]);
        }
    }



    for(int i = 0 ; i < r1 ; i++)
    {
        for(int j = 0 ; j < c1 ; j++)
        {
            arr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("============================\n");
    printf("\tfinal metrix\n");
    printf("============================\n");


    for(int i = 0 ; i < r1 ; i++)
    {
        for(int j = 0 ; j < c1 ; j++)
        {
           
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}