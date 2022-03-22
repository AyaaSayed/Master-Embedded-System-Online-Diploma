
char *print_binary(int num)
{
    (num &(1<<i))? printf("1") :  printf("0");
}
int main()
{
    int num;
    printf("enter num:");
    scanf("%d",&num);
    print_binary(num);
 return 0;
}
