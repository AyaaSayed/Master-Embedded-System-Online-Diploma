
void delete_repeted_element(int *a, int size)
{
  int b[10],i,j,count=0;
  for(i=0; i<size; i++)
  {
      for(j=0; j<count; j++)
      {
          if(a[i]==b[j])
            break;
      }
      if(j==count)
      {
          b[count]=a[i];
          count++;
      }
  }
  printf("the array after deleting element is\n");
  for(i=0; i<count; i++)
    printf("%d ",b[i]);
}
int main()
{
 int a[]={4,7,5,7,8,4,9},size;
 size=sizeof(a)/sizeof(*a);
 delete_repeted_element(a,size);
    return 0;
}
