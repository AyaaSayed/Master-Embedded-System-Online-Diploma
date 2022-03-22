int main()
{
   int i,num;
   printf("enter num:");
   scanf("%d",&num);
   printf("the factors of num is\n");
   for(i=1; i<=num; i++)
   {
       if(num%i==0)
        printf("%d ",i);
   }
    return 0;
}
