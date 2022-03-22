int addnum(int a, int b)
{
    return a+b;
}
int subnum(int a, int b)
{
    return a-b;
}
int mulnum(int a, int b)
{
    return a*b;
}
int main()
{
 int choice,num1,num2;
 int (*pf[3])(int,int)={addnum,subnum,mulnum};
 printf("enter choice 0 for int and 1 for sub and 2 for mul:");
 scanf("%d",&choice);
 printf("enter data1:");
 scanf("%d",&num1);
 printf("enter data2:");
 scanf("%d",&num2);
 int ret=(*pf[choice])(num1,num2);
 printf("%d",ret);
    return 0;
}

