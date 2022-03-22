
void display_binary(unsigned char num)
{
   char i;
   for(i=7; i>=0; i--)
   {
    (num &(1<<i))?printf("1"):printf("0");

   }
}
unsigned char reverse_4bits(unsigned char num)
{
    return num>>4 | num<<4;
}
int main()
{
  unsigned char num=149;
  printf("num in decimal is %d\n",num);
  display_binary(num);
  printf("\nnum in binary is\n");
  unsigned char ret=reverse_4bits(num);
  printf("\nreverse in decimal is %d\n",ret);
  printf("\nreverse in decimal is \n");
  printf("\n");
  display_binary(ret);
    return 0;
}
