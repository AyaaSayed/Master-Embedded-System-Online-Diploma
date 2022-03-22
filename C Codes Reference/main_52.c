void binary_num(unsigned int num)
{
    int i;
    for(i=31; i>=0; i--)
    {
        if((num>>i) &1)
            printf("1");
        else
            printf("0");
    }
}
