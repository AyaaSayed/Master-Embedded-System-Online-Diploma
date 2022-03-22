
void my_fun(int a[], int size, int *b)
{
 int i,j,c;
 for(i=0; i<size; i++)
 {
     c=1;
     for(j=i+1; j<size; j++)
     {
         if(a[i]==a[j])
         {
           b[j]=0;
           c++;
         }
     }
     if(b[i]!=0)
     {
         b[i]=c;
     }
 }
 for(i=0; i<size; i++)
 {
     if(b[i]!=0 && b[i]%2!=0)
        printf("unique elements are %d\n",a[i]);
 }
}

/* Driver program to test above function */
int main()
{
  int a[]={1,2,3,1,4,3,2},b[]={-1,-1,-1,-1,-1,-1},size;
  size=sizeof(a)/sizeof(*a);
  my_fun(a,size,b);
    return 0;
}
