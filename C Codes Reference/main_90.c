#define N 2
void multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    int i,j,k;
    for(i=0; i<N; i++)-----------
    {
        for(j=0; j<N; j++)
        {
            res[i][j]=0;
            for(k=0; k<N; k++)
                res[i][j]+=mat1[i][k]*mat2[k][j];
        }
    }

}
int main()
{
   int a1[2][2]={{2,4},{3,4}},a2[2][2]={{1,2},{1,3}},a3[2][2],i,j;
   multiply(a1,a2,a3);
   printf("Result matrix is \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
           printf("%d ", a3[i][j]);
        printf("\n");
    }
     return 0;
}

