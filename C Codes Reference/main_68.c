char *concat_str()
{
    static char s1[50];
    char s2[20];
    int i=0,j=0;
    printf("enter s1:");
    gets(s1);
    printf("enter s2:");
    gets(s2);
   while(s1[i]!='\0')
   {
       i++;
   }
   while(s2[j]!='\0')
   {
       s1[i]=s2[j];
       i++;
       j++;
   }
   s1[i]='\0';
  return s1;
}
int main()
{
   char *p=concat_str();
  printf("s1=%s",p);

	return 0;
}
