
unsigned short reverse_digits(unsigned short num)
{
    unsigned short new_num=0,rem;
    while(num!=0)
    {
       rem=num%10;
       new_num=10*new_num+rem;
       num/=10;
    }
    return new_num;
}
int main()
{
    unsigned short num;
    printf("enter your num:");
    scanf("%hu",&num);
    printf("sum of digits is is %hu",reverse_digits(num));
 return 0;
}
/*// recursion method:
unsigned short reverse_digits(unsigned short num)
{
    static unsigned short new_num=0;
    int rem;
    if(num!=0)
    {
       rem=num%10;
       new_num=10*new_num+rem;
       reverse_digits(num/10);
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
    printf("reverse num is %hu",reverse_digits(num));
 return 0;
}*/
