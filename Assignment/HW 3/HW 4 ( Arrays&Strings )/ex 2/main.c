#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    printf("enter number of data: ");
    scanf("%d",&n);
    float arr[10],average,sum=0.0;
    for(i=0;i<n;i++)
    {
        printf("enter arr[%d]: ",i);
        scanf("%f",&arr[i]);
        sum=sum+arr[i];
    }
    average=sum/n;
    printf("average is: %f",average);
    return 0;
}
