#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[20];
    int i,counter=0;
    printf("enter a string: ");
    gets(c);
    for(i=0;i<20;i++)
    {
        if(c[i]== '\0'){printf("lendth of string: %d",counter);break;}
        counter++;
    }
    return 0;
}
