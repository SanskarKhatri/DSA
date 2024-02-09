#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} *head;
struct node *t1, *t2;
void create();
void insert();
void delete();
void display();
void deletion_middle();
void main(){
    int ch=0;
    while(ch!=5){
        printf("\nSelect the option:\n1.create\n2.insert\n3.delete\n4.display\n5.quit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\n");
            create();
            break;
            case 2:
            printf("\n");
            insert();
            break;
            case 3:
            printf("\n");
            delete();
            break;
            case 4:
            printf("\n");
            display();
            break;
            default:
            ch=5;
        }
    }
}
void create(){
    if(head==NULL){
        int no;
        head=(struct node*)malloc(sizeof(struct node));
        printf("enter the fisrt element: ");
        scanf("%d",&no);
        head->data=no;
        head->next=NULL;
    } else {
        printf("The list already exists.\n");
    }
}
void insert(){
    int ch, no;
    printf("Enter the element to be inserted:\n");
    scanf("%d",&no);
    printf("Enter your choice:\n1.Insert at beginning\n2.At end\n3.In the middle\n");
    scanf("%d",&ch);
    t1=(struct node*)malloc(sizeof(struct node));
    t1->data=no;
    switch(ch){
        case 1:
        {
            t1->next=head;
            head=t1;
            break;
        }
        case 2:
        {   
            t1->next=NULL;
            t2=head;
            while(t2->next!=NULL){
                t2=t2->next;
            }
            t2->next=t1;
            break;
        }
        case 3:
        {
            int pos;
            printf("Enter the position you want to insert at:\n");
            scanf("%d",&pos);
            t2=head;
            for(int i=1;i<pos-1;i++){
                if(t2->next!=NULL){
                    t2=t2->next;
                } else{
                    printf("Inappropriate position so inserted at the end.");
                    break;
                }
            }
            t1->next=t2->next;
            t2->next=t1;
            break;
        }
    }
}
void delete(){
    if(head==NULL){
        printf("list doesn\'t exist.");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else {
        int ch;
        printf("Enter your choice:\n1.delete from beginning\n2.from end\n3.from the middle\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
        {
            t1=head;
            head=head->next;
            free(t1);
            break;
        }
        case 2:
        {   
            t1=head;
            while(t1->next->next!=NULL){
                t1=t1->next;
            }
            t2=t1->next;
            t1->next=NULL;
            free(t2);
            break;
        }
        case 3:
        {
            deletion_middle();
            break;
        }
    }
    }
}
void deletion_middle(){
    int pos;
    printf("Enter the position you want to delete from:\n");
    scanf("%d",&pos);
    t1=head;
    for(int i=1;i<pos-1;i++){
        if(t1->next!=NULL){
            t1=t1->next;
        } else{
            printf("No element in the position.");
            return 0;
        }
    }
    t2=t1->next;
    t1->next=t2->next;
    free(t2);
}
void display(){
    if (head==NULL){
        printf("list is empty.\n");
    } else{
        t1=head;
        while(t1!=NULL){
            printf("%d\n",t1->data);
            t1=t1->next;
        }
    }
}