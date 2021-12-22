#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y=1,sum=0;
    printf("enter an integer: ");
    scanf("%d",&x);
    for(;y<=x;y++)
    {
        sum+=y;
    }
    printf("sum: %d",sum);
    return 0;
}
