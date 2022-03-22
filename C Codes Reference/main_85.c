
int check_little_or_big( int num)
{
  char *p=(char *)&num;
  return *p;
}
int main()
{
    int num=1;
    int ret=check_little_or_big(num);
    if(ret==1)
    printf("little endian");
    else
        printf("big endian");
    return 0;
}
