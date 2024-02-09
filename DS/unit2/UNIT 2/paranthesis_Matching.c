#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char peek(struct Stack* stack)
{
	return (stack->array[stack->top]);
}

char pop(struct Stack *stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}
int areBracketsBalanced(char exp[])
{
    int i = 0;

    // Declare an empty character stack
    struct Stack *stack = NULL;

    // Traverse the given expression to check matching
    // brackets
    while (exp[i]) {
        // If the exp[i] is a starting bracket then push
        // it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);

        // If exp[i] is an ending bracket then pop from
        // stack and check if the popped bracket is a
        // matching pair*/
        if (exp[i] == '}' || exp[i] == ')'
            || exp[i] == ']') {

            // If we see an ending bracket without a pair
            // then return false
            if (stack == NULL)
                return 0;

            // Pop the top element from stack, if it is not
            // a pair bracket of character then there is a
            // mismatch.
            // his happens for expressions like {(})
            else if (!isMatchingPair(pop(stack), exp[i]))
                return 0;
        }
        i++;
    }

    // If there is something left in expression then there
    // is a starting bracket without a closing
    // bracket
    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}

// Driver code
int main()
{
    char exp[100] = "{()}[]";

    // Function call
    if (areBracketsBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}
