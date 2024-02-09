#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

//struct node *head=NULL;
struct node* createnode(int no){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=no;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
struct node* insert_beginning(int no,struct node *head){
      struct node *t1;
      t1 = createnode(no);
      t1->next=head;
      head->prev=t1;
      head=t1;
      return head;
}
struct node* insert_end(int no,struct node *head){
      struct node *newnode,*last;
      newnode= createnode(no);
      last=head;
      while(last->next!=NULL)
        last=last->next;
      newnode->prev=last;
      last->next=newnode;
      newnode->next=NULL;
      return head;
}
void insert_middle(int no,int pos,struct node *head)
{
      struct node *t1,*newnode;
      newnode = createnode(no);
      t1=head;
      for(int i=1;i<pos-1;i++)
      {
          if(t1->next==NULL)
          {
            printf("Invalid position; inserted at the end of the list");
            break;
          }
          else
          {
            t1=t1->next;
          }
      }
      if(t1->next==NULL)
        {
         t1->next=newnode;
         newnode->prev=t1;
        }
      else
        {
        newnode->prev=t1;
        newnode->next=t1->next;
        t1->next=newnode;
        newnode->next->prev=newnode;
        }
return head;
}
struct node* delete_beginning(struct node *head){
    struct node *t1;
    t1=head;
    head=head->next;
    t1->next=NULL;
    head->prev=NULL;
    free(t1);
    return head;
}
struct node* delete_end(struct node *head){
    struct node *t1,*last;
    last=head;
    /*while(last->next->next!=NULL)
        last=last->next;
    t1=last->next;
    t1->prev=NULL;
    last->next=NULL;*/
    while(last->next!=NULL)
        last=last->next;
    last->prev->next=NULL;
    last->prev=NULL;
    free(t1);
    return head;
}
void delete_middle(int pos,struct node *head){
    struct node *t1,*t2;
    t1=head;
    printf("\n* ");
    for(int i=1;i<pos-1;i++)
      {
          if(t1->next==NULL)
          {
            printf("Invalid position");
            return 0;
          }
          else
          {
            t1=t1->next;
          }
          printf("\n%d ",i);
      }
      printf("\n** ");
      if(t1->next==NULL)
      {
          printf("\n*** ");
        printf("Position invalid");
      }
      else
      {
      t2=t1->next;
      if(t2->next==NULL)
      {
         t1->next=NULL;
         free(t2);
      }
      else{
      t1->next=t2->next;
      //t1=t2->next;
      t2->next->prev=t1;
      t2->prev=NULL;
      t2->next=NULL;
      printf("%d Element deleted",t2->data);
      free(t2);
      }
      }
      return head;
}
void display(struct node* head){
    struct node *t1;
    t1=head;
    printf("\n%d<->",t1->data);
    while(t1->next!=NULL)
    {
        t1=t1->next;
        printf("%d<->",t1->data);
    }
    printf("NULL\n");
}
void swap(struct node *t)
{
    struct node *temp;
    temp=t->next;
    t->next=t->prev;
    t->prev=temp;
}
struct node* reverse(struct node* head){
    struct node *t1,*t2;
    t1=head;

     while(t1->next!=NULL)
    {
        t1=t1->next;
    }
    head=t1;
    swap(t1);
    while(t1->next!=NULL)
    {
        t1=t1->next;
        swap(t1);
    }
    //swap prev and head

    return head;
}
struct node* delete_head(struct node* head){
        head=NULL;
        return head;
}

