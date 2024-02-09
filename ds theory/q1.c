#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} *head;
struct node *t1, *t2;
void create();
void insert();
void display();
void find_unique();
void main(){
    int ch=0;
    while(ch!=5){
        printf("\nSelect the option:\n1.create\n2.insert\n3. Find unique element\n4.display\n5.quit\n");
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
            find_unique();
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
    t1=(struct node*)malloc(sizeof(struct node));
    t1->data=no;
    t1->next=NULL;
    t2=head;
    while(t2->next!=NULL){
        t2=t2->next;
    }
    t2->next=t1;
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
void find_unique(){
    int flg;
    t1=head;
    while(t1!=NULL){
        flg=0;
        t2=head;
        while(t2!=NULL){
            if(t1!=t2 && t2->data==t1->data){
                flg=1;
            }
            t2=t2->next;
        }
        if(!flg){
            printf("%d\t",t1->data);
        }
        t1=t1->next;
    }
}