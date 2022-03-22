
int main()
{
   int base,exponent,prod=1;
   printf("enter base and exp:");
   scanf("%d %d",&base,&exponent);
   while(exponent!=0)
   {
       prod*=base;
       exponent--;
   }
   printf("power is %d",prod);
    return 0;
}
