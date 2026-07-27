#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

int top = 0;
struct Node *last = NULL;
struct Node *first = NULL;

void push(int x)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    top += 1;
    newnode->info = x;
    newnode->link = NULL;

    if(first == NULL)
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
    last = newnode;
    
}

void pop()
{
    struct Node *save;
    struct Node *pred;

    if(first == NULL)
    {
        printf("Linked list is empty");
        return;
    }

    save = first;
    pred = NULL;

    while (save -> link != NULL)
    {
        pred = save;
        save = save -> link;
    }
    top -= 1;
    pred -> link = NULL;
    last = pred;
    printf("%d ",save->info);
    free(save);
}

int peek()
{
    return last->info;
}

int peep(int pos)
{
    if(top <= 0)
    {
        printf("Stack is underflow!");
        return 0;
    }

    struct Node *temp = first;

    for(int i = 1 ; i < top-pos+1 ; i++)
    {
        temp = temp->link;
    }

    return temp->info;
}

void change(int pos , int value)
{   
    if(top <= 0)
    {
        printf("Stack is underflow");
        return;
    }

    struct Node *temp = first;

    for(int i = 1 ; i < top-pos+1 ; i++)
    {
        temp = temp->link;
    }

    temp->info = value;
}


void display()
{
    struct Node *temp = first;

    if(temp == NULL)
    {
        printf("Stack is empty!");
        return;
    }

    while (temp != NULL)
    {
        printf("%d\n" , temp->info);
        temp = temp->link;
    }
    
}


int main()
{
    
    int  choice, pos, value, ans;

    while (1)
    {
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.peep\n");
        printf("4.peek\n");
        printf("5.change\n");
        printf("6.Display\n");
        printf("7.Exit\n");
        printf("Enter you choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a value: ");
            scanf("%d", &value);
            push(value);
            printf("%d",top);
            break;

        case 2:
            printf("\nPop element is : ");
            pop();
            break;


        case 3:
            printf("Enter a position to find element: ");
            scanf("%d", &pos);
            ans = peep(pos);
            printf("Element is %d\n", ans);
            break;

        case 4:
            printf("Top element\n");
            ans = peek();
            printf("Peek element is : %d\n", ans);
            break;

        case 5:
            printf("Enter a position to change value: ");
            scanf("%d", &pos);
            printf("Enter a value to change in stack: ");
            scanf("%d", &value);
            change(pos, value);
            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Invalid number operation\n");
            break;
        }
    }
}