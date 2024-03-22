#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *prev;
  int data;
  struct node *next;
}*start=NULL,*cur=NULL;

void create(int ele)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->prev=NULL;
  newnode->data=ele;
  newnode->next=NULL;
  if(start==NULL)
  start=newnode;
  else
  {
    newnode->prev=cur;
    cur->next=newnode;
  }
  cur=newnode;
}
void display_forward()
{
  struct node *temp=start;
  printf("Elements are: ");
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}
void display_backward()
{
  struct node *temp=cur;
  printf("Elements are: ");
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->prev;
  }
  printf("\n");
}
void insert_begin(int ele)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->prev=NULL;
  newnode->data=ele;
  newnode->next=start;
  start->prev=newnode;
  start=newnode;
}
void insert_end(int ele)
{
  struct node *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->prev=cur;
  newnode->data=ele;
  newnode->next=NULL;
  cur->next=newnode;
  cur=newnode;
}

int count()
{
  struct node *temp=start;
  int c=0;
  while(temp!=NULL)
  {
    c++;
    temp=temp->next;
  }
return c;
}
void max()
{
  struct node *temp=start;
  int max=temp->data;
  while(temp!=NULL)
  {
    if(max<temp->data)
    max=temp->data;
    temp=temp->next;
  }
  printf("Max = %d\n",max);
}
void min()
{
  struct node *temp=start;
  int min=temp->data;
  while(temp!=NULL)
  {
    if(min>temp->data)
    min=temp->data;
    temp=temp->next;
  }
  printf("Min = %d\n",min);
}
void insert_pos(int pos)
{
  int i=1,ele;
   printf("Enter element ");
    scanf("%d",&ele);
  if(pos==1)
  {
  insert_begin(ele);
  return ;
    }
    struct node *newnode,*temp=start;
    newnode=(struct node*)malloc(sizeof(struct node));
      while(temp!=NULL)
      {
        if(i!=pos)
        {
          i++;
          temp=temp->next;
      }
      else
      break;
    }
    if(temp!=NULL)
    {
        newnode->data=ele;
        newnode->next=temp;
        newnode->prev=temp->prev;
        temp->prev->next=newnode;
        temp->prev=newnode;
    }
    else
    insert_end(ele);  
}
void delete_begin()
{
  struct node *temp=start;
  printf("Deleted %d\n",temp->data);
  start=start->next;
  start->prev=NULL;
  free(temp);
}
void delete_end()
{
  struct node *temp=cur;
  printf("Deleted %d\n",temp->data);
  cur=temp->prev;
  cur->next=NULL;
  free(temp);  
} 
void delete_pos(int pos)
{
  struct node *temp=start;
  int i=1;
  if(pos==1)
  {
  delete_begin();
  return ;
  }
    if(pos==count())
    {
      delete_end();
      return;
    }
      while(temp->next!=NULL)
      {
        if(i!=pos)
        {
          i++;
          temp=temp->next;  
      }
      else
      break;
        
    }
      temp->prev->next=temp->next;
      temp->next->prev=temp->prev;
      free(temp);
}
void search()
{
  int i=1,key;
  struct node *temp=start;
  printf("Enter key ");
  scanf("%d",&key);
  while(temp!=NULL)
  {
    if(temp->data==key)
    {
      printf("Found at %d\n",i);
      break;
    }
    else
    {
      i++;
      temp=temp->next;
    }
  }
  if(temp==NULL)
  printf("Element not found\n");
  
}
void sort()
{
  int t;
  struct node *temp,*next;
  temp=start;
  while(temp!=NULL)
  {
      next=temp->next;
      while(next!=NULL)
      {
        if(temp->data>next->data)
        {
          t=temp->data;
          temp->data=next->data;
          next->data=t;
      }
      next=next->next;
    }
      temp=temp->next;
  }
}
void main()
{
  int c,ele,p;
  printf("Enter 1.Exit\n2.Create\n3.Display forward\n4.Dispay backward\n5.insert at begin\n6.insert at end\n7.insert at position\n8.Count\n9.Max\n10.Min\n11.Delete at begin\n12.Delete at end\n13.Delete at position\n14.Search\n15.Sort\n");
  while(1)
  {
    printf("Enter choice ");
    scanf("%d",&c);
    if(c==1)
    {
      printf("Exiting...");
      break;
    }
    else
    {
      switch(c)
      {
        case 2:
          printf("Enter data ");
          scanf("%d",&ele);
          create(ele);
          break;
        case 3:
          display_forward();
          break;
        case 4:
          display_backward();
          break;
        case 5:
          printf("Enter data ");
          scanf("%d",&ele);
          insert_begin(ele);
          break;
        case 6:
          printf("Enter data ");
          scanf("%d",&ele);
          insert_end(ele);
          break;
        case 7:
          printf("Enter position ");
          scanf("%d",&p);
          insert_pos(p);
          break;
        case 8:
          printf("Count = %d\n",count());
          break;
        case 9:
          max();
          break;
        case 10:
          min();
          break;
        case 11:
            delete_begin();
          break;  
        case 12:
          delete_end();
          break;
        case 13:
            printf("Enter position ");
          scanf("%d",&p);
          delete_pos(p);  
          break;
        case 14:
          search();
          break;
        case 15:
          sort();
          break;
        default:
          printf("INVALID");
      }
    }
  }
}