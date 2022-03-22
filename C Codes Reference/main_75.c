
#define stack_size 100
int stack[stack_size],top=-1,choice;
void push(int data)
{
 if(top==stack_size-1)
    printf("stack is overflow");
 else
 {
   stack[++top]=data;
 }
}
void pop()
{
    if(top==-1)
    printf("stack is underflow");
 else
 {
   printf("the poped element is %d\n",stack[top--]);
 }

}
void display()
{
    int i;
    printf("\nthe elements in the stack is\n");
 if(top==-1)
    printf("stack is underflow");
    else
    {
        for(i=top; i>=0; i--)
            printf("%d ",stack[i]);
    }
}
int main()
{

    while(1)
    {
      int data;
      printf("enter an choice:");
      scanf("%d",&choice);
      switch(choice)
      {
      case 0:
        printf("enter data:");
        scanf("%d",&data);
        push(data);
        break;
      case 1:
        pop();
        break;
      case 2:
        display();
        break;
      case 3:
        exit(0);
      default:
        printf("enter value 0 or 1 or 2");
      }
    }

    return 0;
}
