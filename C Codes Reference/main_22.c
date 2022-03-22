
char *longest_word(char *string1)
{
   static char longestword[20];
    int index,letters,longestnumber=0,temp=0,j;

	for(index=0;string1[index]!='\0';index++)
	{
		temp = index;

		for(letters=0;string1[index]!=' ' && string1[index]!='\0' ;index++,letters++);

		j=0;

		if(letters>=longestnumber)
		{
			while(string1[temp] != ' ')
			{
				longestword[j] = string1[temp];
				temp++;
				j++;
			}
			 longestword[j] = '\0';
            longestnumber = letters;
		}
	}
   return longestword;
}
int main()
{

char string1[] = "my name is mohamed ali",*p;
p=longest_word(string1);
printf("longest word is %s",p);
	return 0;
}
