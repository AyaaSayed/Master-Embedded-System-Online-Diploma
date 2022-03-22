
#include <stdio.h>
#include <assert.h>
unsigned char add(unsigned char num2, unsigned char num1 )
{

  assert(num1+num2<=255); //will print error if num+num2>255
  return num1+num2;     //else print sum;
}
int main()
{
    unsigned char n1=200,n2=120;
    unsigned char ret;
    ret=add(n1,n2);
    printf("sum=%d",(unsigned char)ret);
    return 0;
}

/*// the problem is when the summation is greater than 255,there will be overflow.
// the solution we store the result in unsigned short
unsigned short add(unsigned char num2, unsigned char num1 )
{
  unsigned short sum=num1+num2;
  return sum;
}
int main()
{
    unsigned char n1=150,n2=200;
    unsigned short ret;
    ret=add(n1,n2);
    printf("sum=%hu",ret);
    return 0;
}
