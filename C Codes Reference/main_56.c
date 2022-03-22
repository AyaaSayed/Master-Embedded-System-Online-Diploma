int main()
{
  int num,new_num=0,rem,n;
  printf("enter num:");
  scanf("%d",&num);
  n=num;
  while(n!=0)
  {
      rem=n%10;
      new_num=10*new_num+rem;
      n=n/10;
  }
  if(num==new_num)
  printf("number is palindrome");
  else
    printf("number is not palindrome");
    return 0;
}

