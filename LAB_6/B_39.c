#include<stdio.h>
#include<string.h>
void main()
{
    char str[50] , *start , *end;
    int flag = 1;
    printf("Enter a string: ");
    scanf("%s",str);

    int len = strlen(str);
    start = str;
    end = str + len - 1;

    while (start < end)
    {
        if(*start != *end)
        {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if(flag)
    {
        printf("String is palindrom");
    }
    else
    {
        printf("string is not palindrom");
    }
    

}