
//first method:iteration
int factorial(int n)
{
    int prod=1;;
    while(n!=0)
    {
        prod*=n;
        --n;
    }
    return prod;
}
int main()
{
    int num;
    printf("enter your num:");
    scanf("%d",&num);
    printf("factorial=%d",factorial(num));
    return 0;
}
/*// second method:recursive
int factorial( int n)
{
    if(n<=0)
    {
        return 1;
    }
    return n*factorial(n-1);
}
int main()
{
    int num;
    printf("enter your num:");
    scanf("%d",&num);
    printf("factorial=%d",factorial(num));
    return 0;
}
