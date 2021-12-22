#include <stdio.h>
#include <stdlib.h>

int last_accurrence(int arr[],int s,int num)
{
    int i,l,flag=0;
    for(i=0;i<s;i++)
    {
        if(num==arr[i])
        {
            l=i;flag=1;
        }
    }
    if(flag=0)
        printf("the number isn't found");
    else
        printf("last accurrence of %d is %d",num,l);
}

int main()
{
    int arr[10],s,num,i;
    printf("enter array size: ");
    scanf("%d",&s);
    printf("enter an array: \n");
    for(i=0;i<s;i++)
    {
        printf(" ");
        scanf("%d",&arr[i]);
    }
    printf("enter a number: ");
    scanf("%d",&num);
    last_accurrence(arr,s,num);
    return 0;
}
