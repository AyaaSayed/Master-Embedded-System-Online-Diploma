int myfun(char *a, int size,int *elem)
{
    int i, j, count;
    int most = 0;
    int temp;

    for(i = 0; i < size; i++) {
        temp = a[i];
        count = 1;
        for(j = i + 1; j < size; j++) {
            if(a[j] == temp) {
                count++;
            }
        }
        if (most < count) {
            most = count;
            *elem = a[i];
        }
    }
    return most;
}
int main()
{
    char a[200];
    puts("enter string");
    fgets(a,200,stdin);
   int size,num;
   size=strlen(a);
   int ret=myfun(a,size,&num);
   printf("%c exits %d times",num,ret);
    return 0;
}

