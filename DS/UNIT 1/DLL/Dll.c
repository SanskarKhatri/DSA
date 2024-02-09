#include<stdio.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*last=NULL;
static int cnt=0;
struct node* createnode(int no)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=no;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
struct node* insert_beginning(int no,struct node* head)
{
        struct node* newnode;
        newnode=createnode(no);
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        cnt++;
        return head;
}
void insert_middle(int pos,int no,struct node* head)
{
    struct node* t1,*newnode;
    newnode=createnode(no);
    t1=head;
    for(int i=1;i<pos-1;i++)
        {
        t1=t1->next;
        }
    newnode->prev=t1;
    newnode->next=t1->next;
    t1->next->prev=newnode;
    t1->next=newnode;
    cnt++;
}

struct node* insert_end(int no,struct node* last){
    struct node *newnode;
    newnode=createnode(no);
    newnode->prev=last;
    last->next=newnode;
    last=newnode;
    cnt++;
    return last;
}

struct node* delete_beginning(struct node* head){
    struct node* t1;
    t1=head;
    head=head->next;
    t1->next=NULL;
    head->prev=NULL;
    free(t1);
    cnt--;
    return head;
}
void delete_middle(int pos,struct node* head){
    struct node* t1,*t2;
    t1=head;
    for(int i=1;i<pos-1;i++)
    {
        t1=t1->next;
    }
    t2=t1->next;
    t1->next=t1->next->next;
    t1->next->prev=t1;
    t2->next=NULL;
    t2->prev=NULL;
    free(t2);
    cnt--;
}
struct node* delete_end(struct node* last){
    struct node* t1;
    t1=last;
    last=last->prev;
    t1->prev=NULL;
    last->next=NULL;
    free(t1);
    cnt--;
    return last;
}
void display(struct node* head){
    if(head!=NULL){
    struct node *t1;
    t1=head;
    printf("%d<->",t1->data);
    while(t1->next!=NULL)
    {
        t1=t1->next;
        printf("%d<->",t1->data);
    }
    printf("NULL");
    }
    else
        printf("Empty list");
}

struct node* reverse(struct node *head)
{
    struct node *t1;
    if(head!=NULL)
    {
        t1=head;
        while(t1->next!=NULL)
        {
        t1=t1->next;
        }
        head=t1;
        swap(t1);//swap address in prev and next
        while(t1->next!=NULL)
        {
        t1=t1->next;
        swap(t1);
        }
    }
    //swap prev and head*/
    return head;
}
void swap(struct node *t)
{
    struct node *temp;
    temp=t->next;
    t->next=t->prev;
    t->prev=temp;
}
