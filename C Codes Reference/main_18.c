
// first method:using iteration:
#define MAX 20
void reverse_array(int *a, int size )
{
  int i,b[MAX],c=0;
  for(i=0; i<size; i++)
  {
      b[c]=a[size-1-i];
      c++;
  }
  for(i=0; i<size; i++)
    a[i]=b[i];
}
int main()
{
    int a[]={1,2,3,4,5,7},size,i;
    size=sizeof(a)/sizeof(*a);
    reverse_array(a,size);
    for(i=0; i<size; i++)
        printf("%d ",a[i]);
    return 0;
}
/*// second method:using stack
#define MAX 20
int stack[MAX],top=-1;
void push(int data)
{
    if(top==MAX-1)
        printf("stack is full");
    else
    {
        stack[++top]=data;
    }
}
void pop()
{
       if(top==-1)
        printf("stack is empty");
    else
    {
        printf("%d ",stack[top--]);
    }
}
int main()
{
    int a[]={5,3,2,8,10,15},size,i;
    size=sizeof(a)/sizeof(*a);
    printf("the reverse array is\n");
    for(i=0; i<size; i++)
        push(a[i]);
    for(i=0; i<size; i++)
        pop();
    return 0;
}

