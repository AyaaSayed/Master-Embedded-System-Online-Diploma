#define bits sizeof(num)*8
int count_trailingzeros(int num)
{
int i,count=0;
for(i=0; i<bits-1; i++)
{
    if((num>>i) &1)
    {
        break;
    }
    else
        count++;
}
return count;

}
int main()
{
int num;
printf("enter num:");
scanf("%d",&num);
int ret=count_trailingzeros(num);
printf("number of trailing zeros is %d",ret);
    return 0;
}
