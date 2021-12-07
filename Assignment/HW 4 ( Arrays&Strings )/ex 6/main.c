#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char c[20],ch;
    int i,counter=0;
    printf("enter a string: ");
    gets(c);
    fflush(stdin);fflush(stdout);
    printf("enter a character to find frequancy: ");
    scanf("%c",&ch);
    //fflush(stdout);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]==ch)
        {
            counter++;
        }
    }//printf("%d",strlen(c));
    printf("frequancy of %c = %d",ch,counter);
    return 0;
}
