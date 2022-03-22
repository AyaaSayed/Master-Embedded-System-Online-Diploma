int main()
{
  int num,flag,i,sum=0;
  for(num=1; num<=10; num++)
  {
      flag=1;
      for(i=2; i<=num/2; i++)
  {
      if(num%i==0)
      {
          flag++;
          break;
      }
  }
  if(flag==1)
  {
      sum+=num;
  }
  }
  printf("sum=%d",sum);
    return 0;
}
