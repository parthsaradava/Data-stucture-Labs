#include<stdio.h>

int main()
{
    float r;

    printf("Enter a radius: ");
    scanf("%f",&r);

    float area = 3.145 * r * r;

    printf("area of circle is %2.f",area);

    return 0;
}