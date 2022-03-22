void reverse_string(char *s1,char *s2, int len)
{
 int m=0,n,times=0;
 for(n=0; s1[n]!='\0'; n++)
 {
   if(s1[n]==s2[m])
   {
       while(s1[n]==s2[m] && s1[n]!='\0')
       {
           m++;
           n++;
       }
       if(m==len)
       {
           times++;
       }
   }
   else
   {
       while(s1[n]!=' ')
       {
           n++;
           if(s1[n]=='\0')
            break;
       }
   }
   m=0;

 }
 if(times>0)
        printf("%s appears in sentence",s2);
     else
         printf("%s doesn't appear in sentence",s2);


}
int main()
{
   char str[50],word[10];
   puts("enter string");
   fgets(str,50,stdin);
   puts("enter word");
   fgets(word,50,stdin);
   reverse_string(str,word,strlen(word));
    return 0;
}

