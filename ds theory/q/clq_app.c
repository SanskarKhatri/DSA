#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} NODE;
NODE* t;
NODE* createnode(int data){
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    return nn;
}
int isempty(NODE *front,NODE *rear){
    return (front==rear && front==NULL);
}
int isOneelement(NODE *front,NODE *rear){
    return (front==rear && front!=NULL);
}
void enqueue(NODE **front,NODE **rear,int data){
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->data=data;
    if(isempty(*front,*rear)){
        (*front)=nn;
        (*rear)=nn;
        nn->next=(*front);
    } else {
        (*rear)->next=nn;
        nn->next=(*front);
        (*rear)=nn;
    }
}
void dequeue(NODE **front,NODE **rear){
    if(isempty(*front,*rear)){
        printf("No element to dequeue!\n");
    } else if(isOneelement(*front,*rear)){
        (*front)=(*rear)=NULL;
    } else {
        t=(*front);
        (*front)=(*front)->next;
        free(t);
        (*rear)->next=(*front);
    }
}
void display(NODE *front,NODE *rear){
    if(!isempty(front,rear)){
        NODE* i;
        for(i=front;i->next!=front;i=i->next){
            printf("%d\t",i->data);
        }
        printf("%d\n",i->data);
    }
}
int main(){
    int n,i,k;
    NODE *front=NULL, *rear=NULL;
    printf("Enter the number of people:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        enqueue(&front,&rear,i);
    }
    display(front,rear);
    printf("Enter a random number:\n");
    scanf("%d",&k);
    while(front->next!=front){
        for(i=1;i<k;i++){
            front=front->next;
            rear=rear->next;
        }
        dequeue(&front,&rear);
        display(front,rear);
    }
    display(front,rear);
}