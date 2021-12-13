#include <stdio.h>
#include <stdlib.h>

int prime(int x,int flag)
{
    int i;
    for(i=2;i<x;i++)
    {
        if(x%i != 0)
        {
            flag = 1;continue;
        }
        else
        {
            flag=0;break;
        }
    }return flag;
}

int main()
{
    int x,y,flag;
    printf("enter 2 numbers: ");
    scanf("%d %d",&x,&y);
    printf("prime numbers between %d and %d are ",x,y);
    while(x<=y)
    {
        flag=prime(x,0);
        if(flag==1)
            printf("%d ",x);
        x++;
    }
    return 0;
}
