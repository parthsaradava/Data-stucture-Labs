#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coff;
    int power;
    struct Node *link;
};

struct Node *sfirst = NULL;
struct Node *first = NULL;

void insert_At_last(int coff, int power, struct Node **head)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->coff = coff;
    newnode->power = power;
    newnode->link = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    else
    {
        struct Node *save = *head;

        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newnode;
    }
}

// void insert_At_slast(int coff, int power)
// {
//     struct Node *newnode;

//     newnode = (struct Node *)malloc(sizeof(struct Node));
//     newnode->coff = coff;
//     newnode->power = power;
//     newnode->link = NULL;

//     if (sfirst == NULL)
//     {
//         sfirst = newnode;
//         return;
//     }
//     else
//     {
//         struct Node *save;

//         save = sfirst;

//         while (save->link != NULL)
//         {
//             save = save->link;
//         }
//         save->link = newnode;
//     }
// }

void display(struct Node *fst)
{
    struct Node *save;

    save = fst;

    while (save != NULL)
    {
        printf("%dx^%d", save->coff, save->power);
        save = save->link;
        if (save != NULL)
        {
            printf(" + ");
        }
    }
}

void sum_of_polynomial()
{
    struct Node *save1 = first;
    struct Node *save2 = sfirst;
    struct Node *result = NULL;

    if (save1 == NULL && save2 == NULL)
    {
        printf("Both polynomials are empty.\n");
        return;
    }

    if (save1 == NULL)
    {
        display(save2);
        return;
    }
    if (save2 == NULL)
    {
        display(save1);
        return;
    }

    while (save1 != NULL && save2 != NULL)
    {
        if (save1->power > save2->power)
        {
            insert_At_last(save1->coff, save1->power, &result);
            save1 = save1->link;
        }
        else if (save1->power < save2->power)
        {
            insert_At_last(save2->coff, save2->power, &result);
            save2 = save2->link;
        }
        else
        {
            int power = save1->power;
            int sum_coff = save1->coff + save2->coff;

            if (sum_coff != 0)
            {
                insert_At_last(sum_coff, save1->power, &result);
            }
            save1 = save1->link;
            save2 = save2->link;
        }
    }

    while (save1 != NULL)
    {
        insert_At_last(save1->coff, save1->power, &result);
        save1 = save1->link;
    }

    while (save2 != NULL)
    {
        insert_At_last(save2->coff, save2->power, &result);
        save2 = save2->link;
    }

    printf("Sum of polynomials: ");
    display(result);
}

int main()
{
    int n1, n2, coff, power;

    printf("Enter the number of terms in first polynomial: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++)
    {
        printf("Enter the coefficient and power: ");
        scanf("%d %d", &coff, &power);
        insert_At_last(coff, power, &first);
    }

    printf("Enter the number of terms in second polynomial: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++)
    {
        printf("Enter the coefficient and power: ");
        scanf("%d %d", &coff, &power);
        insert_At_last(coff, power, &sfirst);
    }

    printf("First Polynomial: ");
    display(first);

    printf("\nSecond Polynomial: ");
    display(sfirst);
    printf("\n");

    sum_of_polynomial();
}
