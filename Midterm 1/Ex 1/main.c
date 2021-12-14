#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char itos(int num)
{
    int i; char str[10];
    for(i=0;i<10;i++)
    {
        if(num!=0)
        {
            str[i]=num%10;
            num /=10;
            continue;
        }
        else
            str[i]="0";
            break;
    }
    sum(str,i);
}

int sum(char str[] , int s)
{
    int i,sum=0;
    for(i=0;i<s;i++)
        {sum +=str[i];}
    printf("output: %d\n",sum);
}

int main()
{
    int num;
    printf("input: ");
    scanf("%d",&num);
    itos(num);
    return 0;
}
