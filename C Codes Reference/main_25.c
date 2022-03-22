
int big_diff(int *a, int size)
{
    int i,small,big,small_index;
    small=a[0];
    for(i=1; i<size; i++)
    {
        if(small>=a[i])
        {
            small=a[i];
            small_index=i;
        }
    }
       big=a[0];
       for(i=1; i<size; i++)
       {
           if(big<=a[i])
           {
               big=a[i];
           }
       }
         printf("small=%d\n",small);
        printf("big=%d\n",big);

    return big-small;
}
int main()
{
int a[]={10,1,5,3,6,8,7,2},size;
size=sizeof(a)/sizeof(*a);
printf("big diff is %d",big_diff(a,size));
    return 0;
}
