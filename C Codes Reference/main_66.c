int length_str(char *str)
{
    int i,c=0;
    for(i=0; str[i]!='\0'; i++)
        c++;
    return c;
}
int main()
{
    char s[50];
    printf("enter string:");
    gets(s);
    printf("length of tsring is %d",length_str(s));

	return 0;
}
