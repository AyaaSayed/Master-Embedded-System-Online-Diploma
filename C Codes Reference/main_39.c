
void Sort_array(char *s, int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(s[i]>s[j])
            {
                s[i]^=s[j];
                s[j]^=s[i];
                s[i]^=s[j];

            }
        }
    }
    printf("%s",s);
}

// Driver code
int main()
{

char str[]="geeksforgeeks";
int size=strlen(str);
Sort_array(str,size);
    return 0;
}
