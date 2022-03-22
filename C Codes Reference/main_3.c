

void prime(int num1, int num2)
{
    int i,flag,num;
    for(num=num1; num<=num2; num++)
    {
        flag=0;
        for(i=2; i<=num/2; i++)
        {
            if(num%i==0)
            {
                flag++;
                break;
            }
        }
        if(flag==0)
        printf("%d ",num);
    }
}
int main()
{
    int num1,num2;
    printf("enter your num1:");
    scanf("%d",&num1);
     printf("enter your num2:");
    scanf("%d",&num2);
   prime(num1,num2);
 return 0;
}
