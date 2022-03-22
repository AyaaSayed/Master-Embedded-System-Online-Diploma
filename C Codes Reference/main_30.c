
void display_binary(unsigned char num)
{
   char i;
   for(i=7; i>=0; i--)
   {
    (num &(1<<i))?printf("1"):printf("0");

   }
}
unsigned char reverse_bits(unsigned char num)
{
    unsigned char i,temp=0;
    for(i=0; i<8; i++)
    {
           if(num&(1<<i))
            temp|=1<<(7-i);
    }
    return temp;
}
int main()
{
  unsigned char num=149;
  printf("num in decimal is %d\n",num);
  display_binary(num);
  printf("\nnum in binary is\n");
  unsigned char ret=reverse_bits(num);
  printf("\nreverse in decimal is %d\n",ret);
  printf("\nreverse in decimal is \n");
  printf("\n");
  display_binary(ret);
    return 0;
}
