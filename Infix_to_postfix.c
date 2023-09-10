#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
    int top;
    int size;
    int* arr;
};
int isEmpty(struct Stack* sp) // Checking is The Stack Empty or Not
{
    if (sp -> top == -1) {
        return 1;
    }
    return 0;
}
int isFull(struct Stack* sp) // To check if the stack is Full or not.
{
    if (sp -> top == sp -> size - 1) {
        return 1;
    }
    return 0;
}
void push(struct Stack* sp, char data)  // This Function will push the value.
{
    if (isFull(sp)) // Checking Stack Overflow Condition.
    {
        printf("Stack Overflow Occuring...\n");
        return;
    }
    sp -> top++;
    sp -> arr[sp -> top] = data;
}
char pop(struct Stack* sp)  // This Function will pop out the stack Elements
{
    if (isEmpty(sp)) // Checking Stack Underflow Condition
    {
        printf("Stack Underflow Occuring...\n");
        return -1;
    }
    char value = sp -> arr[sp -> top];
    sp -> top--;
    return value;
}
char stackTop(struct Stack* sp) // It will return the top element of the Stack
{
    return sp -> arr[sp -> top];
}
int isOperator(char ch) // To check the operator
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}
int precedence(char ch) // This Function will check the precedence of the operator
{
    if (ch == '+' || ch == '-') {
        return 1;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else{
        return 0;
    }
}
char* infix_to_postfix(char* infix) // This Function will return the PostFix Expression
{
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp -> size = 10;
    sp -> top = -1;
    sp -> arr = (char*)malloc(sizeof(char) * sp -> size);
    char* postfix = (char*)malloc(sizeof(char) * (strlen(infix) + 1));
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if (precedence(infix[i]) > precedence(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "x-y/z-k*d"; // Demo Infix Expression. 
    printf("The postfix expression is: %s\n", infix_to_postfix(infix)); // The postfix expression is: xyz/-kd*-
    return 0;
}