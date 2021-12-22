#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main()
{
    char str[50],flag;
    printf("enter your user name: ");
    gets(str);
    flag = stricmp(str,"Aya Sayed");
    (flag==0)?printf("are the same"): printf("not the same");
    return 0;
}
