
/*int squarRoot(int num)
{
    int res=0;
    if(num==0 || num==1)
        return num;
    while(res*res<=num)    //if 5th root (res*res*res*res*res<=num)
    {
        res++;
    }
    return res-1;

}
int main()
{
    printf("square root is %d",squarRoot(11));
   return 0;
}*/
// Another method:
double SquareRoot(int number)
{
 if(number==0 || number==1)
        return number;
    double temp, sqrt;
    sqrt = number / 2;
    temp = 0.0;
    while(sqrt != temp)
    {
        temp = sqrt;
        sqrt = ( number/temp + temp) / 2;
    }
    return sqrt;
}
int main()
{
   int number;
    printf("Provide the number: \n");
    scanf("%d", &number);
    printf("The square root of '%d' is '%lf'", number, SquareRoot(number));
    return 0;
}
