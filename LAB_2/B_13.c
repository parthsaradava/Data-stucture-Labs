#include<stdio.h>
int main()
{
    int start , end , isprime;

    printf("Enter a staring number: ");
    scanf("%d",&start);

    printf("Enter a ending number: ");
    scanf("%d",&end);

    for(int i = start ; i <= end ; i++)
    {
        isprime = 0;
        for(int j = 1; j <= i ; j++)
        {
            if(i % j == 0)
            {
                isprime++;
            }
        }
        if(isprime == 2)
        {
            printf("%d\n",i);
        }
    }
}