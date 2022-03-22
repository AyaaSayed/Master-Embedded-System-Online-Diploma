// a)first method:Using a single pointer:
#define r 3
#define c 4
int main()
{
    int *arr = (int *)malloc(r * c * sizeof(int));

    int i, j, count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         *(arr + i*c + j) = ++count;

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", *(arr + i*c + j));

   return 0;
}
/*// b)second method:Using an array of pointers;
#define r 3
#define c 4
int main()
{
     int i, j, count=0;

    int *arr[r];
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count;

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);

   return 0;
}*/
/*// c)third method:Using pointer to a pointer:
#define r 3
#define c 4
int main()
{
    int i, j, count=0;

    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count;

    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);

   return 0;
}*/
/*// d)fourt method:Using double pointer and one malloc call:
#define r 3
#define c 4
int main()
{
    int len=0;
    int *ptr, **arr;
    int count = 0,i,j;

    len = sizeof(int *) * r + sizeof(int) * c * r;
    arr = (int **)malloc(len);
      ptr = (int *)(arr + r);

    for(i = 0; i < r; i++)
        arr[i] = (ptr + c * i);

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            arr[i][j] = ++count;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);

   return 0;
}*/
