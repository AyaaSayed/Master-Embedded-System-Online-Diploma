#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void swap_elements(int *a, int *b)
{
    *a^=*b;
    *b^=*a;
    *a^=*b;
}
void my_fun( int *a, int *b,int s1, int s2)
{
int c[2*MAX],s3,i,j,count=0;
s3=s1+s2;
for(i=0; i<s1; i++)
{
    c[count]=a[i];
    count++;
}
for(i=0; i<s2; i++)
{
    c[count]=b[i];
    count++;
}

for(i=0; i<s3-1; i++)
{
    for(j=i+1; j<s3; j++)
    {
        if(c[i]>=c[j])
        {
         swap_elements(&c[i],&c[j]);
        }
    }
}
if(s3%2!=0)
{
   for(i=1; i<s3; i=i+2)
   {
      swap_elements(&c[i],&c[i+1]);
   }
}
else
{
 for(i=1; i<s3; i=i+2)
   {
       if(i==9)
        break;
       else
      swap_elements(&c[i],&c[i+1]);
   }
}
printf("\nzigzag array is\n");
for(i=0; i<s3; i++)
    printf("%d ",c[i]);
}
int main()
{
    int a[MAX],b[MAX],s1,s2,i;
    printf("enter s1:");
    scanf("%d",&s1);
    printf("enter s2:");
    scanf("%d",&s2);
    for(i=0; i<s1; i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
     for(i=0; i<s2; i++)
    {
        printf("b[%d]=",i);
        scanf("%d",&b[i]);
    }
    my_fun(a,b,s1,s2);

    return 0;
}
