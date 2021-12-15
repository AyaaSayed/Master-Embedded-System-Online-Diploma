#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i;                                              //assume int size is 2 byte
    char ch[16];
    printf("enter a number: ");
    scanf("%d",&x);
    ((x&8)==0)?printf("forth bit of %d is 0\n",x):printf("forth bit of %d is 1\n",x);
    for(i=0;i<16;i++)
    {
        do                         //this way will print binary number as b0 b1...b15
        {
            ((x%2)==1)?printf("1"):printf("0");
            x=x/2;
        }while((x/2) !=0);
    }


    return 0;
}
