#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *link;
}*top=NULL,*newnode;

void push(int e){
    newnode=(struct stack*)malloc(sizeof(struct stack));
    newnode->data=e;
    newnode->link=top;
    top=newnode;
}

void pop(){
    struct stack *temp=top;
    top=top->link;
    printf("deleted element: %d\n",temp->data);
    free(temp);
}

void display(){
    struct stack *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

void peek(){
    printf("top element: %d\n",top->data);
}

void isEmpty(){
    if(top==NULL){
        printf("stack is empty");
    }
}

int main(){
    int n;
    printf("\nHarshith || 2310030334");
    printf("Enter an operation:\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.isEmpty\n0.Exit\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d",&n);
        
        if (n==0) {
            printf("Exiting...\n");
            break;
        } else {
            switch (n) {
                case 1:
                    printf("Enter the element: ");
                    int e;
                    scanf("%d", &e);
                    push(e);
                    break;

                case 2:
                    pop();
                    break;

                case 3:
                    peek();
                    break;

                case 4:
                    display();
                    break;

                case 5:
                    isEmpty();
                    break;

                default:
                    printf("Invalid choice.\n");
            }
        }
    }
}