#include<stdio.h>
int main()
{
    for(int i = 1 ; i <= 1000 ; i++)
    {
        int temp = i;
        int rem = 0 , ans = 0;
        while (temp != 0)
        {
            rem = temp % 10;
            ans = ans + (rem * rem * rem);
            temp /= 10;
        }
        if(i == ans)
        {
            printf("%d\n",i);
        }
    }
}