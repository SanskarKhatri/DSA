#include<stdio.h>
#include<stdlib.h>
# define SIZE 5
struct node {
    int d;
    int p;
};
struct node deque[SIZE];
int isempty(int f, int r){
    return (f==r && f==-1);
}
int isOneelement(int f,int r){
    return (f==r && f!=-1);
}
int isfull(int f,int r){
    return r==SIZE-1;
}
void enqueue(int *f,int *r,int d,int p){
    int t1,t2;
    if(isempty(*f,*r)){
        *f=*r=0;
        deque[*f].d=d;
        deque[*f].p=p;
    } else if(isfull(*f,*r)){
        printf("QUEUE is full! Cannot perform insertion!\n");
    } else {
        t1=*f;
        while(deque[t1].p>=p){
            t1++;
        }
        t2=++(*r);
        while(t2>t1){
            deque[t2].d=deque[t2-1].d;
            deque[t2].p=d=deque[t2-1].p;
            t2--;
        }
        deque[t2].d=d;
        deque[t2].p=p;
    }
}
void dequeue(int *f,int *r){
    if(isempty(*f,*r)){
        printf("QUEUE is empty! Cannot dequeue!\n");
    } else if(isOneelement(*f,*r)){
        *f=*r=-1;
    } else {
        ++(*f);
    }
}
void display(int f,int r){
    if(!isempty(f,r)){
        for(int i=f;i<=r;i++){
            printf("%d-%d\t",deque[i].d,deque[i].p);
        }
        printf("\n");
    }
}
int main(){
    int front=-1,rear=-1;
    printf("\n%d %d\n",front,rear);
    enqueue(&front,&rear,5,2);//ins 1st ele
    display(front,rear);
    enqueue(&front,&rear,10,4);//ins at front
    display(front,rear);
    enqueue(&front,&rear,15,3);//ins at middle
    display(front,rear);
    enqueue(&front,&rear,25,1);//ins at rear
    display(front,rear);
    for(int i=0;i<3;i++)
    {
        dequeue(&front,&rear);//del at front
        display(front,rear);
    }
}