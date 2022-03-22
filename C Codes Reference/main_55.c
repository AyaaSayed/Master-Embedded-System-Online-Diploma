int main()
{
  int num,first,last,c=0,swap,n;
  printf("enter num:");
  scanf("%d",&num);
  n=num;
  last=n%10;
  while(n!=0)
  {
      c++;
      n=n/10;
  }
  first=(int)num/pow(10,c-1);
  swap=(last*pow(10,c-1)+first)+(num-(first*pow(10,c-1)+last));
  printf("first=%d\nlast=%d\n",first,last);
  printf("number after swapping is %d",swap);
    return 0;
}

