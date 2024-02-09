#include<stdio.h>
#include"dll.c"
m_node* rm_duplicates(m_node* head){
    int pos1,pos2;
    m_node *t1, *t2;
    t1=head;
    pos1=1;
    while(t1!=NULL && t1->next!=NULL){
        t2=t1->next;
        pos2=pos1+1;
        while(t2!=NULL){
            if(t2->data==t1->data){
                t2=t2->next;
                delete_middle(pos2,head);
            }else{
                t2=t2->next;
                pos2++;
            }
        }
        pos1++;
        t1=t1->next;
    }
    return head;
};
void main(){
    int no, pos, ch=1;
    m_node* newnode;
    while(ch){
        printf("\nEnter you choice: \n1. Create node \n2. Insert \n3. Display \n4. remove duplicates\n0. Quit.");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                {
                    if(head==NULL){
                        printf("Enter the first element:\n");
                        scanf("%d",&no);
                        head=create_node(no);
                        last=head;
                        cnt++;
                    } else {
                        printf("List already exists.\n");
                    }
                    break;
                }
            case 2:
                {
                    if(head==NULL){
                        printf("Enter the first element:\n");
                        scanf("%d",&no);
                        head=create_node(no);
                        last=head;
                        cnt++;
                    } else {
                        printf("Enter the element:\n");
                        scanf("%d",&no);
                        last=insert_end(no,last);
                    }
                    break;
                }
            case 3:
                {
                    if(head==NULL){
                        printf("The list is empty.\n");
                    } else {
                        display(head);
                    }
                    break;
                }
            case 4:
                {
                    if(head==NULL){
                        printf("The list is empty.\n");
                    } else {
                        head=rm_duplicates(head);
                    }
                    break;
                }
            default:
                {
                    ch=0;
                }
            
        }
        }
    
}