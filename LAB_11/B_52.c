#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int info;
    struct Node *link;
};


struct Node *first = NULL;
struct Node *last = NULL;
struct Node *second_half_first = NULL;
struct Node *second_half_last = NULL;

void inser_at_last(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->info = x;

    if(first == NULL)
    {
        newnode->link = newnode;
        first = newnode;
        last = newnode;
    }
    else
    {
        newnode->link = first;
        last->link = newnode;
        last = newnode;
    }

}

int count_node()
{
    struct Node *temp;
    int count=0;
    temp = first;

    do
    {
        temp=temp->link;
        count++;
    } while (temp != first);
    
    return count;

}

void display(struct Node *fst)
{
    struct Node *temp;

    temp=fst;
    do
    {
        printf("%d ",temp->info);
        temp = temp->link;
    } while (temp != fst);
}

void split_list()
{
    struct Node *temp_first_half, *temp_second_half;

    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int n = count_node();

    temp_first_half = first;

    for(int i = 1; i < n / 2; i++)
    {
        temp_first_half = temp_first_half->link;
    }

    second_half_first = temp_first_half->link;


    temp_second_half = second_half_first;

    while(temp_second_half->link != first)
    {
        temp_second_half = temp_second_half->link;
    }

    
    second_half_last = temp_second_half;



    temp_first_half->link = first;

    last = temp_first_half;


    second_half_last->link = second_half_first;


    printf("-------First half-----\n");
    display(first);

    printf("\n");

    printf("------Second half------\n");
    display(second_half_first);
}





int main()
{
    int x ,n;

    printf("Enter a size of a linked list: ");
    scanf("%d",&n);


    for(int i = 1 ; i <= n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&x);

        inser_at_last(x);
    }

   split_list();

   

}

