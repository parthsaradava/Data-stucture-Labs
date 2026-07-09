#include <stdio.h>
#include <stdlib.h>

struct Node_1
{
    int info;
    struct Node_1 *link_1;
};

struct Node_2
{
    int info;
    struct Node_2 *link_2;
};

struct Node_1 *first1 = NULL;
struct Node_2 *first2 = NULL;

void insert_first_Linkedlist(int x)
{
    struct Node_1 *newnode1;

    newnode1 = (struct Node_1 *)malloc(sizeof(struct Node_1 ));

    newnode1->info = x;
    newnode1->link_1 = first1;
    first1 = newnode1;
}

void insert_Second_Linkedlist(int x)
{
    struct Node_2 *newnode2;

    newnode2 = (struct Node_2 *)malloc(sizeof(struct Node_2 ));

    newnode2->info = x;
    newnode2->link_2 = first2;
    first2 = newnode2;
}

int check()
{
    struct Node_1 *save1 = first1;
    struct Node_2 *save2 = first2;

    if (save1 == NULL && save2 == NULL)
    {
        return 1;
    }

    while ((save1->link_1 != NULL) && (save2->link_2 != NULL))
    {
        if (save1->info != save2->info)
        {
            return 0;
        }
        else{
            save1 = save1->link_1;
            save2 = save2->link_2;
        }
    }
    return 1;
}

void main()
{
    int x, n1, n2;

    printf("Enter a number n1: ");
    scanf("%d", &n1);

    printf("Enter a number n2: ");
    scanf("%d", &n2);

    if (n1 != n2)
    {
        printf("Linked list length are not same!");
        exit(0);
    }

    else
    {
        for (int i = 1; i <= n1; i++)
        {
            printf("Enter a firstnode info portion : ");
            scanf("%d", &x);
            insert_first_Linkedlist(x);
        }

        for (int i = 1; i <= n2; i++)
        {
            printf("Enter a second node info portion : ");
            scanf("%d", &x);
            insert_Second_Linkedlist(x);
        }
    }

    if(check())
    {
        printf("both linked list are same");
    }
    else
    {
        printf("both linked list are not same");
    }


}