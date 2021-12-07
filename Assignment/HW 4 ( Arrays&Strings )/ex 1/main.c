#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[2][2],b[2][2],sum[2][2];
    int i,j;
    printf("enter the element of 1st matrix\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("enter a[%d][%d]: ",i,j);
            scanf("%f",&a[i][j]);
        }
    }printf("enter the element of 2nd matrix\n");
     for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("enter b[%d][%d]: ",i,j);
            scanf("%f",&b[i][j]);
        }
    }printf("sum: \n");
     for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            sum[i][j]=a[i][j]+b[i][j];
            printf("%f\t",sum[i][j]);
            if(j==1){printf("\n");}
        }
    }
    return 0;
}
