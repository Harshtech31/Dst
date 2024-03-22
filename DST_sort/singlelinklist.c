#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
    
} *start=NULL,*curr;
void insert_create()
{
    struct node *newnode;
    int e;
    printf("enter the element: ");
    scanf("%d",&e);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->link=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        curr->link=newnode;
    }
    curr=newnode;
    
}
void display()
{
    struct node *temp=start;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void insert_at_begin(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int e;
    scanf("%d",&e);
    newnode->link=start;
    newnode->data=e;
    start=newnode;
}

void insert_end()
{
  struct node *newnode;
    int e;
    printf("Enter the element: ");
    scanf("%d",&e);
    newnode=(struct node*)malloc(sizeof(struct node) );
    curr->link=newnode;
    newnode->data=e;
    curr=newnode;
}

void insert_at_pos()
{
    struct node *prev=start,*next;
    int i=1,e,pos;
    printf("Enter the pos: ");
    scanf("%d",&pos);
    printf("Enter the element: ");
    scanf("%d",&e);
    while(prev!=NULL)
    {
       if(i==pos){
       break;
       }
       else
       {
           i++;
           next=prev;
           prev=prev->link;
       }}
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node) );
    newnode->data=e;
    newnode->link=next->link;
    next->link=newnode;
}

void max(){
    struct node *temp=start;
    int max=0;
    while(temp!=NULL){
        if(temp->data>max){
            temp->data=max;
        }
        temp=temp->link;
    }
    printf("\n");
    printf("Maximum element: %d\n",max);
}

void min(){
    struct node *temp=start;
    int min=temp->data;
    while(temp!=NULL){
        if(temp->data<min){
            temp->data=min;
        }
        temp=temp->link;
    }
    printf("\n");
    printf("Minimum element: %d\n",min);
}

void count(){
    struct node *temp=start;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->link;
    }
    printf("\n");
    printf("Count of nodes: %d\n",c);
}

void search(){
    int i=1,key;
    struct node *temp=start;
    printf("enter the key: ");
    scanf("%d",&key);
    while(temp!=NULL){
        if(temp->data==key){
            printf("element found at: %d\n",i);
            break;
        }
        i++;
        temp=temp->link;
    }
    printf("element not found\n");
}

void del_at_begin(){
    struct node *temp=start;
    printf("deleted element is %d\n",temp->data);
    start=start->link;
    free(temp);
}

void del_at_end()
{
    struct node *temp=start;
    printf("deleted element is %d\n",temp->data);
    while(temp->link!=curr)
    {
        temp=temp->link;
    }
    curr=temp;
    temp=temp->link;
    curr->link=NULL;
    free(temp);
    
}

void del_at_pos(){
    struct node *prev,*next=start;
    int i=1,pos;
    printf("enter the pos: ");
    scanf("%d",&pos);
    while(next!=NULL)
    {
       if(i==pos){
           break;
       } 
       else {
        i++;
        prev=next;
        next=next->link;
       }
    }
    prev->link=next->link;
    printf("deleted element = %d\n",next->data);
}
void sort()
{
    int t;
    struct node *temp,*prev,*next;
    temp=start;
    while(temp!=NULL){
    prev=temp;
    next=temp->link;
    while(next!=NULL)
    {
        if(prev->data>next->data)
        {
            t=temp->data;
            prev->data=next->data;
            next->data=t;
        }
       //prev=next;
        next=next->link;
    }
    temp=temp->link;
    }
}
void reve()
{


    struct node *prev = NULL,*temp = start,*next = NULL;
    while (temp != NULL) 
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    start = prev; 
}

void main()
{
    while(1)
    {
        printf("2310030334-Harshith\n");
        printf("Enter one option from the following\n");
        printf("1.Insert\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at position\n6.Maximum\n7.Minimum\n8.Count of Nodes\n9.Search\n10.Delete at begin\n11.Delete at end\n12.Delete at Position\n13.Sort\n14.Exit\n");
        int c,flag=1;
        printf("enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insert_create();
            break;
            
            case 2:
            display();
            printf("\n");
            break;

            case 3:
            insert_at_begin();
            break;
            case 4:
            insert_end();
            break;

            case 5:
            insert_at_pos();
            break;

            case 6:
            max();
            break;

            case 7:
            min();
            break;

            case 8:
            count();
            break;

            case 9:
            search();
            break;

            case 10:
            del_at_begin();
            break;

            case 11:
            del_at_end();
            break;

            case 12:
            del_at_pos();
            break;
            
            case 13:
            sort();
            break;
            default:
            flag=0;
            printf("exiting..");
            break;
        }
            if(flag==0)
            break;
    }
}