#include<stdio.h>
#include<stdlib.h>
struct que
{
  int data;
  struct que *link;
}*front=NULL,*rare=NULL;
void enque()
{
  int ele;
  printf("Enter the element");
  scanf("%d",&ele);
  struct que *newnode;
  newnode=(struct que*)malloc(sizeof(struct que));
  newnode->data=ele;
  newnode->link=front;
  front=newnode;
  printf("Created");
}
void deque()
{
  struct que *temp=front;
  front=front->link;
  printf("Element is deleted is %d",temp->data);
  free(temp);
  printf("\nDeleted\n");
}
void display()
{
  struct que *temp=front;
  front=front->link;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->link;
  }
}
void main()
{
    printf("\nHarshith||2310030334\n");
  int choice=1;
  printf("1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\n");
  while(choice!=0)
  {
    printf("Enter the choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        enque();
        break;
        case 2:
          deque();
            break;
            case 3:
              display();
              break;
        default:
          if(choice==0)
          printf("Exiting....");
          else
          printf("Enter the valid choice");
          break;
    }
  }
}