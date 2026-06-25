 #include<stdio.h>
 int main()
 {
    int n ;

    printf("Enter a size of an array: ");
    scanf("%d",&n);

    int arr[n];

    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }

    int idx=0 , number;

    printf("Enter a number to  delete in array: ");
    scanf("%d",&number);

    while (arr[idx] != number)
    {
        idx++;
    }

    for(int j = idx ; j < n ; j++)
    {
        arr[j] = arr[j+1];
    }

    n--;

    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
    
 }