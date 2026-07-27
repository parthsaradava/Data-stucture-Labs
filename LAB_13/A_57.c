
#include <stdio.h>
#include <stdlib.h>

int top = -1;


void push(int x ,int arr[])
{
    if (top >= 5 - 1)
    {
        printf("Stack is overflow\n");
        return;
    }

    top += 1;

    arr[top] = x;
}

int pop(int arr[])
{
    int delete;
    if (top == -1)
    {
        printf("Stake is underflow\n");
        return 0;
    }

    top = top - 1;
    delete = arr[top + 1];

    return delete;
}

int peep(int i , int arr[])
{
    if ((top - i + 1) <= -1)
    {
        printf("Element is not found\n");
        return 0;
    }

    return arr[top - i + 1];
}

int peek(int arr[])
{
    if (top <= -1)
    {
        printf("Element is not avilable\n");
        return 0;
    }

    return arr[top];
}

void change(int i, int x , int arr[])
{
    if ((top - i + 1) <= -1)
    {
        printf("Element is not found\n");
        return;
    }

    arr[top - i + 1] = x;
}

void display(int arr[])
{
    if (top == -1)
    {
        printf("stack is undeflow\n");
        return;
    }

    printf("====Stack===\n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int  choice, pos, value, ans , n;



    printf("Enter a size of stack: ");
    scanf("%d",&n);
    int arr[n];

    while (1)
    {
        printf("1.push\n");
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
            push(value , arr);
            break;

        case 2:
            ans = pop(arr);
            printf("delete : %d\n", ans);
            break;

        case 3:
            printf("Enter a position to find element: ");
            scanf("%d", &pos);
            ans = peep(pos,arr);
            printf("Element is %d\n", ans);
            break;

        case 4:
            printf("Top element\n");
            ans = peek(arr);
            printf("Peek element is : %d\n", ans);
            break;

        case 5:
            printf("Enter a position to change value: ");
            scanf("%d", &pos);
            printf("Enter a value to change in stack: ");
            scanf("%d", &value);
            change(pos, value , arr);
            break;

        case 6:
            display(arr);
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