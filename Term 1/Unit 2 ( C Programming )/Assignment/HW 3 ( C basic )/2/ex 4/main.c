#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    printf("enter an integer to check: ");
    scanf("%d",&x);
    if(x>0){printf("%d is positive",x);}
    if(x<0){printf("%d is negative",x);}
    else {printf("%d is zero");}
    return 0;
}
