#include <stdio.h>
#include <stdlib.h>

int i;
int print(int rev[],int s)
{
    printf("output: ");
    for(i=0;i<s;i++)
    {
        printf(" %d",rev[i]);
    }
}

int reverse(int arr[], int s)
{
    int rev[10];
    for(i=s-1;i>=0;i--)
    {
        rev[s-i-1]=arr[i];
    }
    print(rev,s);
}

int main()
{
    int arr[10];
    printf("enter an array: \n");
    for(i=0;i<5;i++)
    {
        printf(" ");
        scanf("%d",&arr[i]);
    }
    reverse(arr,5);
    return 0;
}
