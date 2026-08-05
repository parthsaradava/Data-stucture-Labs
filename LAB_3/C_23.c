
#include<stdio.h>
#include<string.h>
int main()
{
    int n;

    printf("Enter a size of an string: ");
    scanf("%d",&n);

    char str[n][50] , temp[100];

    printf("Enter %d names:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i + 1; j < n ; j++)
        {
            if(strcmp(str[i] , str[j]) > 0)
            {
                strcpy(temp , str[i]);
                strcpy(str[i] , str[j]);
                strcpy(str[j] , temp);
            }
        }
    }


    for(int i = 0 ; i < n ; i++)
    {
        printf("%s  ",str[i]);
    }
}