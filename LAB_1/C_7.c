#include<stdio.h>
int main()
{
    int days;

    printf("Enter a days: ");
    scanf("%d",&days);

    int year = days / 365;
    int week = (days % 365) / 7;
    int day = (days % 365) % 7;

    printf("year = %d\n",year);
    printf("week = %d\n",week);
    printf("day = %d\n",day);

    return 0;
}