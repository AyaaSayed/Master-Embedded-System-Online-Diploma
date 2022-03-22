// method1:using second array
void reverse_string(char *str, int size)
{
    int i,j,k=0;
    char ch[50];
    for(i=size-1; i>=0; i--)
    {
        if(str[i]==' ')
        {
            for(j=k-1; j>=0; j--)
            {
                printf("%c",ch[j]);
            }
            printf(" ");
            k=0;
        }
        else
        {
            ch[k]=str[i];
            k++;
        }
    }
    if(k!=0)
    {
        for(j=k-1; j>=0; j--)
        {
            printf("%c",ch[j]);
        }
    }

}
int main()
{
   char str[50];
   puts("enter string");
   fgets(str,50,stdin);
   reverse_string(str,strlen(str));
    return 0;
}
/*// method2:without second array:
void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

// Function to reverse words*/
void reverseWords(char* s)
{
    char* word_begin = s;

    // Word boundary
    char* temp = s;

    // Reversing individual words as
    // explained in the first step
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }

    // Reverse the entire string
    reverse(s, temp - 1);
}

int main()
{
    char s[] = "i like this program very much";
    char* temp = s;
    reverseWords(s);
    printf("%s", s);
    getchar();
    return 0;
}*/
/*// method three:
char *reverse_words(char *s,int len)
{
    int index=0,i,startword,endword;
    static char reverse[50];
    startword=len-1;
    endword=len-1;
    while(startword>0)
    {
        if(s[startword]==' ')
        {
            i=startword+1;
           while(i<=endword)
           {
               reverse[index]=s[i];
               index++;
               i++;
           }
           reverse[index++]=' ';
           endword=startword-1;
        }

        startword--;
    }
    for(i=0; i<=endword; i++)
    {
        reverse[index]=s[i];
        index++;
    }
    return reverse;
}
int main()
{
   char s[50];
   int len;
   printf("enter str:");
   gets(s);
   len=strlen(s);
   printf("original string is\n%s",s);
   char *p=reverse_words(s,len);
    printf("\nstring after reverse words is\n %s",p);

    return 0;
}
