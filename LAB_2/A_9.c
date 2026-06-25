#include<stdio.h>
int main()
{
    int base , power , ans = 1;

    printf("Enter a base number: ");
    scanf("%d",&base);


    printf("Enter a power number: ");
    scanf("%d",&power);


    for(int i = 1 ; i <= power ; i++)
    {
        ans = ans * base;
    }

    printf("%d",ans);
}