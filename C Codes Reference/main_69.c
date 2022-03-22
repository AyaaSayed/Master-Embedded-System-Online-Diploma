
// first method:
int compare(char * str1, char * str2)
{
    int i = 0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' && str2[i] == '\0')
            break;

        i++;
    }
    return str1[i] - str2[i];
}


int main()
{
    char str1[50], str2[50];
    int index;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    index = compare(str1, str2);
    if(index == 0)
    {
        printf("equal strings");
    }
    else if(index < 0)
    {
        printf("First strin smaller than second");
    }
    else
    {
        printf("First string is greater than second.");

    }
    return 0;
}
/*// second method:
int compare_str(char *s1, char *s2)
{
   int i,index;
   for(i=0; s1[i]!='\0' && s2[i]!='\0'; i++)
   {
       if(s1[i]==s2[i])
        index=0;
       else if(s1[i]>s2[i])
       {
          index=1;
          break;
       }
       else
       {
         index=-1;
           break;
       }
   }
   return index;
}
int main()
{
    char s1[30],s2[30];
    printf("enter s1:");
    gets(s1);
    printf("enter s2:");
    gets(s2);
     int index=compare_str(s1,s2);
     if(index==0)
        printf("equal strings");
     else if(index==1)
     printf("s1 greater than s2");
     else
        printf("s1 is smaller than s2");
	return 0;
}*/
/*// third method:
#define SIZE 100
char strcmp_fun(char *str1, char *str2)
{
    int i=0,flg=0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' || str2[i] == '\0')
            break;

        i++;
    }
     if (str1[i] > str2[i])
      flg=1;
   else if (str1[i] < str2[i])
      flg=-1;
   else
      flg=0;
        return flg;
}
int main()
{
   char str1[SIZE], str2[SIZE];
   printf("\nEnter first string:");
   fgets(str1,sizeof(str1),stdin);
   printf("\nEnter second string:");
   fgets(str2,sizeof(str2),stdin);
   char ret=strcmp_fun(str1,str2);
   if(ret==0)
    printf("str1 is equal to str2");
   else if(ret==1)
    printf("str1 is larger than to str2");
    else if(ret==-1)
    printf("str1 is smaller than to str2");
   return (0);
}
