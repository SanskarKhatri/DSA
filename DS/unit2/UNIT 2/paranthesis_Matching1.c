#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Stack {
    int top;
    char* array;
};

struct Stack* create(char max)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (char*)malloc(max * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, char item)
{
    stack->array[++stack->top] = item;
}

void pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top];
}

int checkPair(char val1,char val2){
    return (( val1=='(' && val2==')' )||( val1=='[' && val2==']' )||( val1=='{' && val2=='}' ));
}

int checkBalanced(struct Stack* stack, char expr[], int len){

    for(int i = 0; i < len; i++)
    {
        if (expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
        {
          push(stack, expr[i]);
        }
        else if(expr[i]==')' || expr[i]==']' || expr[i]=='}')
        {
            if (isEmpty(stack))//Extra close brackets
                return 0;
            else if(checkPair(peek(stack),expr[i]))//mismatching brackects
                {
                pop(stack);
                continue;
                }
        return 0;
        }
    }
    if(isEmpty(stack)) //No extra open brackets
        return 1;
    else
        return 0;
}
int main() {
  char exp[MAX] = "({)}[]";

  int len = strlen(exp);
  struct Stack* stack = create(len);
  checkBalanced(stack, exp, len)?printf("Balanced"): printf("Not Balanced");

  return 0;
}

