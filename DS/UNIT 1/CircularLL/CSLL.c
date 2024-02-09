#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
typedef struct csll
{
    NODE *head;
    NODE *last;
    int cnt;
}LIST;

NODE *newnode,*t1,*t2;
void init_list(LIST *p)
{
    p->head=NULL;
    p->last=NULL;
    p->cnt=0;
}

NODE* create_node(int data)
{
  NODE *newnode;
  newnode=(NODE*)malloc(sizeof(NODE));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}

void ins_begin(LIST *p,int data)
{
    if(p->head==NULL)
    {
       newnode=create_node(data);
       if (newnode==NULL)
            printf("Node not allocated");
       p->head=newnode;
       p->last=newnode;
       p->head->next=p->head;//change
    }
    else
    {
        newnode=create_node(data);
        if (newnode==NULL)
            printf("Node not allocated");
        t1=p->head;
        p->head=newnode;
        p->head->next=t1;
        p->last->next=p->head;//change
    }
    p->cnt++;
}

void ins_middle(LIST *p,int data,int pos)
{
    if(p->head==NULL)
    {
       newnode=create_node(data);
       p->head=newnode;
       p->last=newnode;
       p->head->next=p->head;//change
    }
    else
    {
        newnode=create_node(data);
        t1=p->head;
        for(int i=1;i<pos-1;i++)
        {
            t1=t1->next;
        }
        newnode->next=t1->next;
        t1->next=newnode;
    }
    p->cnt++;
}
void ins_end(LIST *p,int data)
{
    if(p->head==NULL)
    {
       newnode=create_node(data);
       p->head=newnode;
       p->last=newnode;
       p->head->next=p->head;//change
    }
    else
    {
       newnode=create_node(data);
       p->last->next=newnode;
       p->last=newnode;
       p->last->next=p->head;//change
    }
    p->cnt++;
}
void del_begin(LIST *p)
{
   if(p->head==NULL)
    printf("\nList is empty");
   else if(p->head->next==p->head)//one node condition//change
   {
    p->head=NULL;
    p->last=NULL;
    p->cnt=0;
   }
   else
   {
       t1=p->head;
       p->head=p->head->next;
       t1->next=NULL;
       free(t1);
       p->last->next=p->head;//change
       p->cnt--;
   }
}
void del_middle(LIST *p,int pos)
{
   if(p->head==NULL)
    printf("\nList is empty");
   else if(p->head->next==p->head)//one node condition//change
   {
    p->head=NULL;
    p->last=NULL;
    p->cnt=0;
   }
   else
   {
       t1=p->head;
       for(int i=1;i<pos-1;i++)
        t1=t1->next;
       t2=t1->next;
       t1->next=t2->next;
       t2->next=NULL;
       free(t2);
       p->cnt--;
   }
}

void del_end(LIST *p)
{
   if(p->head==NULL)
    printf("\nList is empty");
   else if(p->head->next==p->head)//one node condition//change
   {
    p->head=NULL;
    p->last=NULL;
    p->cnt=0;
   }
   else
   {
        t1=p->head;
        while(t1->next!=p->last)
            t1=t1->next;
        t1->next=p->head;
        free(p->last);
        p->last=t1;
        p->cnt--;
   }
}
void display(LIST *p)
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
int main()
{
 LIST *p;
 p=(LIST*)malloc(sizeof(LIST));
 init_list(p);
 display(p);
 ins_begin(p,10);
 display(p);
 ins_end(p,30);
 display(p);
 ins_middle(p,20,2);
 display(p);
 del_middle(p,2);
 display(p);
 del_begin(p);
 display(p);
 del_end(p);
 display(p);
}
