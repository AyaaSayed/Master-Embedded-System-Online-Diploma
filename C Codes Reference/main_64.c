
#define SIZE 8
int main()
{
  char binary[SIZE+1],onescomp[SIZE+1];
  int i;
  printf("enter binary num:");
  gets(binary);
  for(i=0; i<SIZE; i++)
  {
      if(binary[i]=='1')
      {
         onescomp[i]='0';
      }
        else if(binary[i]=='0')
        {
          onescomp[i]='1';
        }
        else
        {
            printf("error");
             break;
        }
  }
  onescomp[SIZE]='\0';
  printf("%s",onescomp);

    return 0;
}
