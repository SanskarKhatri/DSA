#include <stdio.h>
#include "Dll.c"

void main()
{
int no,pos,ch;
struct node *newnode;
do{
printf("\n Enter your choice \n1.create_node \n2.Inserting at the beginning \n 3.Inserting at the middle \n 4.Inserting at the end \n 5. Delete at the beginning \n 6. Delete at the middle \n 7.Delete at the end \n 8.Display \n 9. Reverse DLL ");
scanf("%d",&ch);
switch(ch)
{
case 1://Create
    {
        if(head==NULL)
        {
            printf("Enter the first element");
            scanf("%d",&no);
            head=createnode(no);
            last=head;
            cnt++;
        }
        else
            {
            printf("List already exists");
            }
        display(head);
        break;
    }
case 2://Ins Begin
    {
        if(head==NULL)
        {
            printf("Enter the first element");
            scanf("%d",&no);
            head=createnode(no);
            last=head;
            cnt++;
        }
        else
        {
            printf("Enter the element to be inserted");
            scanf("%d",&no);
            head=insert_beginning(no,head);
        }
        display(head);
        break;
    }
case 3://Ins Middle
    {
        if(head==NULL)
        {
            printf("Enter the first element");
            scanf("%d",&no);
            head=createnode(no);
            last=head;
            cnt++;
        }
        else
        {
            printf("Enter the first element");
            scanf("%d",&no);
            printf("Enter the position to be inserted");
            scanf("%d",&pos);
            if(pos<1 || pos>cnt)
                printf("Invalid position");
            else if(pos==1)
                head=insert_beginning(no,head);
            else
                insert_middle(pos,no,head);
        }
        display(head);
        break;
    }
    case 4://Insertion at end
        {
        if(head==NULL)
            {
            printf("Enter the first element");
            scanf("%d",&no);
            head=createnode(no);
            last=head;
            cnt++;
            }
        else
            {
            printf("Enter the first element");
            scanf("%d",&no);
            last=insert_end(no,last);
            }
            display(head);
            break;
            }
    case 5://Deletion at Beginning
            {
                struct node* t1;
                if(head==NULL)
                {
                    printf("list empty");
                }
                else if(head->next==NULL)
                {
                    head=NULL;
                    last=NULL;
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
                struct node* t1;
                if(head==NULL)
                {
                    printf("list empty");
                }
                else if(head->next==NULL)
                {
                    head=NULL;
                    last=NULL;
                }
                else
                {
                    printf("Enter the position to be deleted");
                    scanf("%d",&pos);
                    if(pos<1 || pos>cnt)
                        printf("Invalid position");
                    else if(pos==1)
                        head=delete_beginning(head);
                   /* else if(pos=cnt)
                        last=delete_end(last);*/
                    else
                        delete_middle(pos,head);
                }
                if(head!=NULL)
                    display(head);
                break;
            }
    case 7: // Deletion at end
            {
                if(head==NULL)
                {
                    printf("list empty");
                }
                else if(head->next==NULL)
                {
                    head=NULL;
                    last=NULL;
                }
                else
                {
                  last=delete_end(last);
                }
                //if(head!=NULL)
                    display(head);
                break;
            }
    case 8://Display
            {
                display(head);
            }
    case 9://Reverse the list
            {
                last=head;
                head=reverse(head);
                display(head);
                break;
            }
    }
}while(ch>0 && ch<10);
}
