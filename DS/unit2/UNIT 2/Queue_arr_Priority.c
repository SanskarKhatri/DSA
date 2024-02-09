#include<stdio.h>
#define SIZE 5
typedef struct pq
{
    int data;
    int priority;
}PQ;
struct pq queue[SIZE];

void init(int *front,int *rear)
{
    *front=-1;
    *rear=-1;
}
int isempty(int front,int rear)
{
    return (front==-1 && rear==-1);
}
int isfull(int front,int rear)
{
    return (rear==SIZE-1);
}
void enqueue(int *front,int *rear,int data,int priority)
{

   if(isfull(*front,*rear))
        printf("\nQueue is full");
   else if(isempty(*front,*rear))
        {
        *front=*rear=0;
        //queue[*rear]=createnode(data,priority);
        queue[*rear].data=data;//change
        queue[*rear].priority=priority;
        }
   else//change
   {
       int t1,t2;
       t1=*front;
       while(queue[t1].priority>=priority)
            t1++;
       ++*rear;
       t2=*rear;
       while(t2>t1)
       {
          queue[t2].data=queue[t2-1].data;
          queue[t2].priority=queue[t2-1].priority;
          t2--;
       }
        queue[t1].data=data;
        queue[t1].priority=priority;
   }
}
int isOneElement(int front,int rear)
{
    return front==rear && rear!=-1;
}
void dequeue(int *front,int *rear)
{
    if(isempty(*front,*rear))
    {
        printf("Queue is empty");
    }
    else if(isOneElement(*front,*rear)){
        *front=-1;
        *rear=-1;
    }
    else
    {
        (*front)++;
    }
}
void display(int front,int rear)
{
    printf("\n");
    if(!(isempty(front,rear)))
       {
          for(int i=front;i<=rear;i++)
                printf("%d-%d ",queue[i].data,queue[i].priority);
       }
}
int main()
{
    int front,rear,i;
    init(&front,&rear);
    printf("\n%d %d",front,rear);
    enqueue(&front,&rear,5,2);
    display(front,rear);
    enqueue(&front,&rear,10,4);
    display(front,rear);
    enqueue(&front,&rear,15,3);
    display(front,rear);
    enqueue(&front,&rear,25,1);
    display(front,rear);
    for(i=0;i<3;i++)
    {
        dequeue(&front,&rear);
        display(front,rear);
    }
    return 0;
}
