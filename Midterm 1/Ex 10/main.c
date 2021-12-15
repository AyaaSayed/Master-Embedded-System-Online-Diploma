#include <stdio.h>
#include <stdlib.h>
int x=0,m=1,arr[32],array[32],i=0;
int* p=arr;

int max(int array,int m)
{
    int* p=array,i=0;
    while(i<10)
    {
        if(m>*(p+i));
        else
            m=*(p+i);
        ++i;
    }
    printf("The longest consecutive occurrence of %d is %d",1,m);
}
int count(int* p)
{
    int y=0;
    p=x+arr;
    while(x<32)
    {
       x++;
       while(*p==1)
       {
           y++;x++;
           while(*(p+1)!=1){return y;}
           p++;
       }p++;
    }
}

int binary(unsigned int num)
{
    printf("the binary number of %d is ",num);
    for(i=0;i<32;i++)
    {
        if(num<<i & 1<<31)
        {
            printf("1");
            arr[i]=1;
        }
        else
        {
            printf("0");
            arr[i]=0;
        }
    }
    printf("\n");

    int *P=arr;
    for(i=0;x<32;i++)
    {
        array[i]=count(p);
        m=array[i];
    }
    max(array,m);
}

int main()
{
    unsigned int num;
    printf("input: ");
    scanf("%d",&num);
    binary(num);
    return 0;
}
