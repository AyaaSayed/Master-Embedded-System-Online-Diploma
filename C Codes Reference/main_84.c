
int Convert_Little_To_BigEndian( int num)
{
   return (((num&0x000000ff)<<24) | ((num&0x0000ff00)<<8) |((num&0x00ff0000)>>8) | ((num&0xff000000)>>24));

}
int main()
{
    int num;
    printf("enter num:");
    scanf("%X",&num);
    int ret=Convert_Little_To_BigEndian(num);
    printf("0x%X",ret);
    return 0;
}
