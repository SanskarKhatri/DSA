#include<stdio.h>
#include<stdlib.h>
#define MAX 5
static int stack[MAX];

int isempty(int *top)
{
if((*top)==-1)
    {
    printf("The STACK is empty");
    return 1;
    }
return 0;
}
int isfull(int *top)
{
    if((*top)==(MAX-1))
    {
    printf("The STACK is full");
    return 1;
    }
return 0;
}

void push(int *top,int data)
{
    printf("\nPUSH:");
    if(!isfull(top))
    {
    (*top)++;//++*top;
    stack[*top]=data;
    printf("Element inserted: %d", stack[*top]);//data
    }
}

void peep(int *top)
{
    printf("\nPEEP:");
    if(!isempty(top))
        printf("The element in the topmost stack is:%d",stack[*top]);
}

void pop(int *top)
{
    printf("\nPOP:");
    if(!isempty(top))
    {
      printf("The element deleted: %d",stack[*top]);
      (*top)--;
    }
}
void display(int *top)
{
    printf("\nDisplay:");
    if(!isempty(top))
    {
        for(int i=*top;i>=0;i--)
            printf("%d ",stack[i]);
    }
}
int main()
{
    int *top;
    *top=-1;
    for (int i=0;i<=MAX;i++)//to access out of array
        push(top,i^3);
    peep(top);
    display(top);
    for (int i=0;i<=MAX;i++)//try deleting in an empty stack
        pop(top);
    peep(top);
    display(top);
}
