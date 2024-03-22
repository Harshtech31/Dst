#include<stdio.h>
#include<stdlib.h>
#define n 10
struct node
{
    int data;
    struct node*link;
}*temp,*a[n],*newnode;
void insert(int elm){
    int k;
    ewnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=elm;
    newnode->link=NULL;
    k=elm%n;
    if(a[k]==NULL)
    a[k]=newnode;
    else{
        temp=a[k];
        while (temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newnode;
    }
}
void Display()
{
  for(int i=0;i<n;i++){
    temp=a[i];
    printf("a[%d]-->",i);
    while (temp)
    {
        printf("%d-->",temp->data);
        temp=temp->link;
    }
    printf("\n");
  }
}

int main(){
    int key;//elm
    for(int i=0;i<n;i++){
        a[i]=NULL;
    }
    for(int i=0;i<n;i++){
        printf("enter the data");
        scanf("%d",&key);
        insert(key);
    }
    Display();
}