#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int len,i,j,k;
char str[20],s1[10],s2[10];

void print(char str[],int len)
{
    for(i=0;i<len;i++)
    {
        printf("%c",str[i]);
    }
}

void replace(char s1[],char s2[],int len,int j)
{
    for(i=0;i<j;i++)
    {
        str[i]=s2[i];
    }
    str[i]=32;
    for(i=0;i<len-j-1;i++)
    {
        str[j+i+1]=s1[i];
    }
    print(str,len);
}

void cat(char str[],int len)
{
    for(i=0;i<len;i++)
    {
        if(str[i]!= 32)                 //32 is ASCII value of ' '
            s1[i]=str[i];
        if(str[i]== 32)
        {
            s1[i]=0;
            j=i;
            break;
        }
    }
    for(k=0;k<len-j-1;k++)
    {
        s2[k]=str[j+k+1];
    }
    replace(s1,s2,len,k);
}

int main()
{
    printf("enter a string: ");
    gets(str);
    len=strlen(str);
    cat(str,len);
    return 0;
}
