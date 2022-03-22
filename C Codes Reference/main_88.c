void rotateArry(int a[],int N,int D)
{
    int newArry[n],i;

    for ( i = 0; i < N; i++)
    {
    	int newIndex = (i+N-D)%N;
    	newArry[newIndex]=a[i];
    }
    for ( i = 0; i < N; i++)
    {
        a[i]=newArry[i];
    }

}

int main() {
	int a[]={1,2,3,4,5},N,D,i;
	N=sizeof(a)/sizeof(*a);
	printf("enter no of rotates:");
	scanf("%d",&D);
	rotateArry(a,N,D);
    for (i = 0; i < N; i++)
    {
        printf("%d ",a[i]);
    }
	return 0;
}
