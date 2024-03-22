#include<stdio.h>
#include<math.h>
#include<ctype.h>
int top=-1;
int stack[100];
void push(int oper){
    stack[++top]=oper;
}
int pop(){
    return stack[top--];
}
int main()
{
    char exp[100];
    int i,oper1,oper2;
    printf("Enter postfix exp");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i]))
        push(exp[i] - '0');
        else{
            oper1=pop();
            oper2=pop();
            switch (exp[i])
            {
            case '+':
                push(oper2+oper1);
                break;
            case '-':
                push(oper2-oper1);
                break;    
            case '*':
                push(oper2*oper1);
                break;
            case '/':
                push(oper2/oper1);
                break;    
            case '^':
                push(oper2^oper1);
                break;    
            default:
                printf("Not a valid exp");
                break;
            }
        }
    }
    if (top!=-1)
    {
        printf("%d",pop());
    }
    
}