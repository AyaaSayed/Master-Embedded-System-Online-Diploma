int main()
{
  int i,space,rows,k,count=0,count1=0;
  printf("enter number of rows:");
  scanf("%d",&rows);
  for(i=1; i<=rows; i++)
  {
      for(space=1; space<=rows-i; space++)
      {
          printf(" ");
          count++;
      }
      for(k=0; k!=2*i-1; k++)
      {
          if(count<=rows-1)
          {
              printf("%d",i+k);
              count++;
          }
          else
          {
              count1++;
              printf("%d",(i+k-2*count1));
          }
      }
      count1=count=k=0;
      printf("\n");

  }
  return 0;
}
