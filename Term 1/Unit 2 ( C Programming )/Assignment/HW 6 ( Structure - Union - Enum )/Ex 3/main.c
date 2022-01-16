#include <stdio.h>
#include <stdlib.h>
struct Scomplex
{
    int r_num;   //Real Number
    int i_num;   //Imaginary Number
};

struct Scomplex readcomplex(char name[])
{
    struct Scomplex complexx;
    printf("enter %s as 5,-3 for example: ",name);
    scanf("%d,%d",&complexx.r_num,&complexx.i_num);
    return complexx;
}

struct Scomplex addcomplex(struct Scomplex A,struct Scomplex B)
{
    struct Scomplex sum;
    sum.r_num = A.r_num + B.r_num;
    sum.i_num = A.i_num + B.i_num;
    return sum;
}

void printcomplex(char name[],struct Scomplex S)
{
    printf("%s: (%d)+(%d)",name,S.r_num,S.i_num);
}

int main()
{
    struct Scomplex A = readcomplex("1st complex number");
    struct Scomplex B = readcomplex("2nd complex number");
    struct Scomplex S = addcomplex(A,B);
    printcomplex("Result of adding two complex number is",S);
    return 0;
}
