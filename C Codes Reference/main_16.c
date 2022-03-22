
// first method:using pointers
void search_for_num(int *a, int size,int *max, int *min, int *index_of_max, int *index_of_min)
{
    *max=a[0];
    *min=a[0];
    int i;
    for(i=0; i<size; i++)
    {
        if(*max<=a[i])
        {
            *max=a[i];
            *index_of_max=i;
        }
        if(*min>=a[i])
        {
            *min=a[i];
            *index_of_min=i;
        }
    }
}
int main()
{
    int a[5]={13,8,10,12,15},size,max,min,max_index,min_index;
    size=sizeof(a)/sizeof(*a);
    search_for_num(a,size,&max,&min,&max_index,&min_index);
    printf("max is %d and it's position is %d\nmin is %d and it's position is %d",max,max_index,min,min_index);
    return 0;
}
/*// second method:using structure
struct max_min
{
    int max;
    int min;
    int max_index;
    int min_index;
};
struct max_min search_for_num(int *a, int size )
{
  struct max_min Max_Min;
  Max_Min.max=a[0];
  Max_Min.min=a[0];
  int i;
  for(i=0; i<size; i++)
  {
      if(Max_Min.max<=a[i])
      {
          Max_Min.max=a[i];
          Max_Min.max_index=i;
      }
       if(Max_Min.min>=a[i])
      {
          Max_Min.min=a[i];
          Max_Min.min_index=i;
      }
  }
  return Max_Min;
}
int main()
{
    int a[5]={3,8,10,12,15},size;
    size=sizeof(a)/sizeof(*a);
    struct max_min Max_Min=search_for_num(a,size);
     printf("max is %d and it's position is %d\nmin is %d and it's position is %d",Max_Min.max,Max_Min.max_index, Max_Min.min,Max_Min.min_index);
    return 0;
}
