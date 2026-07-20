#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *lptr;
    struct Node *rptr;
};

struct Node *l = NULL;
struct Node *r = NULL;

void insert_at_first(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->info = x;
    newnode->lptr = NULL;

    if (r == NULL)
    {
        newnode->rptr = NULL;
        l = newnode;
        r = newnode;
    }
    else
    {
        newnode->rptr = l;
        l->lptr = newnode;
        l = newnode;
    }
}

void insert_at_last(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->info = x;
    newnode->rptr = NULL;

    if (r == NULL)
    {
        newnode->lptr = NULL;
        l = newnode;
        r = newnode;
    }
    else
    {
        newnode->lptr = r;
        r->rptr = newnode;
        r = newnode;
    }
}

void Display()
{
    struct Node *save = l;

    if (l == NULL)
    {
        printf("List is empty!");
        return;
    }

    while (save != NULL)
    {
        printf("%d ", save->info);
        save = save->rptr;
    }
}

int Count_node()
{
    struct Node *save;
    int count = 0;

    if(l == NULL)
    {
        printf("Link list is empty");
        return 0;
    }

    save = l;

    while (save != NULL)
    {
        save=save->rptr;
        count++;
    }

    return count;
}

void Delete_alternate()
{
    if (l == NULL)
        return;

    struct Node *curr = l;

    while (curr != NULL && curr->rptr != NULL)
    {
        struct Node *temp = curr->rptr;     

        curr->rptr = temp->rptr;

        if (temp->rptr != NULL)
            temp->rptr->lptr = curr;
        else
            r = curr;        

        free(temp);

        curr = curr->rptr;   
    }
}

int main()
{
    int x, n ;

    printf("Enter a size of linked list:  ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);

        insert_at_last(x);
    }

    Delete_alternate();

    Display();

}