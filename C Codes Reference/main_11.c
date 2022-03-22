
int sum_Nos(unsigned int n)
{
    static int sum=0;
    if(n > 0)
    {
        sum_Nos(n - 1);
        sum=sum+n;
    }
    return sum;;
}
int main()
{
    int ret=sum_Nos(100);
    printf("sum=%d",ret);
    getchar();
    return 0;
}

