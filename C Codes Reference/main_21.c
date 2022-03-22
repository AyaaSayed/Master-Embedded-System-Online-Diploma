
void swap2zeros(int *a, int size)
{
    int i,p1,temp[3],p2,j=0;
    //get the position of twp zeros
    for(i=0; i<size; i++)
    {
        if(a[i]==0)
        {
           j++;
           if(j==2)
           {
              p2=i;
           }
           else
           {
               p1=i;
           }
        }
    }
    //store the 3 elements after zero one in temp array
    for(i=0; i<3; i++)
    {
        temp[i]=a[p1+1+i];
    }
    //overwrite the 3 elements after second zero on 3 elements after first zero
        for(i=0; i<3; i++)
        {
            a[p1+i+1]=a[p2+i+1];
        }
        //overwrite the elements in temp array on the 3 elements after second zero
        for(i=0; i<3; i++)
        {
            a[p2+1+i]=temp[i];
        }

}
int main()
{
   int a[]={1,2,5,0,3,4,5,6,10,0,30,40,50,60,80,100},size,i;
   size=sizeof(a)/sizeof(*a);
   swap2zeros(a,size);
   for(i=0; i<size; i++)
   printf("%d ",a[i]);
    return 0;
}
