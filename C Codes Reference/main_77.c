#define MAX 5
int cque[MAX],rear=-1,front=-1,i,element,choice;
void enqueue()
{
  if((rear==MAX-1 && front==0) || (rear==front-1))
    printf("queue is full");
  if(rear==MAX-1 && front!=0)
    rear=0;
  else
    rear++;
  printf("enter data:");
  scanf("%d",&element);
  cque[rear]=element;
  if(front==-1)
    front=0;
}
void dequeue()
{
  if(front==-1)
  printf("queue is empty");
  element=cque[front];
  cque[front]=0;
      if(front==rear)
        front=rear=-1;
      else
      {
          if(front==MAX-1)
            front=0;
          else
            front++;
      }
      printf("the delete element is %d",element);
}
void display()
{
  printf("the circular queue is\n");
  for(i=0; i<MAX; i++)
        printf("%d ",cque[i]);
}
int main()
{
  while(1)
  {
      printf("enter a choice:");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      }
  }
  return 0;
}
