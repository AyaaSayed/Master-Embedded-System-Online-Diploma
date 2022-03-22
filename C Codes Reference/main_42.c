
int max_numbers(int x, int y,int z)
{
    int max;
    max=((x)>(y))?((x)>(z))?x:z:((y)>(z))?y:z;     //or     max=(x>y && x>z)?x:(y>z)?y:z;

  return max;
}
int main()
{
int a,b,c,max;
printf("enter two numbers:");
scanf("%d %d %d",&a,&b,&c);
max=max_numbers(a,b,c);
printf("max is %d",max);
    return 0;
}
