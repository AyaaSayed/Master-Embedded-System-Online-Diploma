#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("enter an alphabet: ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a'...'z':
        case 'A'...'Z':
            {
                printf("%c is alphabet",ch);
            }break;
        default:
            {
                printf("%c isn't alphabet",ch);
            }break;
    }
    return 0;
}
