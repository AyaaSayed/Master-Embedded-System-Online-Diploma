// method1:using iterartion:
void reverse_string(char *str, int len)
{
    int i;
    char s[20];
    for(i=0; i<len; i++)
    {
        s[i]=str[len-1-i];
    }
    for(i=0; i<len; i++)
     {
         str[i]=s[i];
     }
}
int main()
{
   char str[20];
   puts("enter string");
   fgets(str,20,stdin);
   reverse_string(str,strlen(str));
   printf("str after reversing is %s",str);
    return 0;
}
/*// method2:using stack data structure:
#define MAX_size 20
int top=-1;
char stack[MAX_size];
void push(char data)
{
    if(top>=MAX_size-1)
        printf("stack is full");
    else
        stack[++top]=data;

}
void pop()
{
        if(top==-1)
        printf("stack is empty");
        else
            printf("%c",stack[top--]);

}
int main()
{
   char str[20];
   int i;
   puts("enter string");
   fgets(str,20,stdin);
   printf("the reverse string is:");
   for(i=0; i<strlen(str); i++)
    push(str[i]);
     for(i=0; i<strlen(str); i++)
    pop();

    return 0;
}

