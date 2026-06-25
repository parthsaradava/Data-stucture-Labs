#include<stdio.h>
int main()
{
    int a , b , c;

    printf("Enter a number a: ");
    scanf("%d",&a);

    printf("Enter a number b: ");
    scanf("%d",&b);

    printf("Enter a number c: ");
    scanf("%d",&c);


    if((a > b) && (a > c))
    {
        printf("%d is largest number",a);
    }
    else if((b > a) && (b > c))
    {
        printf("%d is largest number",b);
    }
    else
    {
        printf("%d is largest number",c);
    }

    return 0;
}