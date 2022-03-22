
// first method:
int sum_digits(int num)
{
    int sum=0,rem;
    while(num!=0)
    {
       rem=num%10;
       sum+=rem;
       num/=10;
    }
    return sum;
}
int main()
{
    int num;
    printf("enter your num:");
    scanf("%d",&num);
    printf("sum of digits is is %d",sum_digits(num));
 return 0;
}
/*// second method:
unsigned short sum_digits(unsigned short num)
{
    static unsigned short new_num=0;
    int rem;
    if(num!=0)
    {
       rem=num%10;
       new_num+=rem;;
       sum_digits(num/10);
    }
    else
        return 0;
    return new_num;
}
int main()
{
    unsigned short num;
    printf("enter your num:");
    scanf("%hu",&num);
    printf("sum of digits is is %hu",sum_digits(num));
 return 0;
}*/
