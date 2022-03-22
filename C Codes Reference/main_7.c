//first method:
enum Boolean{false,true};
char check_base2(unsigned short num)
{
    if(num!=0 && (num&(num-1))==0)
        return true;
    return false;
}
int main()
{
    unsigned short num;
    printf("enter your num:");
    scanf("%hu",&num);
    char ret=check_base2(num);
    (ret==true)?printf("%hu is base 2",num):printf("%hu is not base 2",num);
 return 0;
}/*// second method:
void check_base2(int num)
{
    int i,c=0;
    for(i=0; i<8; i++)
    {
        if(num &(1<<i))
        {
            c++;
        }
    }
   if(c==1)
    printf("number is base 2");
   else
    printf("number is not base 2");
}
int main()
{
    int num;
    printf("enter num:");
    scanf("%d",&num);
check_base2(num);
    return 0;
}

