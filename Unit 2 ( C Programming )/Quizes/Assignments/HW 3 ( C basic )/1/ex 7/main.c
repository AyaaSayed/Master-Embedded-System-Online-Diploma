#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    printf("enter value of x: ");
    scanf("%f",&x);
    printf("enter value of y: ");
    scanf("%f",&y);
    x = x+y;
    y = x-y;
    x = x-y;
    printf("after swapping, value of x = %f\n",x);
    printf("after swapping, value of y = %f",y);
    return 0;
}
