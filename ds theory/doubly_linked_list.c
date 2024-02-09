#include<stdio.h>
#include"dll.c"
void main(){
    int no, pos, ch=1;
    m_node* newnode;
    while(ch){
        printf("\nEnter you choice: \n1. Create node \n2. Inserting at the beginning \n3. Inserting in the middle \n4. Inserting at the end \n5. Delete at the beginning \n6. Delete from middle \n7. Delete at end \n8. Display \n9. Reverse DLL\n0. Quit.");
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
                        head=insert_beginning(no,head);
                    }
                    break;
                }
            case 3:
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
                        printf("Eneter the position:\n");
                        scanf("%d",&pos);
                        if(pos<1 && pos>cnt){
                            printf("Invalid position.");
                        } else if(pos==1){
                            head=insert_beginning(no,head);
                        } else{
                            insert_middle(no,pos,head);
                        }
                    }
                    break;
                }
            case 4:
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
            case 5:
                {
                    if(head==NULL){
                        printf("list doesn\'t exist.\n");
                    }
                    else if(head->next==NULL){
                        free(head);
                        head=NULL;
                        printf("As there was only 1 element in the list, the list has been deleted.\n");
                    } else{
                        head=delete_beginning(head);
                    }
                    break;
                }
            case 6:
                {
                    if(head==NULL){
                        printf("list doesn\'t exist.\n");
                    }
                    else if(head->next==NULL){
                        free(head);
                        head=NULL;
                        printf("As there was only 1 element in the list, the list has been deleted.\n");
                    } else {
                        printf("Enter the position you want to delete from:\n");
                        scanf("%d",&pos);
                        delete_middle(pos, head);
                    }
                    break;
                }
            case 7:
                {
                    if(head==NULL){
                        printf("list doesn\'t exist.\n");
                    }
                    else if(head->next==NULL){
                        free(head);
                        head=NULL;
                        printf("As there was only 1 element in the list, the list has been deleted.\n");
                    } else{
                        last=delete_end(last);
                    }
                    break;
                }
            case 8:
                {
                    if(head==NULL){
                        printf("The list is empty.\n");
                    } else {
                        display(head);
                    }
                    break;
                }
            case 9:
                {
                    if(head==NULL){
                        printf("The list is empty.\n");
                    } else if(head->next==NULL){
                        printf("reversed.\n");
                    } else {
                        head=reverse_list(head);
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