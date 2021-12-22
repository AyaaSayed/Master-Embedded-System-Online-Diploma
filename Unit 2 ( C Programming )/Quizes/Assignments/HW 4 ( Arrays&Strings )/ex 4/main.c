#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    printf("enter number of data: ");
    scanf("%d",&n);
    int arr[10];
    for(i=0;i<n;i++)
    {
        printf(" ");
        scanf("%d",&arr[i]);
    }

    int num,loc;
    printf("enter number to insert: ");
    scanf("%d",&num);
    printf("enter number's location: ");
    scanf("%d",&loc);
    for(i=n;i>=loc;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[loc-1]=num;

    for(i=0;i<=n;i++)
    {
        printf(" %d\t",arr[i]);
    }
    return 0;
}
