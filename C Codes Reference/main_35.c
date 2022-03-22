
// method1:using bitwise operato:
char check_even_odd(unsigned char num)
{
   if(num&1)
    return 1;
   return 0;
}
int main()
{
  unsigned char num=6;
  printf("%d",check_even_odd(num));
	return 0;
}
/*// method2:using modules operator:
char check_even_odd(unsigned char num)
{
   if(num%2!=0)
    return 1;
   return 0;
}
int main()
{
  unsigned char num=7;
  printf("%d",check_even_odd(num));
	return 0;
}
