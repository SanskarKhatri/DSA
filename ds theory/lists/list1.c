#include<stdio.h>
#define MAX 50
typedef struct arrlst{
    int a[MAX];
    int index;
} ARRLST;
void init(ARRLST *p){
    p->index=-1;
}
int append(ARRLST *p, int data){
    if(p->index==MAX-1){
        return 0;
    } else {
        p->index++;
        p->a[p->index]=data;
        return 1;
    }
}
int dellst(ARRLST *p, int *data){
    if(p->index==-1){
        return 0;
    } else {
        *data=p->a[p->index];
        p->index--;
        return 1;
    }
}
void display(ARRLST *p){
    if(p->index==-1){
        printf("The list is empty.\n");
    } else {
        for(int i=0;i<=p->index;i++){
            printf("%d\t",p->a[i]);
        }
        printf("\n");
    }
}
void main(){
    ARRLST mylist;
    int l,data,res,p;
    init(&mylist);
    printf("Enter the number of elements in the list:\n");
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        printf("Enter the element:\n");
        scanf("%d",&data);
        res=append(&mylist,data);
        if(!res){
            printf("The list is full");
        }
    }
    display(&mylist);
    res=dellst(&mylist,&p);
    printf("After popping:\n");
    display(&mylist);
    
}