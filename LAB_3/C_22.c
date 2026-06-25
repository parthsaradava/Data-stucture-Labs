#include<stdio.h>

int main()
{
    int n;

    printf("Enter size of Pascal triangle: ");
    scanf("%d", &n);

    int arr[n][n];

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for(int k = n-1 ; k >= i ; k--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}













// other way


#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int c = 1;

        for (int j = 0; j <= i; j++)
        {
            printf("%d ", c);
            c = c * (i - j) / (j + 1);
        }
        printf("\n");
    }

    return 0;
}