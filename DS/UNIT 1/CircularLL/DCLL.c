#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *prev;
   struct node *next;
}NODE;
typedef struct list
{
   int cnt;
   NODE *head;
   NODE *last;
}DCLL;
NODE *newnode,*t1,*t2;
void init(DCLL *p)
{
    p->cnt=0;
    p->head=NULL;
    p->last=NULL;
}

NODE* createnode(int no)
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=no;
    return newnode;
}

void ins_beg(DCLL *p,int no)
{
    newnode=createnode(no);
    if(p->head==NULL)
    {
        p->head=newnode;
        p->last=newnode;
        p->head->prev=p->last;//c
        p->last->next=p->head;//c
        p->cnt++;
    }
    else{
        p->head->prev=newnode;
        newnode->next=p->head;
        p->head=newnode;
        p->head->prev=p->last;//c
        p->last->next=p->head;//c
        p->cnt++;
    }
}

void ins_end(DCLL *p,int no)
{
    newnode=createnode(no);
    if(p->head==NULL)
    {
        p->head=newnode;
        p->last=newnode;
        p->head->prev=p->last;//c
        p->last->next=p->head;//c
        p->cnt++;
    }
    else{
    p->last->next=newnode;
    newnode->prev=p->last;
    p->last=newnode;
    p->head->prev=p->last;//c
    p->last->next=p->head;//c
    p->cnt++;
    }
}

void del_beg(DCLL *p)
{
    if(p->head==NULL)//empty list condition
    {
        printf("\nList is empty");
    }
    else if(p->head->next==p->head)//one node condition
    {
        t1=p->head;
        free(t1);
        p->head=NULL;
        p->last=NULL;
        p->cnt=0;
    }
    else{
        t1=p->head;
        p->head=p->head->next;
        p->head->prev=p->last;//c
        p->last->next=p->head;//c
        p->cnt--;
        t1->next=t1->prev=NULL;
        free(t1);
    }
}

void del_end(DCLL *p)
{
    if(p->head==NULL)//empty list condition
    {
        printf("\nList is empty");
    }
    else if(p->head->next==p->head)//one node condition
    {
        t1=p->head;
        free(t1);
        p->head=NULL;
        p->last=NULL;
        p->cnt=0;
    }
    else{
        t1=p->last;
        p->last=p->last->prev;
        p->last->next=p->head;//c
        p->head->prev=p->last;//c
        p->cnt--;
        t1->next=t1->prev=NULL;
        free(t1);
    }
}
void display(DCLL *p)
{
    if(p->head==NULL)
        printf("\nList is empty");
    else
    {
        printf("\n");
        /*
       for(t1=p->head;t1!=p->last;t1=t1->next)
            printf("%d ",t1->data);
        printf("%d",t1->data);*/

        t1=p->head;
        for(int i=1;i<=p->cnt;i++)
        {
            printf("%d ",t1->data);
            t1=t1->next;
        }
    }
}




