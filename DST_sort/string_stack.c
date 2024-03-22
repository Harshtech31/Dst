#include <stdio.h>// reversing of a string
int top = -1;
char stack[100];
void push(char c){
    stack[++top] = c;
}
char pop(){
    return stack[top--];
}
int main(){
    char str[100]="hello";
    int i;
    printf("Enter a string: ");
    for(i=0;str[i]!='\0';i++)
    push(str[i]);
    for(i = top; i >= 0; i--)
    printf("%c",pop());
    return 0;
}