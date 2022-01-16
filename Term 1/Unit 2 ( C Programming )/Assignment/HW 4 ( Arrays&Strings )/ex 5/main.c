#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,arr[10];
    printf("enter number of data: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    int num,flag=0;
    printf("enter number to be searched: ");
    scanf("%d",&num);
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
            {
                printf("is found");
                flag=1;
                break;
            }
    }
    if(flag==0)
        printf("isn't found");
    return 0;
}
