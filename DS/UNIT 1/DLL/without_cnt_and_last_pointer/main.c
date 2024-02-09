#include<stdio.h>
#include<stdlib.h>
#include "dll.c"

void main()
{
    int ch,no,pos;
    struct node *head=NULL,*t1;
    printf("Doubly Linked List");
    do{
    printf("choose the operations to be performed on the DLL");
    printf("\n 1. Create DLL \n 2. Insert element at beginning\n 3. Insert element at middle \n 4. Insert element at end\n 5. delete element at beginning\n 6. delete element at middle\n 7. delete element at end \n 8. display the list \n 9. reverse the list");
    scanf("%d",&ch);
    switch(ch){
    case 1: //1. Create DLL
            {
                if(head==NULL)
                {
                    printf("Enter the first element");
                    scanf("%d",&no);
                    head=createnode(no);
                }
                else
                    printf("List already exists");
                display(head);
                break;
            }
    case 2://Insertion at beginning
            {
                if (head!=NULL)
                {
                    printf("Enter the element to be inserted");
                    scanf("%d",&no);
                    head=insert_beginning(no,head);
                }
                else
                {
                    printf("Enter the first element");
                    scanf("%d",&no);
                    head=createnode(no);
                }
                display(head);
                break;
            }
    case 4://Insertion at end
            {
                if (head!=NULL)
                {
                    printf("Enter the element to be inserted");
                    scanf("%d",&no);
                    head=insert_end(no,head);
                }
                else
                {
                    printf("Enter the first element");
                    scanf("%d",&no);
                    head=createnode(no);
                }
                display(head);
                break;
            }
    case 3://Insertion at middle
            {
                if (head!=NULL)
                {
                    printf("Enter the element to be inserted");
                    scanf("%d",&no);
                    printf("Enter the position to be inserted");
                    scanf("%d",&pos);
                    if(pos<1)
                        printf("invalid position");
                    else if(pos==1)
                        head=insert_beginning(no,head);
                    else
                        insert_middle(no,pos,head);
                }
                else
                {
                    printf("Enter the first element");
                    scanf("%d",&no);
                    head=createnode(no);
                }
                display(head);
                break;
            }
    case 5://Deletion at Beginning
            {
                if(head==NULL)
                {
                    printf("cannot perform deletion");
                }
                else if(head->next==NULL )
                {
                    t1=head;
                    head=NULL;
                    free(t1);
                }
                else
                {
                    head=delete_beginning(head);
                }
                display(head);
                break;
            }
    case 6://Deletion at middle
            {
                if(head==NULL)
                {
                    printf("cannot perform deletion");
                }
                else if(head->next==NULL)
                {
                    printf("**");
                    t1=head;
                    head=NULL;
                    free(t1);
                }
                else
                {
                printf("Enter the position to be deleted");
                scanf("%d",&pos);
                if(pos<1)
                    printf("invalid position");
                else if(pos==1){
                    head=delete_beginning(head);
                }
                else
                    delete_middle(pos,head);
                }
                display(head);
                break;
            }
    case 7: // Deletion at end
            {
                if(head==NULL)
                {
                    printf("cannot perform deletion");
                }
                else if(head->next==NULL)
                {
                    t1=head;
                    head=NULL;
                    free(t1);
                }
                else
                {
                head=delete_end(head);
                }
                display(head);
                break;
            }
    case 8://Display
            {
                printf("Doubly Linked List");
                if(head==NULL)
                {
                    printf("the list is empty");
                }
                else
                    display(head);
                break;
            }
    case 9://Reverse the list
            {
                head=reverse(head);
                display(head);
                break;
            }
    }
}while(ch>0 && ch<10);
}
