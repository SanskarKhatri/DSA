#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10
struct node{
    int data;
    struct node* next;
};
void create_adjList(struct node* l){
    int v,from,to;
    printf("\nEnter the number of vertices:");
    scanf("%d",&v);
    l[0].data=v;
    l[0].next=NULL;
    for(int i=1;i<=l[0].data;i++){
        l[i].data=i;
        l[i].next=NULL;
    }
    while(1){
        printf("\nEnter the edge(v1 v2):");
        scanf("%d %d",&from,&to);
        if(from<1 || from>l[0].data || to<1 ||  to>l[0].data || from==to){
            return;
        }
        struct node *t,*nn;
        t=&l[from];
        nn=(struct node*)malloc(sizeof(struct node));
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=nn;
        nn->data=to;
        nn->next=NULL;
    }
}
void display(struct node *l){
    struct node* t;
    for(int i=1;i<=l[0].data;i++){
        t=&l[i];
        printf("\n%d=> ",t->data);
        while(t->next!=NULL){
            t=t->next;
            printf("%d ",t->data);
        }
    }
}
void indegree(struct node *l,int v){
    struct node* t;
    int count=0;
    for(int i=1;i<=l[0].data;i++){
        t=&l[i];
        while(t->next!=NULL){
            t=t->next;
            if(t->data==v){
                count++;
            }
        }
    }
    printf("\nThe indegree of the vertex %d is %d.",v,count);
}
void outdegree(struct node *l, int v){
    struct node* t;
    int count=0;
    t=&l[v];
    while(t->next!=NULL){
        t=t->next;
        count++;
    }
    printf("\nThe outdegree of the vertex %d is %d.",v,count);
}
int main(){
    int ch,v;
    struct node l[MAX_NODES];
    create_adjList(l);
    while(1){
        printf("\n\nEnter the choice:");
        printf("\n1.Display");
        printf("\n2.Indegree of the node");
        printf("\n3.Outdegree of the node");
        printf("\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                display(l);
                break;
            case 2:
                printf("\nEnter the vertex:");
                scanf("%d",&v);
                indegree(l,v);
                break;
            case 3:
                printf("\nEnter the vertex:");
                scanf("%d",&v);
                outdegree(l,v);
                break;
            case 4:
                exit(0);
                break;
        }
    }
}