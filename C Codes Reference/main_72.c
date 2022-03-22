// first method:
char *reverse_str(char *str)
{
    int i=0,j=0,c=0;
    static char s[50];
    //find length
    while(str[c]!='\0')
        c++;
   for(i=0; str[i]!='\0'; i++)
   {
       s[j]=str[c-1-i];
       j++;
   }
   s[j]='\0';
    return s;
}
void check_palindrome(char *str, char *p,int len)
{
    int i,c=0;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]==p[i])
            c++;
        else;
    }
    if(c==len)
        printf("string is palindrome");
    else
        printf("string is not plaindrome");
}
int main()
{
    char str[50],len;
    printf("Enter any string: ");
    gets(str);
    len=strlen(str);
    printf("original string is %s\n",str);
   char *p=reverse_str(str);
    printf("reverse string is %s\n",p);
    check_palindrome(str,p,len);

    return 0;
}
/*// second method:
void check_palindrome(char *str,int len)
{
    int i,c=0;
    for(i=0; i<len/2; i++)
    {
       if(str[i]==str[len-1-i])
       c++;
        else
        break;
    }
    if(c==len/2)
        printf("string is palindrome");
    else
        printf("string is not plaindrome");
}
int main()
{
    char str[50],len;
    printf("Enter any string: ");
    gets(str);
//find length of string
    while(str[len]!='\0')
    len++;

    check_palindrome(str,len);

    return 0;
}
