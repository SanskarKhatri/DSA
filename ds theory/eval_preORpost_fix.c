#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Stack type
struct Stack {
	int top;
	int capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack(int capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));
//if malloc is successful
	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array
		= (int*)malloc(stack->capacity * sizeof(int));

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return (stack->top == -1);
}
char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}
int evalPost(char *exp){
    int a,b,res=0;
    char c;
    struct Stack* stack=createStack(strlen(exp));
    for(int i=0;i<strlen(exp);i++){
        if(isdigit(exp[i])){
            push(stack,exp[i]);
        } else{
            b=(int)pop(stack)-48;
            a=(int)pop(stack)-48;
            switch(exp[i]){
                case '+':
                res=a+b;
                break;
                case '*':
                res=a*b;
                break;
                case '-':
                res=a-b;
                break;
                case '/':
                res=a/b;
                break;
                case '^':
                res=pow(a,b);
                break;
            }
            c=res+'0';
            push(stack,c);
        }
    }
    return res;
}
int evalPre(char *exp){
    int a,b,res=0;
    char c;
    struct Stack* stack=createStack(strlen(exp));
    for(int i=strlen(exp)-1;i>=0;i--){
        if(isdigit(exp[i])){
            push(stack,exp[i]);
        } else{
            a=(int)pop(stack)-48;
            b=(int)pop(stack)-48;
            switch(exp[i]){
                case '+':
                res=a+b;
                break;
                case '*':
                res=a*b;
                break;
                case '-':
                res=a-b;
                break;
                case '/':
                res=a/b;
                break;
                case '^':
                res=pow(a,b);
                break;
            }
            c=res+'0';
            push(stack,c);
        }
    }
    return res;

}  
int main(){
    char exp[50];
    printf("Enter the expression to be evaluated: ");
    scanf("%s",exp);
    // char exp[] = "53+62/*35*+";
    if(isdigit(exp[0])){
        printf("Result for postfix expression: %d",evalPost(exp));
    } else {
        printf("Result for prefix expression: %d",evalPre(exp));
    }
    
}