
int main()
{
   char arr[2][5] = {"Even", "Odd"};
   int no;
  printf("Enter a number: ");
  scanf("%d",&no);
  printf("number is %s",arr[no%2]);
    return 0;
}
