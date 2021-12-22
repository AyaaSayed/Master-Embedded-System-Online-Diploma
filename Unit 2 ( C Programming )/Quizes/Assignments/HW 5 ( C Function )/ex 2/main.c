#include <stdio.h>
#include <stdlib.h>

int factorial(int x)
{
    while(x>1)
        return x*factorial(x-1);
}

int main()
{
    int x;
    printf("enter an positive number: ");
    scanf("%d",&x);
    printf("Factorial of %d is %d",x,factorial(x));
    return 0;
}
