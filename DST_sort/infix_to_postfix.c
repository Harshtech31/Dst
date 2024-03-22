#include<stdio.h>
#include<ctype.h>
int top=-1;
char stack[100];
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
int priority(char ch)
{
    if(ch=='^')
    return 3;
    else if(ch=='*'||ch=='/')
    return 2;
    else if(ch=='+'||ch=='-')
    return 1;
    else
    return 0;
}
int main()
{
    char exp[100],x;
    int i;
    printf("Enter a expression\n");
    scanf("%s",exp);
    for ( i = 0; exp[i]!='\0'; i++)
    {
        if(isalpha(exp[i]))
        printf("%c",exp[i]);
        else if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while((x=pop())!='(')
            printf("%c",x);
        }
        else {
            while (priority(stack[top])>=priority(exp[i]))
            {
                printf("%c",pop());
            }
         push(exp[i]);
        }
    }
    while (top!=-1)
    {
        printf("%c",pop());
    }
    
    
}