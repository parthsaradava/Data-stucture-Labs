#include<stdio.h>
int main()
{
    int n , sum = 0 ;

    printf("Enter a number: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a element of in array");
        scanf("%d",&arr[i]);
    }

    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + arr[i];
    }

    float avg = sum / n;

    printf("%2.f",avg);
}