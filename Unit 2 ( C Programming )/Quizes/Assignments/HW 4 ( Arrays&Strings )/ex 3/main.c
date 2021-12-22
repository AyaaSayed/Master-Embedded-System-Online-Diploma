#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j;
    printf("enter number of rows: ");
    scanf("%d",&n);
    printf("enter number of colums: ");
    scanf("%d",&m);
    int arr[100][100];
     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("enter arr[%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }printf("entered array:\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d \t ",arr[i][j]);
            if(j==m-1){printf("\n\n");}
        }
    }printf("transposed array:\n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[j][i]);
            if(j==n-1){printf("\n\n");}
        }
    }return 0;
}
