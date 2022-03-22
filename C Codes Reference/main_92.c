
#define N 3
int my_fun(int a[][N])
{
    int i,j,sum=0,m=N;
    for(i=0; i<N; i++)
    {
        m=m-1;
        for(j=0; j<N; j++)
        {
         if(j==m)
                sum+=a[i][j];

        }
    }
    return sum;
}

int main()
{
  int a[][N]={{1,2,3},{8,4,4}, {10,4,9} };
  int ret=my_fun(a);
  printf("sum is %d",ret);
    return 0;
}
