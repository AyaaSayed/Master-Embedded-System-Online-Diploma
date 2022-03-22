int Neares10th_number(int num)
{
    int rem;
    rem=num%10;
    if(rem>=5)
        return num+(10-rem);
    return num-rem;
}
int main()
{
    int num;
    printf("enter your num:");
    scanf("%d",&num);
    printf("nearst 10th number is %d",Neares10th_number(num));
 return 0;
}
