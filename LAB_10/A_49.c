#include<stdio.h>
#include<stdlib.h>

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

int Count_gcd(int a , int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void insert_gcd_in_linkedlist()
{
    struct Node *temp , *temp2 , *newNode;

    temp = first;
    temp2 = first->link;

    while (temp2 != NULL)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = Count_gcd(temp->info , temp2->info);

        temp->link = newNode;
        newNode->link = temp2;
        temp = temp2;
        temp2 = temp->link;
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

    printf("Original list: \n");
    display();
    printf("\n");

    insert_gcd_in_linkedlist();

    printf("after add gcd...\n");
    display();
    printf("\n");
}
