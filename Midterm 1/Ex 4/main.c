#include <stdio.h>
#include <stdlib.h>

char reverse(int num)
{
    int i,j; char str[10],rev[10];
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

    printf("output: ");
    for(j=0;j<i;j++)
    {
        printf("%d",str[j]);
    }
}

int main()
{
    int num,x;
    printf("input: ");
    scanf("%d",&num);
    reverse(num);
    return 0;
}

