#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}NODE;
typedef struct stack
{
    struct node *top;
}STACK;
void init(STACK *s)
{
    s->top=NULL;
}
int isempty(STACK *s)
{
    if(s->top==NULL)
    {
        printf("The stack is empty");
        return 1;
    }
    return 0;
}
void push(STACK *s,int data)
{
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->next=s->top;
    s->top=nn;
}
void pop(STACK *s)
{
    if(!isempty(s))
    {
        NODE *t;
        t=s->top;
        s->top=s->top->next;
        t->next=NULL;
        free(t);
    }
}
void peep(STACK *s)
{
    NODE *t=s->top;
    if(!isempty(s))
    {
        printf("Last element: %d",t->data);
    }
}
void display(STACK *s)
{
NODE *t=s->top;
    if(!isempty(s))
    {
        while(t!=NULL){
           printf("%d ",t->data);
           t=t->next;
        }
    }
}
int main()
{
    STACK *s;
    s=(STACK*)malloc(sizeof(STACK));
    init(s);
    for (int i=0;i<=4;i++)
        push(s,i^3);
    printf("\n PEEP:");
    peep(s);
    printf("\n Display after Push:");
    display(s);
    printf("\nPOP:");
    for (int i=0;i<=5;i++)//try deleting in an empty stack
        pop(s);
    printf("\n PEEP:");
    peep(s);
    printf("\n Display after Push:");
    display(s);
}

