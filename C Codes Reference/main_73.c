
/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;
void createList(int n);                             //fun to create linked list
void traverseList();                                //fun to print linked list
void insert_element(int pos, int element);          //fun to insert element at specific position in linked list
void delete_element(int pos);                       //fun to delete element at specific position in linked list
void delete_linkedlist();                           //fun to count node
int count_nodes();
int main()
{
   int n,pos1,element,pos2,choice,count;
   printf("enter number of nodes in the list:");
   scanf("%d",&n);
   createList(n);
   printf("\ndata in the list is\n");
   traverseList();
    printf("\nenter element to insert:");
   scanf("%d",&element);
    printf("enter position of element\n:");
   scanf("%d",&pos1);
   insert_element(pos1,element);
    printf("\ndata in the list after insert an element is\n");
   traverseList();
   printf("enter pos2:");
   scanf("%d",&pos2);
   delete_element(pos2);
    printf("\ndata in the list after deleting an element is\n");
   traverseList();
   printf("\nenter an choice to delete linked list\n");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
    delete_linkedlist();
    break;
   default:
    printf("\nenter 1 to deleter the list\n");
    break;
   }
   traverseList();
    count=count_nodes();
   printf("number of nodes is %d",count);
    return 0;
}

void createList(int n)
{
  head=(struct node*)malloc(sizeof(struct node));
  struct node *new_node,*temp;
  int i,data;
  if(head==NULL)
  {
      printf("unallocated memory");
      exit(0);
  }
  printf("enter data of node 1:");
  scanf("%d",&data);
  head->data=data;
  head->next=NULL;
    temp=head;
for(i=2; i<=n; i++)
{
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("unalloctaed memeory");
        break;
    }
    temp->next=new_node;
    temp=temp->next;
    printf("enter data of node %d:",i);
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;

}
}
void insert_element(int pos, int element)
{
    struct node *new_node, *temp;
    new_node=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int i;
    new_node->data=element;
    if(pos==1)
    {
        new_node->next=head;
        head=new_node;
        return;
    }
    for(i=1; i<pos-1; i++)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}
void delete_element(int pos)
{
    int i;
    struct node* temp1=head;
    struct node* temp2=(struct node *)malloc(sizeof(struct node));
    if(pos==1)
    {
        head=temp1->next;
        free(temp1);
        return;
    }
    for(i=1; i<pos-1; i++)
    {
        temp1=temp1->next;
    }
    temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
}
void delete_linkedlist()
{
    struct node *temp=head;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
int count_nodes()
{
    int count=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void traverseList()
{
   struct node *temp=head;
   while(temp!=NULL)
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }
}
