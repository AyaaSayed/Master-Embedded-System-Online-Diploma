
char count_ones(int num)
{
    char count=0;
    int i;
     for(i=0; i<32; i++)
    {
        if(num &(1<<i))
            count++;

    }
    return count;
}
int main()
{
    int num;
    printf("enter your num:");
    scanf("%d",&num);
    printf("count of ones is %d",count_ones(num));
 return 0;
}

