#include<stdio.h>
int main()
{
    int second;

    printf("Enter a second: ");
    scanf("%d",&second);

    int hh = second / 3600 ;
    int mm = (second % 3600)/60;
    int ss = (second % 60)%60;
    
    printf("%d:%d:%d",hh,mm,ss);

    return 0;
}