#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct node{
    int data;
    struct node* next;
}NODE;

typedef struct hash{
    int count;
    struct node *head;
}HashTable;

void insert(int key, HashTable* hashTable)
{
    int hash;
    hash=key%SIZE;
    NODE nn=(NODE)malloc(sizeof(NODE));
    nn->data=key;
    nn->next=NULL;
    if(hashTable[hash].count==0)//inserting @ the 1st node
    {
        hashTable[hash].head=nn;
        hashTable[hash].count++;
    }
    else//traverse to the end of the list and then insert
    {
        NODE *t=hashTable[hash].head;
        while(t->next!=NULL)
            t=t->next;
        t->next=nn;
        hashTable[hash].count++;
    }
}

void display(HashTable* hashTable)
{
    for(int i=0;i<SIZE;i++)
    {
        printf("[%d]C=%d=>",i,hashTable[i].count);
        NODE *t=hashTable[i].head;
        while(t!=NULL)
        {
            printf("%d->",t->data);
            t=t->next;
        }
        printf("\n");
    }
}

void search(int key,HashTable* hashTable)
{
    int hash,pos=0;
    NODE *t;
    hash=key%SIZE;
    t=hashTable[hash].head;
    while(t!=NULL)
    {
        pos++;
        if(t->data==key)
        {
            printf("\nData found at index %d in position %d",hash,pos);
            return;
        }
        t=t->next;
    }
    printf("\nData not found");
}

void delete(int key,HashTable* hashTable)
{
    int hash,pos=0;
    NODE *t,*prev;
    hash=key%SIZE;
    t=hashTable[hash].head;
    while(t!=NULL)
    {
        pos++;
        if(t->data==key)
        {
            if(pos==1)//or hashTable[hash].head->data==ket
                hashTable[hash].head=t->next;
            else
            {
                prev=hashTable[hash].head;
                while(prev->next!=t)//or move till pos-1
                    prev=prev->next;
                prev->next=t->next;
            }
            free(t);
            hashTable[hash].count--;
            return;
        }
        t=t->next;
    }
}

void main()
{
    int key;
    HashTable hashTable[SIZE]={};
    printf("\nEnter the key to be inserted: ");
    scanf("%d",&key);
    insert(key,hashTable);
    display(hashTable);
    search(key,hashTable);
    delete(key,hashTable);
}