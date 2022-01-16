#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("enter an alphabet: ");
    scanf("%c",&ch);
    if((ch=='a')||(ch=='i')||(ch=='u')||(ch=='e')||(ch=='o'))
        printf("%c is a vowel",ch);
    else
        printf("%c is a consonant",ch);
    return 0;
}
