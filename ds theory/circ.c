//singly circular linked list
// #include<stdio.h>
// #include<stdlib.h>
// typedef struct node
// {
//     int data;
//     struct node* next;
// }node;
// typedef struct csll
// {
//     node* head;
//     node *last;
//     int count;
// }list;
// list *p;
// node *newnode,*t1,*t2;
// void init(list *p)
// {
//     p->head=NULL;
//     p->last=NULL;
//     p->count=0;
// }
// node* create(int data)
// {
//     newnode=(node*)malloc(sizeof(node));
//     newnode->data=data;
//     newnode->next=NULL;
//     return newnode;
// }
// void insbeg(list *p,int data)
// {
//     if(p->head==NULL)
//     {
//         newnode=create(data);
//         p->head=newnode;
//         p->last=newnode;
//         p->head->next=p->head; //change
//     }
//     else
//     {
//         newnode=create(data);
//         t1=p->head;
//         p->head=newnode;
//         p->head->next=t1;
//         p->last->next=p->head; //change
//     }
//     p->count++;
// }
// void insmid(list *p,int data,int pos)
// {
//     if(p->head==NULL)
//     {
//         newnode=create(data);
//         p->head=newnode;
//         p->last=newnode;
//         p->head->next=p->head; //change
//     }
//     else
//     {
//         newnode=create(data);
//         t1=p->head;
//         for(int i=1;i<pos-1;i++)
//         {
//             t1=t1->next;
//         }
//         newnode->next=t1->next;
//         t1->next=newnode;
//     }
//     p->count++;
// }
// void insend(list *p,int data)
// {
//     if(p->head==NULL)
//     {
//         newnode=create(data);
//         p->head=newnode;
//         p->last=newnode;
//         p->head->next=p->head; //change
//     }
//     else
//     {
//         newnode=create(data);
//         p->last->next=newnode;
//         p->last=newnode;
//         p->last->next=p->head; //change
//     }
//     p->count++;
// }
// void delbeg(list *p)
// {
//     if(p->head==NULL) 
//        printf("List is empty");
//     else if(p->head->next==p->head)
//     {
//         p->head=NULL;
//         p->last=NULL;
//         p->count=0;
//     }
//     else
//     {
//         t1=p->head;
//         p->head=p->head->next;
//         t1->next=NULL;
//         free(t1);
//         p->last->next=p->head;  //change
//         p->count--;
//     }
// }
// void delmid(list *p,int pos)
// {
//     if(p->head==NULL) 
//        printf("List is empty");
//     else if(p->head->next==p->head)
//     {
//         p->head=NULL;
//         p->last=NULL;
//         p->count=0;
//     }
//     else
//     {
//         t1=p->head;
//         for(int i=1;i<pos-1;i++)
//           t1=t1->next;
//         t2=t1->next;
//         t1->next=t2->next;
//         t2->next=NULL;
//         free(t2);
//         p->count--;
//     }
// }
// void delend(list *p)
// {
//     if(p->head==NULL) 
//        printf("List is empty");
//     else if(p->head->next==p->head)
//     {
//         p->head=NULL;
//         p->last=NULL;
//         p->count=0;
//     }
//     else
//     {
//         t1=p->head;
//         while(t1->next!=p->last)
//             t1=t1->next;
//         t1->next=p->head;
//         free(p->last);
//         p->last=t1;
//         p->count--;
//     }
// }
// void display(list *p)
// {
//     if(p->head==NULL)
//       printf("Nothing to display");
//     else
//     {
//         for(t1=p->head;t1!=p->last;t1=t1->next)
//           printf("%d\t",t1->data);
//         printf("%d\t",t1->data);
//         // for(int i=1;i<=p->count;i++)
//         //    printf("%d",t1->data);
//     }
// }
// int main()
// {
//     p=(list*)malloc(sizeof(list));
//     init(p);
//     insbeg(p,10);
//     insend(p,30);
//     insmid(p,20,2);
//    delmid(p,2);
//     //delbeg(p);
//     //delend(p);
//     display(p);
// }

//doubly circular linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;
typedef struct cdll
{
    node* head;
    node *last;
    int count;
}list;
node *newnode,*t1,*t2;
void init(list* p)
{
    p->count=0;
    p->head=NULL;
    p->last=NULL;
}
node* create(int no)
{
    newnode=(node*)malloc(sizeof(node));
    newnode->data=no;
    return newnode;
}
void insbeg(list* p,int no)
{
    newnode=create(no);
    if(p->head==NULL)
    {
        p->head=newnode;
        p->last=newnode;
        p->head->prev=p->last;
        p->last->next=p->head;
        p->count++;
    }
    else
    {
        p->head->prev=newnode;
        newnode->next=p->head;
        p->head=newnode;
        p->head->prev=p->last;
        p->last->next=p->head;
        p->count++;
    }
}
void insend(list* p,int no)
{
    newnode=create(no);
    if(p->head==NULL)
    {
        p->head=newnode;
        p->last=newnode;
        p->head->prev=p->last;
        p->last->next=p->head;
        p->count++;
    }
    else
    {
    p->last->next=newnode;
    newnode->prev=p->last;
    p->last=newnode;
    p->head->prev=p->last;
    p->last->next=p->head;
    p->count++;
    }
}
void delbeg(list* p)
{
    if(p->head==NULL)
    {
        printf("list is empty");
    }
    else if(p->head->next==p->head)  //one node condition
    {
        t1=p->head;
        free(t1);
        p->head=NULL;
        p->last=NULL;
        p->count=0;
    }
    else
    {
        t1=p->head;
        p->head=p->head->next;
        p->head->prev=p->last;
        p->last->next=p->head;
        p->count--;
        t1->next=t1->prev=NULL;
        free(t1);
    }
}
void delend(list* p)
{
    if(p->head==NULL)
    {
        printf("list is empty");
    }
    else if(p->head->next==p->head)  //one node condition
    {
        t1=p->head;
        free(t1);
        p->head=NULL;
        p->last=NULL;
        p->count=0;
    }
    else
    {
        t1=p->last;
        p->last=p->last->prev;
        p->last->next=p->head;
        p->head->prev=p->last;
        p->count--;
        t1->next=t1->prev=NULL;
        free(t1);
    }
}
void display(list *p)
{
    if(p->head==NULL)
      printf("Nothing to display");
    else
    {
        for(t1=p->head;t1!=p->last;t1=t1->next)
          printf("%d\t",t1->data);
        printf("%d\t",t1->data);
        // for(int i=1;i<=p->count;i++)
        //    printf("%d",t1->data);
    }
}
int main()
{
    list *p;
    p=(list*)malloc(sizeof(list));
    init(p);
    insbeg(p,10);
    insend(p,30);
    //delbeg(p);
    delend(p);
    display(p);
}