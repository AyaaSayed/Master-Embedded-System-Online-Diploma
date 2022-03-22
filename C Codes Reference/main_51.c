unsigned rotate_right(unsigned int num, unsigned bit_num)
{
    unsigned new_num;
     new_num= (num<<bit_num) | (num>>(bits-bit_num));
     return new_num;
}
int main()
{
unsigned int num,no_of_rotate;
printf("enter num:");
scanf("%x",&num);
printf("enter no of rotate:");
scanf("%u",&no_of_rotate);
printf("\n");
unsigned int new_num= rotate_right(num,no_of_rotate);
printf("0x%x\n",new_num);

    return 0;
}
