#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y=1,F=1;
    printf("enter an integer: ");
    scanf("%d",&x);
    if(x>0)
    {
        for(;y<=x;y++)
            {
                F*=y;
            }
        printf("Factorial = %d",F);
    }
    else(x<0);
        printf("error!!");
    return 0;
}
