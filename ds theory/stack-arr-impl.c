#include<stdio.h>
#include<stdlib.h>
#define MAX 7
struct stack 
{
    int top;
    int arr[MAX];
};
typedef struct stack stack;
stack *s;
void init(stack *s)
{
    s->top=-1;
}
int isempty(stack *s)
{
    if(s->top==-1)
    {
        printf("The stack is empty");
        return 1;
    }
    return 0;
}
int isfull(stack *s)
{
    if(s->top==MAX-1)
    {
        printf("The stack is full");
        return 1;
    }
    return 0;
}
void push(stack *s,int data)
{
    if(!isfull(s))
    {
        s->top++;
        s->arr[s->top]=data;
        printf("inserted:%d",s->arr[s->top]);
    }
}
void pop(stack *s)
{
    if(!isempty(s))
    {
        printf("deleted:%d",s->arr[s->top]);
        s->top--;
    }
}
void peep(stack *s)
{
    if(!isempty(s))
    {
        printf("the last element:%d",s->arr[s->top]);
        
    }
}
void display(stack *s)
{
    if(!isempty(s))
    {
        for(int i=s->top;i>=0;i--)
        {
            printf("%d",s->arr[i]);
        }
    }
}
int main()
{
    s=(stack*)malloc(sizeof(stack));
    init(s);
    for(int i=0;i<=MAX;i++)
       push(s,i^3);
    peep(s);
    display(s);
    for(int i=0;i<=MAX;i++)
    {
        pop(s);
    }
    peep(s);
    display(s);
}