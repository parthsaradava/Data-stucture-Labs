#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int main()
{
    int n;

    printf("Enter size of an string array: ");
    scanf("%d",&n);

    char strarr[n][50];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a word in array: ");
        scanf("%s",strarr[i]);
    }

    srand(time(NULL));

    int rand_num = rand() % n;

    char arr_word[50];
    strcpy(arr_word,strarr[rand_num]);

    

    char user_word[50];

    printf("Enter a word to check anagram or not: ");
    scanf("%s",&user_word);


    int len_arr_str = strlen(arr_word);
    int len_usr_str = strlen(user_word);

    if(len_arr_str == len_usr_str)
    {
        for(int i = 0 ; i < len_arr_str ; i++)
        {
            for(int j = i + 1 ; j < len_arr_str; j++)
            {
                if(tolower(arr_word[i]) > tolower(arr_word[j]))
                {
                    char temp_arr = arr_word[i];
                    arr_word[i] = arr_word[j];
                    arr_word[j] = temp_arr;
                }

                if(tolower(user_word[i]) > tolower(user_word[j]))
                {
                    char temp_usr = user_word[i];
                    user_word[i] = user_word[j];
                    user_word[j] = temp_usr;
                }
            }
        }

        if (strcmp(arr_word,user_word))
        {
            printf("%s is not anagram word",strarr[rand_num]);
        }
        else
        {
            printf("%s is anagram word",strarr[rand_num]);
        }
    }

    // printf("Random word is: %s\n",arr_word);
    // printf("User word is: %s\n",user_word);

    else
    {
        printf("%s is not anagram because lenght is not same" , strarr[rand_num]);
    }
}