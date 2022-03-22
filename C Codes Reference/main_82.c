
#define SIZE 100
enum Boolean{OUT,IN};
unsigned count_Words(char *str)
{
    int state = OUT;
    unsigned wc = 0;
    while (*str)
    {
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = OUT;

        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }

        ++str;
    }

    return wc;
}
int main(void)
{
    char str[SIZE];
    puts("enter string");
    fgets(str,100,stdin);
    printf("No of words : %u", count_Words(str));
    return 0;
}
