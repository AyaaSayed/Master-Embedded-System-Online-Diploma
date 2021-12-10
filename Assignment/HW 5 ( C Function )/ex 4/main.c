#include <stdio.h>
#include <stdlib.h>

int power(int x,int p)
{
    while(p>1)
    {
        return x*power(x,--p);
    }
}

int main()
{
    int x,p;
    printf("enter base number: ");
    scanf("%d",&x);
    printf("enter power number(positive integer): ");
    scanf("%d",&p);
    printf("%d^%d = %d",x,p,power(x,p));
    return 0;
}
