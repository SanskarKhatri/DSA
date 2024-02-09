#include<stdio.h>
#include<stdlib.h>
#define MAX 7
struct stack
{
    int top;
    int arr[MAX];
};
typedef struct stack STACK;
STACK *s;

void init(STACK *s)
{
    s->top=-1;
}
int isempty(STACK *s)
{
if(s->top==-1)
    {
    printf("The STACK is empty");
    return 1;
    }
return 0;
}
int isfull(STACK *s)
{
    if(s->top==MAX-1)
    {
    printf("The STACK is full");
    return 1;
    }
return 0;
}

void push(STACK *s,int data)
{
    printf("\nPUSH:");
    if(!isfull(s))
    {
    s->top++;
    s->arr[s->top]=data;
    printf("Element inserted: %d", s->arr[s->top]);//data
    }
}

void peep(STACK *s)
{
    printf("\nPEEP:");
    if(!isempty(s))
        printf("The element in the topmost stack is:%d",s->arr[s->top]);
}

void pop(STACK *s)
{
    printf("\nPOP:");
    if(!isempty(s))
    {
      printf("The element deleted: %d",s->arr[s->top]);
      s->top--;
    }
}
void display(STACK *s)
{
    printf("\nDisplay:");
    if(!isempty(s))
    for(int i=s->top;i>=0;i--)
        printf("%d ",s->arr[i]);
}
int main()
{
    s=(STACK*)malloc(sizeof(STACK));
    init(s);
    for (int i=0;i<=MAX;i++)//to access out of array
        push(s,i^3);
    peep(s);
    display(s);
    for (int i=0;i<=MAX;i++)//try deleting in an empty stack
        pop(s);
    peep(s);
    display(s);
}
