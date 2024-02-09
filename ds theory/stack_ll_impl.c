#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node *next;
} NODE;
typedef struct stack{
    NODE *top;
} STACK;
STACK *s;
void init(STACK *s){
    s->top=NULL;
}
void push(STACK *s,char data){
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    nn->next=s->top;
    s->top=nn;
}
int isempty(STACK *s){
    if(s->top==NULL){
        printf("\nstack is empty!\n");
        return 1;
    }
    return 0;
}
void pop(STACK *s){
    if(!isempty(s)){
        NODE *t;
        t=s->top;
        s->top=s->top->next;
        t->next=NULL;
        free(t);
    }
}
void peep(STACK *s){
    if(!isempty(s)){
        printf("\nTop most element:%c\n",s->top->data);
    }
}
void display(STACK *s){
    NODE *t=s->top;
    printf("\n");
    if(!isempty(s)){
        while(t!=NULL){
            printf("%c\t",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
int main(){
    STACK *s;
    s=(STACK*)malloc(sizeof(STACK));
    init(s);
    char str[50], *ptr;
    printf("Enter the string:\n");
    scanf("%s",str);
    ptr=str;
    int i=0;
    while(ptr!='\0'){
        push(s,str[i]);
        i++;
        ptr++;
    }
    peep(s);
    display(s);
    for(int i=0;i<=10;i++)
    {
        pop(s);
        display(s);
    }
    peep(s);
    display(s);
}