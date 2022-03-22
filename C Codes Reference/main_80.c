// first way: Using pointer to two dimentional array.
int main()
{
    int a[2][2]={{1,2}, {3,4} };
    int *p=&a[0][0];
    int i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            printf("%d ",*(p+i*2+j));
    }
    return 0;
}
/*// second way:
int main()
{
    int a[2][2]={{1,2}, {3,4} };
    int (*p)[2]=a; //pointer to array of 2 integers
    int i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            printf("%d ",p[i][j]);
    }
    return 0;
}*/
/*// third way:
int main()
{
    int a[2][2]={{1,2}, {3,4} };
    int (*p)[2][2]=&a; //pointer to the whole array
    int i,j;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
            printf("%d ",(*p)[i][j]);
    }
    return 0;
}

