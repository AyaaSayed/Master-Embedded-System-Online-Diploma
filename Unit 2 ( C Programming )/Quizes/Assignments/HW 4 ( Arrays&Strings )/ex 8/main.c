#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[20],ch[20];
    printf("enter the string: ");
    gets(c);
    int i,j=strlen(c);
    printf("reversed string is: ");
    for(i=0;i<j;i++)
    {
        ch[i]=c[j-i-1];
        printf("%c",ch[i]);
    }
    return 0;
}
