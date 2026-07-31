#include <stdio.h>
#include <string.h>

void finalstring(char s[])
{
    int len = strlen(s);

    int k = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u')
        {
            int left = 0;
            int right = i - 1;

            while (left < right)
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;

                left++;
                right--;
            }
        }
    }

    printf("%s", s);
}

int main()
{
    char str[100];

    int n;

    printf("Enter a how many time to get a string: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {

        printf("Enter a string: \n");
        getchar();
        gets(str);

        finalstring(str);
    }
}