
//with typdef:
typedef int(*comp)(int,int);
void swap_elemnts(int *a, int *b)
{
        *a^=*b;
        *b^=*a;
        *a^=*b;


}
int compare(int a, int b)
{
    if(a>b)
        return 1;
    return -1;
}
void sort_fun(int *a, int size,comp c )
{
    int i, j ;
    for(i = 0; i < size-1; i++)
        {
        for(j = i + 1; j < size; j++)
        {
            if(c(a[i],a[j])>0)
            {
              swap_elemnts(&a[i],&a[j]);
            }
        }

    }
}
int main()
{
    int a[]={7,2,4,9,3,1},i,size;
   size=sizeof(a)/sizeof(*a);
   sort_fun(a,size,compare);
   for(i=0; i<size; i++)
    printf("%d ",a[i]);
    return 0;
}
/*// without typdef:
void swap_elemnts(int *a, int *b)
{
        *a^=*b;
        *b^=*a;
        *a^=*b;


}
int compare(int a, int b)
{
    if(a>b)
        return 1;
    return -1;
}
void sort_fun(int *a, int size, int(*compare)(int,int) )
{
    int i, j ;
    for(i = 0; i < size-1; i++)
        {
        for(j = i + 1; j < size; j++)
        {
            if(compare(a[i],a[j])>0)
            {
              swap_elemnts(&a[i],&a[j]);
            }
        }

    }
}
int main()
{
    int a[]={7,2,4,9,3,1},i,size;
   size=sizeof(a)/sizeof(*a);
   sort_fun(a,size,compare);
   for(i=0; i<size; i++)
    printf("%d ",a[i]);
    return 0;
}
