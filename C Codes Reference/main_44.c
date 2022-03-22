
void check_alphabet(char num)
{
     ((num>='a' && num<='z')||(num>='A' && num<='Z') )?printf("%c is an alphabet",num):printf("%c is not alphabet",num);

}
int main()
{
char num;
printf("enter char:");
scanf("%c",&num);
check_alphabet(num);
    return 0;
}
