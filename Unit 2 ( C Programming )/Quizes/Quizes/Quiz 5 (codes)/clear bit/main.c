#include <stdio.h>
#include <stdlib.h>

int clear_bit(int a,int b)
{
    return a &=~(1<<b);
}

int main()
{
    int a,b;
    printf("Input number: ");
    scanf("%d",&a);
    printf("Bit position: ");
    scanf("%d",&b);
    printf("result: %d",clear_bit(a,b));
    return 0;
}
