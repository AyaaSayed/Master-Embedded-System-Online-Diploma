#define MAX 20
void swap(int *a, int *b)
{
    int i;
    for(i=0; i<MAX; i++)
    {
        a[i]^=b[i];
        b[i]^=a[i];
        a[i]^=b[i];

    }
}
int main()
{
    int a[MAX]={1,2,3,4,5},b[MAX]={10,20,30},s1=5,s2=3,i;
    printf("two arrays before swapping is\n");
    for(i=0; i<s1; i++)
        printf("%d ",a[i]);
        printf("\n");
        for(i=0; i<s2; i++)
        printf("%d ",b[i]);
    swap(a,b);
    printf("\ntwo arrays after swapping is\n");
    for(i=0; i<s1; i++)
        printf("%d ",a[i]);
        printf("\n");
        for(i=0; i<s2; i++)
        printf("%d ",b[i]);

    return 0;
}
