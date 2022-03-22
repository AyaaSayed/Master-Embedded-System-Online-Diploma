void swap_arrays(int *a, int *b, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        a[i]^=b[i];
        b[i]^=a[i];
        a[i]^=b[i];


    }
}
void reverse_array(int *a,int *b, int size )
{
  int i,a1[10],a2[10],c=0;
  for(i=0; i<size; i++)
  {
      a1[c]=a[size-1-i];
      a2[c]=b[size-1-i];
      c++;
  }
  for(i=0; i<size; i++)
  {
      a[i]=a1[i];
      b[i]=a2[i];
  }
}
int main()
{
    int a[]={1,2,3,4,5},b[]={10,20,30,40,50},size,i;
    size=sizeof(a)/sizeof(*a);
    swap_arrays(a,b,size);
    reverse_array(a,b,size);
         printf("\ntwo arrays after swapping and reversing are\n");
    for(i=0; i<size; i++)
        printf("%d ",a[i]);
    printf("\n");
     for(i=0; i<size; i++)
        printf("%d ",b[i]);
    return 0;
}
