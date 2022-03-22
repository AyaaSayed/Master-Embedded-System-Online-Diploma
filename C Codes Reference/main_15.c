
int search_for_num(int *a, int size, int num)
{
    int i;
    for(i=0; i<size; i++)
        if(num==a[i])
        return i;
    return -1;
}
int main()
{
    int a[5]={5,8,10,12,15},size,num;
    size=sizeof(a)/sizeof(*a);
    printf("enter number to search:");
    scanf("%d",&num);
    int ret=search_for_num(a,size,num);
    ret==-1?printf("number not found"):printf("number found at index %d",ret);
    return 0;
}
