#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insert_at_last(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->info = x;
    newnode->link = NULL;

    if (first == NULL)
    {
        first = newnode;
        return;
    }

    struct Node *save;
    save = first;

    while (save->link != NULL)
    {
        save = save->link;
    }

    save->link = newnode;
}

void sort()
{
    struct Node *save, *next = NULL , *pred;
    

    for (save = first; save != NULL; save = save->link)
    {
        for (next = save->link; next != NULL; next = next->link)
        {
            if (save->info > next->info)
            {
                int temp = save->info;
                save->info = next->info;
                next->info = temp;
            }
        }
    }
     
}

void sort_by_address()
{
    struct Node *save  , *pred;

    for(pred = first ; pred != NULL ; pred = pred->link)
    {
        for(save=pred->link ; save != NULL ; save = save->link)
        {
            if(pred->info > save->info)
            {
                if(pred == first)
                {
                    pred->link = save->link;
                    save->link = pred;
                    first = save;
                }
                else
                {
                    struct Node *temp = first;
                    while(temp->link != pred)
                    {
                        temp = temp->link;
                    }
                    temp->link = save;
                    pred->link = save->link;
                    save->link = pred;
                }
            }
        }
    }
}

void display()
{
    struct Node *temp;

    temp = first;

    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
}

int main()
{

    int x, n;

    printf("Enter a number of node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a info portion of a node: ");
        scanf("%d", &x);
        insert_at_last(x);
    }
    printf("Using info protion short...\n");
    sort();
    display();
    printf("\n");
    printf("Using address protion short...\n");
    sort_by_address();
    display();

    return 0;
}