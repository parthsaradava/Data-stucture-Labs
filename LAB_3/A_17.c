#include<stdio.h>
int main()
{
    int n , sum = 0;

    printf("Enter a number: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    int s , e ;

    printf("Enter a starting index: ");
    scanf("%d",&s);

    printf("Enter a ending index: ");
    scanf("%d",&e);

    
    if (e <= n && s >= 0)
    {
        for(int i = s ; i < e ; i++)
        {
            sum += arr[i];
        }
        printf("%d",sum);
    }
    else
    {
        printf("Enter a valid index!");
    }
    
    
    

}