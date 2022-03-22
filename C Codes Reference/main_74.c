/* Structure of a node */
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;
void createList(int n);                             //fun to create linked list
void traverseList();                                //fun to print linked list
void reverseList();
int main()
{
   int n;
   printf("enter number of nodes in the list:");
   scanf("%d",&n);
   createList(n);
   printf("\ndata in the list is\n");
   traverseList();
    reverseList();
    printf("\ndata after reverse in the list is\n");
   traverseList();
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
void reverseList()
{
    struct node *prevnode,*currnode;
    if(head!=NULL)
    {
        prevnode=head;
        currnode=head->next;
        head=head->next;
         prevnode->next=NULL;
        while(head!=NULL)
        {
            head=head->next;
            currnode->next=prevnode;
            prevnode=currnode;
            currnode=head;
        }
        head=prevnode;
    }
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
