#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} m_node;
m_node* create_node(int no){
    m_node* newnode=(m_node*)malloc(sizeof(m_node));
    newnode->next=NULL;
    newnode->data=no;
    return newnode;
};
m_node* insert_beginning(int no, m_node* head){
    m_node *t1, *t2;
    t1=create_node(no);
    t1->next=head;
    t2=head;
    while(t2->next==head){
        t2=t2->next;
    }
    head=t1;
    t2->next=head;
    return head;
}
m_node* insert_middle(int no, int pos, m_node* head){
    
}