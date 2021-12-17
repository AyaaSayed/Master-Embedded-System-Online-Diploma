#include <stdio.h>
#include <stdlib.h>
#define area(r) 3.14*r*r

int main()
{
    int r;
    printf("enter radius: ");
    scanf("%d",&r);
    printf("area of a circle is %f",area(r));
    return 0;
}
