#include<stdio.h>
#include<stdlib.h>
typedef struct node_t {
    int data;
    struct node_t *prev, *next;
} node;
node* allocate(int data){
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=data;
    p->prev=NULL;
    p->next=NULL;
    return p;
}
node* create(int data){
    node *head;
    head=allocate(data);
    return head;
}
node* insert(node *head,int data){
    if(head==NULL){
        printf("list is empty\n");
    } else {
        node *p, *q;
        q=allocate(data);
        if(head->data>=q->data){
            q->next=head;
            head->prev=q;
            head=q;
            return head;
        } else{
            p=head;
            while(p->next!=NULL && p->next->data<data){
                p=p->next;
            }
            if(p->next==NULL && p->data>q->data){
                q->next=p;
                q->prev=p->prev;
                p->prev=q;
            } else {
                q->prev=p;
                q->next=p->next;
                p->next=q;
            }
            return head;
        }
    }
}
int search(node *head,int data){
    node *p;
    p=head;
    int flg=0, pos=0;
    while(!flg && p!=NULL){
        pos++;
        if(data==p->data){
            flg=1;
        }
        p=p->next;
    }
    if(flg){
        return pos;
    }
    else {
        return 0;
    }
    
}
void display(node *head){
    node *p;
    p=head;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
node* merge(node *head1, node *head2){
    node *head, *t1, *t2, *p, *q, *s;
    int flg;
    if(head1->data<=head2->data){
        head=head1;
        t1=head;
        t2=head2;
    } else {
        head=head2;
        t1=head2;
        t2=head1;
    }
    s=head;
    p=t1->next;
    while(p!=NULL){
        flg=0;
        q=t2;
        while(!flg && q!=NULL){
            if(q->data<=p->data){
                s->next=q;
                t2=q->next;
                s=s->next;
                q=q->next;
            } else {
                flg=1;
            }
        }
        s->next=p;
        t1=p->next;
        s=s->next;
        p=t1;
    }
    if(t2!=NULL){
        s->next=t2;
    }
    return head;

}
int main(){
    int q;
    printf("Which program?(1 or 2)\n");
    scanf("%d",&q);
    switch(q){
        case 1:
        {
            int cho, new_data, pos;
            node *head;
            while(cho!=5){  
                printf("Select a choice:\n1.Create list\n2.Insert data\n3.Display list\n4.Search data\n5.Quit\n");
                scanf("%d",&cho);
                switch(cho){
                    case 1:
                    printf("Enter the first element:\n");
                    scanf("%d",&new_data);
                    head=create(new_data);
                    break;
                    case 2:
                    printf("Enter the element:\n");
                    scanf("%d",&new_data);
                    head=insert(head,new_data);
                    break;
                    case 3:
                    display(head);
                    break;
                    case 4:
                    printf("Enter the element:\n");
                    scanf("%d",&new_data);
                    pos=search(head,new_data);
                    if(pos){
                        printf("Element at position: %d\n",pos);
                    } else {
                        printf("Element not found!\n");
                    }
                    break;           
                }
            }
            
        }
        break;
        case 2:
        {
            node *head1, *head2, *head3;
            int n, new_data;
            printf("Enter the number of elements in list 1:\n");
            scanf("%d",&n);
            printf("Enter the first element:\n");
            scanf("%d",&new_data);
            head1=create(new_data);
            for(int i=2;i<=n;i++){
                printf("Enter the element:\n");
                scanf("%d",&new_data);
                head1=insert(head1,new_data);
            }
            display(head1);
            printf("Enter the number of elements in list 2:\n");
            scanf("%d",&n);
            printf("Enter the first element:\n");
            scanf("%d",&new_data);
            head2=create(new_data);
            for(int i=2;i<=n;i++){
                printf("Enter the element:\n");
                scanf("%d",&new_data);
                head2=insert(head2,new_data);
            }
            display(head2);
            head3=merge(head1,head2);
            printf("After merging the two lists:\n");
            display(head3);
            break;
        }
    }
}
