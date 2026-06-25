#include<stdio.h>
#include<string.h>
#include <ctype.h>
int main()
{
    char str[50];

    printf("Enter a string: ");
    fgets(str , sizeof(str) , stdin);

    int len = strlen(str);

    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = tolower(str[i]);
        }
        else if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = toupper(str[i]);
        }
        else
        {
            str[i] = str[i];
        }
    }

    printf("%s",str);
}