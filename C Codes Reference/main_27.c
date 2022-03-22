char max_ones(char num)
{
char count=0;
while(num!=0)
{
  num=(num &(num<<1));
  count++;
}

 return count;
}
int main()
{
  printf("max ones are %d",max_ones(20));
 return 0;
}

