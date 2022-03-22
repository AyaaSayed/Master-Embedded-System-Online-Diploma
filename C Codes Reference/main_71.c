void count_alp_digits_special(char *s1,int *alphabets,int *digits,int *special)
{
   int i;
   *alphabets=0;
   *digits=0;
   *special=0;
   for(i=0; s1[i]!='\0'; i++)
   {
       if((s1[i]>='A' && s1[i]<='Z') || (s1[i]>='a' && s1[i]<='z'))
      ++*alphabets;
      else if(s1[i]>=0 && s1[i]<=9)
              ++*digits;
      else
        ++*special;
   }
}
int main()
{
    char s1[30];
    int alphabets=0,digits=0,special=0;
    printf("enter s1:");
    gets(s1);
   count_alp_digits_special(s1,&alphabets,&digits,&special);
    printf("number of alphabets is %d\nno of digits is %d\nno of special is %d",alphabets,digits,special);

	return 0;
}

