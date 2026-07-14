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

// void DeleteAtSpecificPosition(int x)
// {
//     struct Node *save;
//     struct Node *pred;

//     if (first == NULL)
//     {
//         printf("Linked list is empty");
//         return;
//     }

//     save = first;
//     pred = NULL;

//     while (save->info != x && save->link != NULL)
//     {
//         pred = save;
//         save = save->link;
//     }

//     if (save->info != x)
//     {
//         printf("Node is not found!");
//         return;
//     }
//     else
//     {
//         if (save == first)
//         {
//             first = first->link;
//         }
//         else
//         {
//             pred->link = save->link;
//         }
//     }
//     free(save);
// }

// void insert_at_specificPosition(int x, int k)
// {
//     struct Node *newnode;
//     newnode = (struct Node *)malloc(sizeof(struct Node));
//     newnode->info = x;
//     newnode->link = NULL;

//     if (k == 1)
//     {
//         newnode->link = first;
//         first = newnode;
//         return;
//     }

//     struct Node *save;
//     save = first;

//     for (int i = 1; i < k - 1; i++)
//     {
//         save = save->link;
//     }

//     newnode->link = save->link;
//     save->link = newnode;
// }

void swap_k_element(int k, int n)
{
    struct Node *temp, *temp2;
    temp = first, temp2 = first;

    if (k < 1 || k > n)
    {
        printf("Invalid position!");
        return;
    }

    for (int i = 1; i < k; i++)
    {
        temp = temp->link;
    }

    for (int i = 1; i < n - k + 1; i++)
    {
        temp2 = temp2->link;
    }

    int temp3 = temp->info;
    temp->info = temp2->info;
    temp2->info = temp3;
}

int CountNodes()
{
    struct Node *save;
    int count=0;

    save = first;

    if(first == NULL)
    {
        count = 0;
        return count;
    }

    while (save != NULL)
    {
        count += 1;
        save = save->link;
    }

    return count;

}



void swap_kth_node(int k)
{
    struct Node *temp, *temp2;
    struct Node *tempred = NULL, *temppred2 = NULL;
    struct Node *tempnext, *tempnext2;

    int n = CountNodes();

    

    temp = first;
    temp2 = first;

    
    for(int i = 1; i < k; i++)
    {
        tempred = temp;
        temp = temp->link;
    }

   
    for(int i = 1; i < n - k + 1; i++)
    {
        temppred2 = temp2;
        temp2 = temp2->link;
    }

    tempnext = temp->link;
    tempnext2 = temp2->link;

   
    if(temp->link == temp2)
    {
        if(tempred != NULL)
            tempred->link = temp2;
        else
            first = temp2;

        temp2->link = temp;
        temp->link = tempnext2;
    }
    else if(temp2->link == temp)
    {
        if(temppred2 != NULL)
            temppred2->link = temp;
        else
            first = temp;

        temp->link = temp2;
        temp2->link = tempnext;
    }
    else
    {
        if(tempred != NULL)
            tempred->link = temp2;
        else
            first = temp2;

        if(temppred2 != NULL)
            temppred2->link = temp;
        else
            first = temp;

        temp2->link = tempnext;
        temp->link = tempnext2;
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

    int x, n, k;

    printf("Enter a number of node: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter a info portion of a node: ");
        scanf("%d", &x);
        insert_at_last(x);
    }

    printf("Original list: ");
    display();

    printf("\nEnter the kth node:\n");
    scanf("%d", &k);

    // swap_k_element(k, n);

    swap_kth_node(k);

    display();
}