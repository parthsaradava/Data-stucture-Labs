#include<stdio.h>

struct Student
{
    int Roll_no;
    char name[50];
    char branch[50];
    int Batch_no;
};

void main()
{
    struct Student *ptrstd , std;
    ptrstd = &std;

    printf("Enter a Roll_no: ");
    scanf("%d",&ptrstd->Roll_no);

    printf("Enter a Name: ");
    scanf("%s",ptrstd->name);

    printf("Enter a Branch: ");
    scanf("%s",ptrstd->branch);

    printf("Enter a Batch_no: ");
    scanf("%d",&ptrstd->Batch_no);

    printf("Roll no : %d\n",ptrstd->Roll_no);
    printf("Name : %s\n",ptrstd->name);
    printf("branch : %s\n",ptrstd->branch);
    printf("Batch no : %d\n",ptrstd->Batch_no);

}


