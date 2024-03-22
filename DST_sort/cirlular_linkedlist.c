#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*start=NULL,*curr;

void create(){
    int e;
    scanf("%d",&e);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->link=NULL;
    if(start==NULL){
        start=newnode;
        newnode->link=start;
    }
    else{
        curr->link=newnode;
        newnode->link=start;
    }
    curr=newnode;
}

void display(){
    struct node *temp=start;
    do{
        printf("%d ",temp->data);
        temp=temp->link;
    } while(temp!=start);
}

void insert_at_begin(){
    int e;
    scanf("%d",&e);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->link=start;
    curr->link=newnode;
    start=newnode;
}

void insert_at_end(){
    int e;
    scanf("%d",&e);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=e;
    newnode->link=start;
    curr->link=newnode;
    curr=newnode;
}

void insert_at_pos(){
    int ele;
    scanf("%d",&ele);
    int pos;
    scanf("%d",&pos);
    struct node *temp,*prev; 
    temp=start; 
    struct node *newnode; 
    newnode=(struct node*)malloc(sizeof(struct node)); 
    newnode->data=ele; 
    int i=1; 
    if(pos==1) 
    insert_at_begin(); 
    else{ 
    do{ 
      if(i==pos){ 
        i++; 
        break; 
      } 
      else{ 
        prev=temp; 
        temp=temp->link; 
        i++; 
      } 
    }while(temp->link!=start); 
    prev->link=newnode; 
    newnode->link=temp; 
  }
}

void delete_at_begin(){
    struct node *temp=start;
    printf("deleted element is %d\n",temp->data);
    start=start->link;
    free(temp);
}

void delete_at_end(){
    struct node *temp=start,*prev;
    printf("deleted element is %d\n",curr->data);
    while(temp->link!=start)
    {
        prev=temp;
        temp=temp->link;
    }
    curr=prev;
    curr->link=start;
    free(temp);
}

void delete_at_pos(){
  struct node *temp=start,*prev; 
  int i=1; 
  int pos;
  printf("enter position: ");
  scanf("%d",&pos);
  while(temp->link!=start) 
  { 
    if(i==pos) 
    break; 
    else 
    { 
      prev=temp;
      temp=temp->link; 
      i++; 
    } 
  } 
  prev->link=temp->link; 
  free(temp); 
}

void max()
{
    struct node *temp=start;
    int max=0;
    do{
        if(temp->data>max){
            max=temp->data;
            temp=temp->link;
        }
    }while(temp!=start);
    printf("\n");
    printf("Maximum element: %d\n",max);
}

void min(){
    struct node *temp=start;
    int min=temp->data;
    do{
        if(temp->data<min){
            min=temp->data;
            temp=temp->link;
        }
    }while(temp!=start);
    printf("\n");
    printf("Minimum element: %d\n",min);
}

void count(){ 
  struct node *temp=start; 
  int c=0; 
  do{ 
    c++; 
    temp=temp->link; 
  }while(temp!=start); 
  printf("No.of nodes:%d\n",c); 
}

int main(){
printf("\nNAME: Harshith || ROLL:2310030334\n");
    printf("*CIRCULAR LINKED L1IST MENU-DRIVEN PROGRAM*\n");
    printf("Enter one option from the following\n");
    printf("1.Insert\n2.Display\n3.Insert at Begin\n4.Insert at End\n5.Insert at Position\n6.Delete at begin\n7.Delete at End\n8.Delete at Position\n9.Maximum\n10.Minimum\n11.Count of Nodes\n12.Exit\n");
    while(1){
        int c,flag=1;
        printf("enter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                create();
                break;
            
            case 2:
                display();
                printf("\n");
                break;

            case 3:
                insert_at_begin();
                break;
            
            case 4:
                insert_at_end();
                break;
                case 5:
                insert_at_pos();
                break;
            
            case 6:
                delete_at_begin();
                break;
            
            case 7:
                delete_at_end();
                break;
            
            case 8:
                delete_at_pos();
                break;
            
            case 9:
                max();
                break;

            case 10:
                min();
                break;
            
            case 11:
                count();
                break;
            
            default:
                printf("Invalid choice\n");
                break;
        }
        if(flag==0)
            break;
    }
    return 0;
}