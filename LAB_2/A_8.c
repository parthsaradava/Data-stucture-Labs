// #include<stdio.h>
// int main()
// {
//     int n , fact = 1;

//     printf("Enter a number: ");
//     scanf("%d",&n);

//     for(int i = 1 ; i <= n ; i++)
//     {
//         fact = fact * i; 
//     }

//     printf("%d! = %d",n,fact);
// }



#include<stdio.h>
int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d",&n);

    int ans = fact(n);

    printf("%d! = %d",n,ans);

}