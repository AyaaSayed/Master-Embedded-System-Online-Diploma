#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y,z;
    printf("enter 3 numbers: ");
    scanf("%f %f %f",&x,&y,&z);
    if((x>y) && (x>z)){printf("largest number is %f",x);}
    if((y>x) && (y>z)){printf("largest number is %f",y);}
    else {printf("largest number is %f",y);}
    return 0;
}
