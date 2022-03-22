
void check_even_odd(int num)
{
     (num&1)?printf("%d is odd",num):printf("%d is even",num);

    // or (num%2!=0)?printf("%d is odd",num):printf("%d is even",num);
}
int main()
{
int num;
printf("enter num:");
scanf("%d",&num);
check_even_odd(num);
    return 0;
}
