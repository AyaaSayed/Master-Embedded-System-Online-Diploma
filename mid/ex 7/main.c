#include <stdio.h>
#include <stdlib.h>

int sum(int x)
{
    while(x>0)
        return x+sum(x-1);
}

int main()
{
    int x;
    printf("enter an positive number: ");
    scanf("%d",&x);
    printf("sum 1:%d is %d",x,sum(x));
    return 0;
}
