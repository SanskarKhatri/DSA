#include<stdio.h>
#include<stdlib.h>
struct node{
	int coeff;
	int px;
	int py;
	struct node *next;	
};
struct node* create(struct node *head){
	struct node *t1, *t2;
	int i, no, coeff, x, y;
	printf("Enter the number of terms:\n");
	scanf("%d",&no);
	for (i=1;i<=no;i++){
		t2=(struct node*)malloc(sizeof(struct node));
		printf("Enter the coeff:\n");
		scanf("%d",&coeff);
		t2->coeff=coeff;
		printf("Enter the px:\n");
		scanf("%d",&x);
		t2->px=x;
		printf("Enter the py:\n");
		scanf("%d",&y);
		t2->py=y;
		t2->next=NULL;
        if(i==1){
            head=t2;
            t1=head;
        } else {
            t1->next=t2;
		    t1=t2;
        }		
	}
    return head;
}
void display(struct node *head){
	struct node *t1;
    t1=head;
	while(t1->next!=NULL){
		printf("%dx^%dy^%d+",t1->coeff,t1->px,t1->py);
		t1=t1->next;
	}
    printf("%dx^%dy^%d\n",t1->coeff,t1->px,t1->py);
};
struct node* add_pol(struct node *head1, struct node *head2, struct node *res){
    struct node *t1,*t2, *t3, *r;
    int flg;
    t1=head1;
    r=NULL;
    while(t1!=NULL){
        t2=head2;
        flg=0;
        r=(struct node*)malloc(sizeof(struct node));
        r->px=t1->px;
        r->py=t1->py;
        r->next=NULL;
        while(t2!=NULL && !flg){
            if((t1->px==t2->px)&&(t1->py==t2->py)){
                r->coeff=(t1->coeff+t2->coeff);
                flg=1;
            }
            t2=t2->next;
        }
        if(!flg){
            r->coeff=t1->coeff;
        }
        if(res==NULL){
            res=r;
            t3=res;
        }
        t3->next=r;
        t3=r;
        r=NULL;
        t1=t1->next;
    }
    t1=head2;
    while(t1!=NULL){
        t2=res;
        flg=0;
        while(t2!=NULL && !flg){
            if(t1->px==t2->px && t1->py==t2->py){
                flg=1;
            }
            t2=t2->next;
        }
        if(!flg){
            r=(struct node*)malloc(sizeof(struct node));
            r->coeff=t1->coeff;
            r->px=t1->px;
            r->py=t1->py;
            r->next=NULL;
            t3->next=r;
            t3=r;
            r=NULL;
        }
        t1=t1->next;        
    }
    return res;
};
int main(){
	struct node *h1, *h2, *res;
    h1=NULL;
    h2=NULL;
    res=NULL;
	h1=create(h1);
    printf("The first polynomial is: ");
    display(h1);
	h2=create(h2);
    printf("The second polynomial is: ");
    display(h2);
    res=add_pol(h1,h2,res);
    printf("On adding the two polynomials: ");
	display(res);
}
