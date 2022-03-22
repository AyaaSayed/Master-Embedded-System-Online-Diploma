
int my_strcmp(char *a, char *b)
{
  return (*a == *b && *b == '\0')? 0 : (*a == *b)? my_strcmp(++a, ++b): 1;
}

/* driver function to test above function */
int main()
{
  char *a = "geeksforgeeks";
  char *b = "geeksforgeeks";
  if(my_strcmp(a, b) == 0)
     printf(" String are same ");
  else
     printf(" String are not same ");

  getchar();
  return 0;
}
