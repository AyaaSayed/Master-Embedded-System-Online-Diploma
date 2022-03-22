
#define stack_size 100
struct node
{
    int data;
    struct node *next;
}*top;
int size=-1,choice;
void push(int data)
{
 if(size==stack_size-1)
    printf("stack is overflow\n");
 struct node *new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=data;
 new_node->next=top;
 top=new_node;
 size++;
}
void pop()
{
    int data;
    if(size==-1)
    printf("stack is underflow\n");
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node=top;
    data=top->data;
    top=top->next;
    free(new_node);
    size--;
    printf("the poped element is %d\n",data);
}
void display()
{
    int i;
    printf("\nthe elements in the stack is\n");
 if(size==-1)
    printf("stack is underflow");
    else
    {
        for(i=size; i>=0; i--)
        {
           printf("%d ",top->data);
            top=top->next;
        }

    }
}
int main()
{

    while(1)
    {
      int data;
      printf("\nenter an choice:");
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
