#include <stdio.h>
int main()
{
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    int arr[x][2];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter a element in 2D array: ");
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = i + 1; j < 2; j++)
        {
            if (arr[i][0] > arr[j][0])
            {
                int temp = arr[i][0];
                int temp2 = arr[i][1];

                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];

                arr[j][0] = temp;
                arr[j][1] = temp2;
            }
        }
    }



    int index = 0;

    for (int i = 1; i < x; i++)
    {
        if (arr[index][1] >= arr[i][0])
        {
            if (arr[i][1] > arr[index][1])
                arr[index][1] = arr[i][1];
        }
        else
        {
            index++;
            arr[index][0] = arr[i][0];
            arr[index][1] = arr[i][1];
        }
    }

    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++)
    {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
}