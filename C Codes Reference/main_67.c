// first method:
char *copy_string(char *str)
{
    static char cpy_str[50];
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        cpy_str[i]=str[i];
    }
     cpy_str[i]='\0';
    return cpy_str;
}
int main()
{
    char str[50],*p;
    printf("enter string:");
    gets(str);
    printf("original string is %s\n:",str);
    p=copy_string(str);
    printf("copying string is is %s",p);
	return 0;
}
/*// second method:using pointer:
int main()
{
    char s1[50],s2[50],*p1,*p2;
    p1=s1;
    p2=s2;
     printf("enter string:");
    gets(s1);
       while(*(p2++)=*(p1++));
    printf("original string is %s\n:",s1);
    printf("copying string is %s\n:",s2);

	return 0;
}*/
/*// third method:
#define SIZE 100
void strcpy_fun(char *str1, char *str2)
{
    while(*str1!='\0')
    {
        *str2=*str1;
        str1++;
        str2++;
    }
    *str2='\0';
}
int main()
{
   char str1[SIZE], str2[SIZE];
   printf("\nEnter first string:");
   fgets(str1,sizeof(str1),stdin);
  strcpy_fun(str1,str2);
  printf("str2=%s",str2);
   return (0);
}
