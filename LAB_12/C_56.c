#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Node
{
    char s_name[100];
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *L = NULL;
struct Node *R = NULL;
struct Node *prev = NULL;

void insert_a_song(char s[100])
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    
    strcpy(newnode->s_name , s);
    newnode->rptr = NULL;

    if (R == NULL)
    {
        newnode->lptr = NULL;
        L = newnode;
        R = newnode;
       
    }
    else
    {
        newnode->lptr = R;
        R->rptr=newnode;
        R = newnode;
        prev = R;
    }
}



void Go_prev_song()
{
    
    if(prev == NULL)
    {
        printf("Playlist is Empty ! ");
        return;
    }
    

    if(prev->lptr == NULL)
    {
        printf("Your playlist have only one song so you can not go your prev song !");
        return;
    }
    prev = prev->lptr;    
    printf("%s\n" , prev->s_name);
}

void Go_next_song()
{
    
    if(prev == NULL)
    {
        printf("Playlist is Empty ! ");
        return;
    }
    

    if(prev->rptr == NULL)
    {
        printf("Your playlist have only one song so you can not go your prev song !");
        return;
    }
    prev = prev->rptr;    
    printf("%s\n" , prev->s_name);
}

void Delete_song(char s[100])
{
    struct Node *save;
    save = L;

    if (L == NULL)
    {
        printf("Your playlist is empty!\n");
        return;
    }

    while (save != NULL && stricmp(save->s_name, s) != 0)
    {
        save = save->rptr;
    }

    if (save == NULL)
    {
        printf("Song not found!\n");
        return;
    }

    
    if (L == R)
    {
        L = NULL;
        R = NULL;
    }

    
    else if (save == L)
    {
        L = L->rptr;
        L->lptr = NULL;
    }


    else if (save == R)
    {
        R = R->lptr;
        R->rptr = NULL;
    }

    
    else
    {
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;
    }

    free(save);
    printf("Song deleted successfully.\n");
}

void display()
{
    struct Node *save;

    save = L;

    if(L == NULL)
    {
        printf("Linked list is empty!");
        return;
    }

    while (save != NULL)
    {
        printf("%s\n" , save->s_name);
        save = save->rptr;
    }
    
}


int main()
{
    int choice;
    char song_name[100];
    char Delete_song_name[100];

    while(1)
    {
        printf("\n1.add Song\n");
        printf("2.go prev song\n");
        printf("3.go next song\n");
        printf("4.delete a song\n");
        printf("5.Display playlist\n");
        printf("6.Exit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
    

        switch (choice)
        {
        case 1:
            printf("Enter a song name:");
            getchar();
            gets(song_name);
            insert_a_song(song_name);
            break;

        case 2:
            
            Go_prev_song();
            printf("\n");
            break;

        case 3:
            Go_next_song();
            printf("\n");
            break;

        case 4:
            printf("Enter a song name to Delete: ");
            getchar();
            gets(Delete_song_name);
            Delete_song(Delete_song_name);
            
            break;

        case 5:
            printf("=======Your playlist=========\n");
            display();
            printf("\n");
            printf("\n");
            break;

        case 6:
            exit(0);
            break;
        
        default:
            printf("Invalid");
            break;
        }
    }
}
