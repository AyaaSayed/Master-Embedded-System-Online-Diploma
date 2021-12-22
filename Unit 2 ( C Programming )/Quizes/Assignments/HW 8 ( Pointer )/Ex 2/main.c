#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a = 'A';
    char* ptr = &a;
    printf("The Alphabets are: \n");
    while(*ptr != '[')
    {
        printf("%c  ",*ptr);
        a++;
    }
    return 0;
}
