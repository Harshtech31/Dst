#include<stdio.h>
#include<stdlib.h>
#define n 10
int a[n]={NULL};
void insert(){
    int elm,i,j,k;
    printf("Enter a value");
    scanf("%d",&elm);
    k=(elm)%n;
    for(i=0;i<n;i++){
        j=(k+i*i)%n;
        if(a[j]==NULL){
            a[j]=elm;
            break;
        }
    }
    if (i==n)
    {
        printf("elm canot be inserted");
    }    
}
void display()
{
    printf("elm in hash table are:\n");
    for(int i=0;i<n;i++){
        printf("\n At index %d\t value=%d",i,a[i]);
    }
}
int main(){
    int ch;
    printf("\n1.Insert\n2.Display\n3.Exit\n");
    while(1){
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        insert();
        break;
    case 2:
        display();
        break;
    case 3:
        exit(0);
        break;    
    default:
    printf("invalid option\n");
        break;
    }
    }
}