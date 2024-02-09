#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*head;
struct node *t1,*t2;
int main()
{
    int ch;
    do
    {
    printf("\nEnter your choice \n1.Create a SLL \n2.Insert an element \n3.Delete an element \n4.Display the elements in the list 5. Exit");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        create();
        display();
        break;
    case 2:
        insert();
        display();
        break;
   case 3:
        delete_ele();
        display();
        break;
    case 4:
        display();
        break;
    }
    }while(ch==1||ch==2||ch==3||ch==4);
    return 0;
}
void create()
{
if (head==NULL)
{
    int no;
    printf("\nEnter the no. to be inserted");
    scanf("%d",&no);
    head=(struct node*)malloc(sizeof(struct node));
    head->data=no;
    head->next=NULL;
    //last=head;
}
else
    printf("\nlist already exists");
}
void insert()
{
if(head==NULL)
    create();
else
{
   int ch;
   int no;
    printf("\nEnter the no. to be inserted");
    scanf("%d",&no);
    printf("\nEnter your choice: 1.Insert at the begining 2.At End 3. At middle ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
            t1=(struct node*)malloc(sizeof (struct node));
            t1->data=no;
            t1->next=head;
            head=t1;
            break;
        }
    case 2:
        {
            t1=(struct node*)malloc(sizeof (struct node));
            t1->data=no;
            t1->next=NULL;
            t2=head;
            while(t2->next!=NULL)
            {
                t2=t2->next;
            }
            //t2 is pointing to the last node
            t2->next=t1;//last->next=t1;last=t1;
            break;
        }
    case 3:
        {
            int pos;
            printf("Enter the position to be inserted");
            scanf("%d",&pos);
            t2=head;
            for(int i=1;i<pos-1;i++)
            {
                if(t2->next!=NULL)
                    t2=t2->next;
                else
                {
                    printf("inappropriate position;inserted at the end");
                    break;
                }
            }
            t1=(struct node*)malloc(sizeof (struct node));
            t1->data=no;
            if(pos==1)
            {
                t1->next=head;
                head=t1;
            }
            else{
            t1->next=t2->next;
            t2->next=t1;
            }
            break;
        }
    }
}

}
void display()
{
    if(head==NULL)
    {
        printf("\nThe list is empty");
    }
    else{
        t1=head;
        printf("\n%d->",t1->data);
        while(t1->next!=NULL)
        {
            t1=t1->next;
            printf("%d->",t1->data);
        }
        printf("NULL");
    }
}
void delete_ele()
{
    if(head==NULL)
            {
            printf("list is empty");
            }
    else if(head->next==NULL)
            {
            t1=head;
            head=NULL;
            free(t1);
            }
    else {
    int ch;
    printf("Enter your choice: 1.Delete at the beginning 2.At End 3. At middle ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        {
             t1=head;
             head=head->next;
             t1->next=NULL;
             free(t1);
             break;
        }
    case 2://at end
        {
            t1=head;
            while(t1->next->next!=NULL)
                t1=t1->next;
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

void deletion_middle()
{
     int pos,flag=1;
            printf("Enter the position to be deleted");
            scanf("%d",&pos);
            t1=head;
            for(int i=1;i<pos-1;i++)
            {
               if(t1->next==NULL)
               {
                   printf("Deletion not possible");
                   flag=0;
               }
               else
                    t1=t1->next;
            }
            if(flag){
            t2=t1->next;//points to the node to be deleted
            t1->next=t2->next;
            t2->next=NULL;
            free(t2);
            }
}
