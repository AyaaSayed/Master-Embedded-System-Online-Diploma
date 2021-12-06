#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y,temp;
    printf("enter value of x: ");
    scanf("%f",&x);
    printf("enter value of y: ");
    scanf("%f",&y);
    temp=x;
    x=y;
    y=temp;
    printf("after swapping, value of x = %f\n",x);
    printf("after swapping, value of y = %f",y);
    //without using temp varaible
    //float x,y;
    //printf("enter value of x: ");
    //scanf("%f",&x);
    //printf("enter value of y: ");
    //scanf("%f",&y);
    //printf("after swapping, value of x = %f",y);
    //printf("after swapping, value of y = %f",x);
    return 0;
}
