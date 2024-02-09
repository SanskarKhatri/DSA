//cll is comb of 2 icr sorted ll joined end to end in a circular manner 
#include<stdio.h>
#include<stdlib.h>
#include"dll.c"
m_node *head1, *last1, *head2, *last2, *p;
m_node* sort_cll(m_node *head){
    m_node *t1, *t2;
    int m;
    t1=head;
    while(t1->next!=head){
        t2=t1->next;
        while(t2->next!=head){
            if(t1->data > t2->data){
                m=t1->data;
                t1->data=t2->data;
                t2->data=m;
            }
            t2=t2->next;
        }
        if(t1->data > t2->data){
            m=t1->data;
            t1->data=t2->data;
            t2->data=m;
        }
        t1=t1->next;
    }
    return head;
};
int main(){
    int n,i,data;
    printf("enter the no.of elements in the individual lists: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        if(i==0){
            printf("enter the first elemnt: ");
            scanf("%d",&data);
            head1=create_node(data);
            last1=head1;
        } else {
            printf("enter the elemnt: ");
            scanf("%d",&data);
            last1=insert_end(data,last1);
        }
    }
    display(head1);
    for(i=0;i<n;i++){
        if(i==0){
            printf("enter the first elemnt: ");
            scanf("%d",&data);
            head2=create_node(data);
            last2=head2;
        } else {
            printf("enter the elemnt: ");
            scanf("%d",&data);
            last2=insert_end(data,last2);
        }
    }
    display(head2);
    last1->next=head2;
    head2->prev=last1;
    last2->next=head1;
    head1->prev=last2;
    printf("Created cll.\n");
    p=head1;
    while(p->next!=head1){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
    head1=sort_cll(head1);
    printf("sorted cll:\n");
    p=head1;
    while(p->next!=head1){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}