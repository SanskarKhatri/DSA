// C program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Stack type
struct Stack
{
	int top;
	int capacity;
	int* array;
};

// Stack Operations
struct Stack* createStack( int capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp)
{
	struct Stack* stack = createStack(strlen(exp));
	int i;
	for (i = 0; exp[i]; ++i)
	{
		if (isdigit(exp[i]))//#include <ctype.h>
			push(stack, exp[i]-'0');
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			}
		}
	}
	return pop(stack);
}

// Driver program to test above functions
int main()
{
	char exp[] = "5569++";//"231*+9-";
	printf ("postfix evaluation: %d", evaluatePostfix(exp));
	return 0;
}
