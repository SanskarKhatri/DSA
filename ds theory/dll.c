#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} m_node;
m_node *head=NULL,*last=NULL;
static int cnt=0;
m_node* create_node(int no){
    m_node* newnode;
    newnode=(m_node*)malloc(sizeof(m_node));
    newnode->data=no;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
m_node* insert_beginning(int no, m_node *head){
    m_node* newnode;
    newnode=create_node(no);
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    cnt++;
    return head;
}
void insert_middle(int no, int pos, m_node *head){
    m_node *t1, *newnode;
    newnode=create_node(no);
    t1=head;
    for(int i=1;i<pos-1;i++){
        t1=t1->next;
    }
    newnode->data=no;
    newnode->prev=t1;
    newnode->next=t1->next;
    t1->next->prev=newnode;
    t1->next=newnode;
    cnt++;
}
m_node* insert_end(int no, m_node *last){
    m_node* newnode;
    newnode=create_node(no);
    newnode->prev=last;
    last->next=newnode;
    last=newnode;
    cnt++;
    return last;
}
m_node* delete_beginning(m_node *head){
    m_node *t1;
    t1=head;
    head=head->next;
    head->prev=NULL;
    free(t1);
    cnt--;
    return head;
}
void delete_middle(int pos, m_node *head){
    m_node *t1, *t2;
    t1=head;
    for(int i=1;i<pos-1;i++){
        t1=t1->next;
    }
    t2=t1->next;
    t1->next=t2->next;
    t2->next->prev=t1;
    free(t2);
    cnt--;
}
m_node* delete_end(m_node *last){
    m_node *t1;
    t1=last;
    last=last->prev;
    last->next=NULL;
    free(t1);
    cnt--;
    return last;
}
void display(m_node *head){
    m_node* t1=head;
    while(t1!=NULL){
        printf("%d\t",t1->data);
        t1=t1->next;
    }
    printf("\n");
}
m_node* reverse_list(m_node *head){
    m_node* t1=head;
    while(t1->next!=NULL){
        t1=t1->next;
    }
    head=t1;
    swap(t1);
    while(t1->next!=NULL){
        t1=t1->next;
        swap(t1);
    }
    return head;

}
void swap(m_node *t1){
    m_node *t2;
    t2=t1->prev;
    t1->prev=t1->next;
    t1->next=t2;
    t2=NULL;
}