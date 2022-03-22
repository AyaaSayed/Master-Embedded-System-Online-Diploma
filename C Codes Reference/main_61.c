int main()
{
   int n1,n2,i,GCD,min;
   printf("enter num1:");
   scanf("%d",&n1);
   printf("enter num2:");
   scanf("%d",&n2);
   min=(n1>n2)?n2:n1;
    for(i=1; i<=min; i++)
    {
        if(n2%i==0 && n1%i==0)
        GCD=i;

    }


   printf("GCD=%d",GCD);
    return 0;
}
