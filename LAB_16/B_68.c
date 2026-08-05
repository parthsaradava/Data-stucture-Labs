#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

int top = -1;
int arr[MAX];


void push(int x )
{
    if (top >= MAX - 1)
    {
        printf("Stack is overflow\n");
        return;
    }

    top += 1;

    arr[top] = x;
}

int pop()
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

void evalution_prefix(char prefix[])
{
    char operand1 , operand2; 
    int result;
    for(int i = strlen(prefix)-1 ; i >= 0 ; i--)
    {
        if(isdigit(prefix[i]))
        {
            push(prefix[i] - '0');
        }
        else
        {
            operand1 = pop();
            operand2 = pop();

            switch(prefix[i])
            {
                case '+':
                result = operand1 + operand2;
                
                break;
                
                case '-':
                result = operand1 - operand2;
                
                break;

                case '*':
                result = operand1 * operand2;
               
                break;

                case '/':
                result = operand1 / operand2;
                
                break;

                case '%':
                result = operand1 % operand2;
                
                break;

                case '^':
                result = (int)pow(operand1 , operand2);
                break;

                default:
                    printf("Invalid");
                    break;
            }

            push(result);
        }
    }
    printf("Result : %d",pop());
}


int main()
{
    char prefix[100];

    printf("Enter a string: ");
    scanf("%s",prefix);

    evalution_prefix(prefix);
    
}
