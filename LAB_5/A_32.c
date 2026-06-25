#include<stdio.h>
int main()
{
    int row1 , col1 , row2 , col2;

    printf("Enter a number first matrix row");
    scanf("%d",&row1);

    printf("Enter a number first matrix column");
    scanf("%d",&col1);

    printf("Enter a number second matrix row");
    scanf("%d",&row2);

    printf("Enter a number second matrix column");
    scanf("%d",&col2);

    int arr1[row1][col1] , arr2[row2][col2];

    for(int i = 0 ; i < row1 ; i++)
    {
        for(int j = 0 ; j < col1 ; j++)
        {
            printf("Enter a first metrix element: ");
            scanf("%d",&arr1[i][j]);
        }
    }

    for(int i = 0 ; i < row2; i++)
    {
        for(int j = 0 ; j < col2 ; j++)
        {
            printf("Enter a second metrix element: ");
            scanf("%d",&arr2[i][j]);  
        }
    }

    int arr[row1][col2];

    if(col1 == row2)
    {
        for(int i = 0 ; i < row1 ; i++)
        {
            for(int j = 0 ; j < col2 ; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0 ; i < row1 ; i++)
    {
        for(int j = 0 ; j < col2 ; j++)
        {
            for(int k = 0 ; k < col1 ; k++)
            {
                arr[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }


     for(int i = 0 ; i < row1 ; i++)
    {
        for(int j = 0 ; j < col2 ; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    
}