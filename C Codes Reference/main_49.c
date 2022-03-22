#define bits sizeof(num)*8
void count_zeros_ones(int num, int *ones, int *zeros)
{
int i;
*ones=0;
*zeros=0;
for(i=0; i<bits-1; i++)
{
    if((num>>i) &1)
    {
        ++*ones;
    }
    else
        ++*zeros;
}

}
int main()
{
int num,ones,zeros;
printf("enter num:");
scanf("%d",&num);
count_zeros_ones(num,&ones,&zeros);
printf("number of zeros is %d\nno of ones is %d",zeros,ones);
    return 0;
}

