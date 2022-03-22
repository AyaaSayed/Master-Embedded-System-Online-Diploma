
int Max_Xor(int a, int b)
{
   int i,j,temp=0,max_xor=0;
   for(i=a; i<=b; i++)
   {
       for(j=i; j<=b; j++)
       {
           temp=i^j;
           if(temp>max_xor)
            max_xor=temp;
       }
   }
   return max_xor;
}
int main()
{
  int A,B;
  printf("enter A:");
  scanf("%d",&A);
  printf("enter B:");
  scanf("%d",&B);
   int ret=Max_Xor(A,B);
   printf("max xor=%d",ret);
	return 0;
}
