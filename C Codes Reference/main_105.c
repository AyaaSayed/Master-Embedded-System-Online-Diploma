
//if x=0->y=a;
//if x=2->y=b;
int assignValue(int a, int b, int x)
{
    int y;
    int arr[2];
    arr[0] = a;
    arr[1] = b;
     y = arr[x];

    return y;
}

int main()
{
    int a = 5;
    int b = 10;
    int x;
   printf("enter value of x:");
   scanf("%d",&x);
    printf("assigned value to y is %d",assignValue(a,b,x));
    return 0;
}
/*// second method:
int assignValue(int a, int b, int c)
{
    return ((1 - c) * a) + (c * b);
}

int main()
{
   int a = 5, b = 10, c = 0;
   int x = assignValue(a, b, c);
   printf("assigned value to y is %d",x);
   return 0;
}
