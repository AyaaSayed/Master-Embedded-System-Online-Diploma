int main(int argc, char *argv[])
{
int i, j, rows;
    printf("Input number of rows: ");
    scanf("%d",&rows);
    for(i = 1; i <= rows; ++i)
    {
        for(j = 1; j <= i; ++j)
        {
            printf("%d", (j + i + 1) % 2);
        }
        printf("\n");
    }
return 0;
}
