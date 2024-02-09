#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *nn,*t;
struct node* createnode(int data){
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->prev=nn->next=NULL;
    return nn;
}
int isempty(struct node **f,struct node **r){
    return (f==r && *f==NULL);
}
int isOneElement(struct node **f,struct node **r){
    return (f==r && *f!=NULL);
}
void insertRear(struct node **f,struct node **r,int data){
    nn=createnode(data);
    if(isempty(f,r)){
        *f=*r=nn;
    }else {
        (*r)->next=nn;
        nn->prev=*r;
        *r=nn;
    }
}
void insertFront(struct node **f,struct node **r,int data){
    nn=createnode(data);
    if(isempty(f,r)){
        *f=*r=nn;
    }else {
        (*f)->prev=nn;
        nn->next=*f;
        *f=nn;
    }
}
void deleteFront(struct node **f,struct node **r){
    if(isempty(f,r)){
        printf("QUEUE is empty!\n");
    }else if(isOneElement(f,r)){
        t=*f;
        *f=*r=NULL;
        free(t);
    } else{
        t=*f;
        *f=(*f)->next;
        (*f)->prev=NULL;
        t->next=NULL;
        free(t);
    }
}
void deleteRear(struct node **f,struct node **r){
    if(isempty(f,r)){
        printf("QUEUE is empty!\n");
    }else if(isOneElement(f,r)){
        t=*f;
        *f=*r=NULL;
        free(t);
    } else{
        t=*r;
        *r=(*r)->prev;
        (*r)->next=NULL;
        t->prev=NULL;
        free(t);
    }
}
void display(struct node **f,struct node **r){
    if(isempty(f,r)){
        printf("QUEUE is empty!\n");
    } else {
        t=*f;
        for(t=*f;t!=NULL;t=t->next){
            printf("%d\t",t->data);
        }
        printf("\n");
    }

}
int main(){
    struct node *front, *rear;
    insertRear(&front,&rear,5); //First element
    display(&front,&rear);
    insertFront(&front,&rear,10); //Front end insertion
    display(&front,&rear);
    insertRear(&front,&rear,15);//Rear end insertion
    display(&front,&rear);
    deleteRear(&front,&rear); //Rear end deletion
    display(&front,&rear);
    deleteFront(&front,&rear); //Front end deletion
    display(&front,&rear);
    deleteFront(&front,&rear);//One element deletion
    display(&front,&rear);
}