//cll is comb of 2 icr sorted ll joined end to end in a circular manner 
#include<stdio.h>
#include<stdlib.h>
#include"dll.c"
m_node *head1, *last1, *head2, *last2, *p;
void sort(){
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
            insert_end(data,last1);
        }
    }
    for(i=0;i<n;i++){
        if(i==0){
            printf("enter the first elemnt: ");
            scanf("%d",&data);
            head2=create_node(data);
            last2=head2;
        } else {
            printf("enter the elemnt: ");
            scanf("%d",&data);
            insert_end(data,last2);
        }
    }
    last1->next=head2;
    head2->prev=last1;
    last2->next=head1;
    head1->prev=last2;
    printf("Created cll.\n");
    p=head1;
    while(p!=head1->prev){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\t",p->data);

}
int main(){
    
}