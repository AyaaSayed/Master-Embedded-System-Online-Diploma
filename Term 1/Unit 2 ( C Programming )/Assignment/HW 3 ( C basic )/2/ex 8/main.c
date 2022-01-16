#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    float x,y;
    printf("enter an operation: ");
    scanf("%c",&ch);
    printf("enter 2 numbers: ");
    scanf("%f %f",&x,&y);
    switch(ch)
    {
    case'+':
        {printf("%f + %f = %f",x,y,x+y);}break;
    case'-':
        {printf("%f - %f = %f",x,y,x-y);}break;
    case'*':
        {printf("%f * %f = %f",x,y,x*y);}break;
    case'/':
        {printf("%f / %f = %f",x,y,x/y);}break;
    default:
        {printf("error!!");}break;
    }
    return 0;
}
