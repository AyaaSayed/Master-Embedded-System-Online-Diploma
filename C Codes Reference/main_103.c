typedef int (*pf)(int,int);
int arithmetic(int data1, int data2,pf calculation )
{
  int iret=calculation(data1,data2);
  return iret;
}
int addfun(int num1, int num2)
{
   return num1+num2;
}
int subfun(int num1, int num2)
{
    return num1-num2;
}
int main()
{
    int n1=20,n2=10,choice,ret;
    while(1)
    {
        printf("\nenter choice 1 for add and 2 for sub:");
        scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
           ret=arithmetic(n1,n2,addfun);
            printf("\nsum of numbers:%d",ret);
            break;
        case 2:
             ret=arithmetic(n1,n2,subfun);
             printf("\nsub of numbers:%d",ret);
             break;
        case 3:
            exit(0);
        }
    }
    return 0;
}

