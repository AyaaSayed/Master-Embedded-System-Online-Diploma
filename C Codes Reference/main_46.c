#define bits sizeof(num)*8
int highest_set_order(int num)
{
int i,order=-1;
for(i=0; i<bits-1; i++)
{
    if((num>>i) &1)
    {
        order=i;
        break;
    }
}
return order;

}
int main()
{
int num;
printf("enter num:");
scanf("%d",&num);
int ret=highest_set_order(num);
(ret!=-1)?printf("highest set bit in inedex %d",ret):printf("no set bits");
    return 0;
}

