#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;	
};
void display(struct node *head){
	struct node* t1=head;
	while(t1!=NULL){
		printf("%d\t",t1->data);
		t1=t1->next;
	}
	printf("\n");
};
struct node* delete_alt(struct node *head){
	struct node *p, *q;
	q=head;
	head=head->next;
	free(q);
	p=head;
	while(p!=NULL && p->next!=NULL){
		q=p->next;
		p->next=q->next;
		free(q);
		p=p->next;
	}
	return head;
}
int main(){
	int i, no, data;
	printf("Enter the number of elements in your list:\n");
	scanf("%d",&no);
	struct node *head, *t1, *t2;
	head=(struct node*)malloc(sizeof(struct node));
	t1=head;
	printf("Enter the first element:\n");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	for (i=2;i<=no;i++){
		t2=NULL;
		t2=(struct node*)malloc(sizeof(struct node));
		printf("Enter the element:\n");
		scanf("%d",&data);
		t2->data=data;
		t2->next=NULL;
		t1->next=t2;
		t1=t2;
		
	}
	printf("without deletion:\n");
	display(head);
	printf("after deletion:\n");
	head=delete_alt(head);
	display(head);
}
