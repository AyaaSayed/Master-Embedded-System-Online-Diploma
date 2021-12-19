#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
    char str[50],*ptr;
    printf("enter a string: ");
    fflush(stdin); gets(str); fflush(stdout);
    int i=strlen(str);
    ptr=str+i;
    printf("Reversed string is: ");
    while(i>=0)
    {
        printf("%c",*ptr);
        ptr--;i--;
    }
    return 0;
}
