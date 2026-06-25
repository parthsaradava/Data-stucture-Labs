#include<stdio.h>
int main()
{
    int n , fact = 1;

    printf("Enter a number: ");
    scanf("%d",&n);

    for(int i = 2 ; i < n ; i++)
    {
        if(n % i == 0)
        {
            fact = 0;
            break;
        }
        else
        {
            fact = 1;
        }
    }

    if(fact == 1)
    {
        printf("%d is prime number",n);
    }
    else
    {
        printf("%d is not prime number",n);
    }
}