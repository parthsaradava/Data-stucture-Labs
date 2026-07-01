#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *i;
    float *f;
    char *c;

    i = (int *)malloc(sizeof(int));
    f = (float *)malloc(sizeof(float));
    c = (char *)malloc(sizeof(char ));

    printf("Enter a int number : ");
    scanf("%d",i);

    printf("Enter a char : ");
    scanf(" %c",c);

    printf("Enter a Float number : ");
    scanf("%f",f);

    printf("%d\n",*i);
    printf("%f\n",*f);
    printf("%c",*c);

    free(i);
    free(f);
    free(c);

}