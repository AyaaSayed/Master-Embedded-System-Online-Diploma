#include <stdio.h>
#include <stdlib.h>
int binary(unsigned int num)
{
    int i,counter=0;
    printf("the binary number of %d is ",num);
    for(i=0;i<32;i++)
    {
        if(num<<i & 1<<31)
        {
            printf("1");
            ++counter;
        }
        else
            printf("0");
    }
    printf("number of ones is %d",counter);
}
int main()
{
    unsigned int num;
    printf("input: ");
    scanf("%d",&num);
    binary(num);

    return 0;
}
