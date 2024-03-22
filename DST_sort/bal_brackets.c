#include<stdio.h>
char s[100];
int top=-1;
void push(char ch){
    s[++top]=ch;
}
char pop(){
    return s[top--];
}
int main()
{
    char ch[20],x;
    int i;
    printf("Enter a bracket expression");
    scanf("%s",ch);
    for(i=0;ch[i]!='\0';i++){
        if(ch[i]=='['||ch[i]=='{'||ch[i]=='('){
            push(ch[i]);
        }else{
            x=pop();
            if(ch[i]==']'&&x=='[')
            continue;
            else if(ch[i]==')'&&x=='(')
            continue;
            else if(ch[i]=='}'&&x=='{')
            continue;
            else
            break;
        }
    }
    if(top==-1)
    printf("Valid");
    else
    printf("Not_Valid");
}