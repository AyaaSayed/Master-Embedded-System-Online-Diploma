
void swaping(int *a, int *b)
{
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

int main()
{
int a,b;
printf("enter two number:");
scanf("%d %d",&a,&b);
swaping(&a,&b);
printf("after swapping a=%d\nb=%d",a,b);

    return 0;
}
