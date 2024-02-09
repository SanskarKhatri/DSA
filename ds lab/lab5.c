#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
struct node {
    char *value;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(char * s) 
{
      int n=0;
      char *temp=s;
      while(*temp!='\0'){
        n++;
        temp++;
      }
      return n;
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    char *temp1=str1, *temp2=str2;
    while(*temp1!='\0'){
        *temp2=*temp1;
        temp1++;
        temp2++;
    }
    temp2="\0";
}

int my_strcmp(const char *a, const char *b)
{
    char *temp1=a, *temp2=b;
    while (temp1!='\0' && temp2!='\0')
    {
        if(*temp1==*temp2){
            temp1++;
            temp2++;
        }
        else if(*temp1<*temp2){
            return -1;
        }
        else {
            return 1;
        }
    }    
    return 0;
}
//inserts elements into the tree
void insert(char* key, struct node** leaf)
{
    if(*leaf==NULL){
        *leaf=(struct node*)malloc(sizeof(struct node));
        (*leaf)->value=key;
        (*leaf)->p_left=NULL;
        (*leaf)->p_right=NULL;
    } else {
        if(my_strcmp(key,(*leaf)->value)>0)
            insert(key,&(*leaf)->p_right);
        else if(my_strcmp(key,(*leaf)->value)<0)
            insert(key,&(*leaf)->p_left);
        else
            check=-1;
    }
}




//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if(root->p_left==NULL && root->p_right==NULL){
        printf("%s\n",root->value);
    } else {
        if(root->p_left!=NULL){
            asc_order(root->p_left);
        }
        printf("%s\n",root->value);
        if(root->p_right!=NULL){
            asc_order(root->p_right);
        }
    }
}



//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    struct node* temp=leaf;
    while(temp!=NULL){
        if(my_strcmp(key,temp->value)==0){
            found=1;
        } else if(my_strcmp(key,temp->value)<0){
            temp=temp->p_left;
        } else {
            temp=temp->p_right;
        }
    }
}




int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }   
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}