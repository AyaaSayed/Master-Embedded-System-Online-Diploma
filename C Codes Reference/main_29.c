#define MAX_size 100
int *merge(int *a, int *b, int s1,int s2, int *s3)
{
   static int c[MAX_size];
   int i,j,count=0;
   *s3=s1+s2;
   if(*s3%2==0)
   {
       for(i=0,j=0;i<*s3;i=i+2)
       {
           c[i]=a[count];
           c[i+1]=b[j];
           count++;
           j++;
       }
   }
   else
   {
     for(i=0,j=0;i<*s3;i=i+2)
       {
           c[i+1]=b[j];
           if(i==(*s3-1))
           {
               c[i]=b[j];
               break;
           }
           c[i]=a[count];
           count++;
           j++;
       }
   }
   return c;
}
int main()
{
    int a1[]={1,2,3,4,5},a2[]={11,12,13,14,15},s1,s2,s3,*p,i;
    s1=sizeof(a1)/sizeof(*a1);
    s2=sizeof(a2)/sizeof(*a2);
    p=merge(a1,a2,s1,s2,&s3);
    for(i=0; i<s3; i++)
        printf("%d ",p[i]);
    return 0;
}

/*// another solution:
void my_fun(int *a1, int *a2, int *a3, int size)
{
 int i=0,j=0,k=0,c=0,s=2*size;
 while(i<s)
 {
    a3[c]=a1[j];
    c++;
    j++;
    a3[c]=a2[k];
    c++;
    k++;
    i=i+2;
 }
}

int main()
{
    int a1[]={1,2,3,4,5},a2[]={11,12,13,14,15},size,a3[30]={0},i;
    size=sizeof(a2)/sizeof(a1[0]);
    my_fun(a1,a2,a3,size);
    for(i=0; i<2*size; i++)
    printf("%d ",a3[i]);
    return 0;
}
