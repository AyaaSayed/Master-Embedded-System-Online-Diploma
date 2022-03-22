
int zeros_max(unsigned long long num)
{
    unsigned int i,j,mask=0x80000000;
    unsigned int max_zeros=0,count_zeros=0;
    for(i=0; i<32; i++)
    {
        if((num<<i) & mask)
        {
        for(j=i+1; j<32; j++)
        {
                   if((num<<j) &mask)
                   {
                       if(count_zeros>max_zeros)
                       {
                           max_zeros=count_zeros;
                       }
                       count_zeros=0;
                       break;
                   }
                   else
                   {
                       count_zeros++;
                   }

        }

        }
    }
    return max_zeros;
}
int main()
{
printf("max zeros is %d",zeros_max(296384));
    return 0;
}
/*// second method:
 int max_zeros(unsigned int num)
{
int max=0,zeros=0;
unsigned int mask=1;
while(num)
{
    if((num&mask)==0)
        zeros++;
    else
    {
        if(zeros>max)
        {
            max=zeros;
            zeros=0;
        }
    }
    num>>=1;
}
return max;
}
int main()
{
    printf("%d",max_zeros(17));
    return 0;
}

