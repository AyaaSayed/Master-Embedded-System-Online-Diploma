int max_numbers(int a, int b)
{
    int max;
    max=(a>b)?a:b;
  return max;
}
int main()
{
int a,b,max;
printf("enter two numbers:");
scanf("%d %d",&a,&b);
max=max_numbers(a,b);
printf("max is %d",max);
    return 0;
}

