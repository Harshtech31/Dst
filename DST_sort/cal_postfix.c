#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int stack1[MAX_SIZE];
int top = -1;

int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void push(char ch) {
    stack[++top] = ch;
}
void push(int ch) {
    stack1[++top] = ch;
}

char pop() {
    return stack[top--];
}
int pop() {
    return stack1[top--];
}

void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    char ch;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while ((ch = pop()) != '(') {
                postfix[j++] = ch;
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char *postfix) {
    int operandStack[MAX_SIZE];
    int top = -1;
    int val1, val2;
    char ch;

    for (int i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0'); 
        } else {
            val2 = pop();
            val1 = pop();
            switch (ch) {
                case '+':
                    push(val1 + val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '/':
                    push(val1 / val2); 
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }
    return stack[top];
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
