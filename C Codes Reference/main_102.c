int Memcpy(void *dst, const void *src, unsigned int cnt)
{
    char *pdes=(char *)dst;
    const char *psrc=(const char *)src;
    while(cnt)
    {

        *(pdes++)=*(psrc++);
        cnt--;
    }
    return 0;
}
/*int main(void)
{
  char *Message="welcome to aticle world";
  char display[32]={0};
  short len=strlen(Message)+1;
  Memcpy(display,Message,len);
  printf("%s",display);
    return 0;
}*/
int main(void)
{
  int a1[6]={4,7,2,3,9,1},i;
  int a2[6]={0};
  Memcpy(a2,a1,sizeof(a1));  //we can use memcpy(a2,a1,sizeof(a1));
  for(i=0; i<6; i++)
    printf("%d ",a2[i]);
      return 0;
}

