#include<stdio.h>
int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c",&ch);


    if(ch == 'A' || ch == 'E' || ch == 'O' || ch == 'i' || ch == 'U'||ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u')
    {
        printf("%c is vowel",ch);
    }
    else
    {
        printf("%c is not vowel",ch);
    }

    return 0;
}