
#define bits sizeof(num)*8
int lowest_set_order(int num)
{
int i,order=-1;
for(i=0; i<bits-1; i++)
{
    if((num>>i) &1)
    {
        order=i;
       // break;
    }
}
return order;

}
int main()
{
int num;
printf("enter num:");
scanf("%d",&num);
int ret=lowest_set_order(num);
(ret!=-1)?printf("lowest set bit in inedex %d",ret):printf("no set bits");
    return 0;
}
