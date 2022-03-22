int main()
{
  int a[10],num,rem,i=0,sum=0;
  printf("enter num:");
  scanf("%d",&num);
  while(num!=0)
  {
      rem=num%10;
      a[i]=rem;
      num/=10;
      i++;
  }
  sum=a[i-1]+a[0];
  printf("first digit is %d\nlast digit is %d\n",a[i-1],a[0]);
  printf("sum=%d",sum);
    return 0;
}
/*// another method:
int main()
{
  int num,c=0,first_digit,last_digit,n;
  printf("enter num:");
  scanf("%d",&num);
  n=num;
  last_digit=num%10;
  while(n!=0)
  {
     //rem=num%10;
     c++;
     n=n/10;
  }
  first_digit=(int)num/(pow(10,c-1));
  printf("first digit is %d\nlast digit is %d\n",first_digit,last_digit);
    return 0;
}

