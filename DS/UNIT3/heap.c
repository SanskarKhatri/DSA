#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 20
typedef struct heap
{
    int heap[SIZE];
    int heapsize;
}HEAP;
void init(HEAP *h)
{
    h->heapsize=0;
    h->heap[0]=INT_MAX;
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
void insert(HEAP *h,int data)//top down
{
    int c,p;
    h->heap[++(h->heapsize)]=data;
    c=h->heapsize;
    p=c/2;
    while(h->heap[p]<h->heap[c])
    {
        swap(&(h->heap[p]),&(h->heap[c]));
        c=p;
        p=p/2;
    }
}
void insert_BottomUp(HEAP *h)
{
    int c,p;
    for(p=(h->heapsize)/2;p>=1;p--)
    {
       c=2*p;
       while(c<=h->heapsize)
        {
        if(c+1<=h->heapsize && h->heap[c+1]>h->heap[c])
            c++;
        if(h->heap[p]<h->heap[c])
            swap(&(h->heap[p]),&(h->heap[c]));
        else
            break;
       p=c;
       c=2*p;
        }
    }
}
int deleteElement(HEAP *h)
{
    int d,c,p;
    d=h->heap[1];
    h->heap[1]=h->heap[h->heapsize--];
    p=1;
    c=2*p;
    while(c<=h->heapsize)
    {
        if(c+1<=h->heapsize && h->heap[c+1]>h->heap[c])
            c++;
        if(h->heap[p]<h->heap[c])
            swap(&(h->heap[p]),&(h->heap[c]));
        else
            break;
       p=c;
       c=2*p;
        }
    return d;
}
void display(HEAP* h)
{
    printf("\n");
    for(int i=1;i<=h->heapsize;i++)
        printf("%d ",h->heap[i]);
}
int main()
{
    int d,ch;
    HEAP *h=(HEAP*)malloc(sizeof(HEAP));
    HEAP *h1=(HEAP*)malloc(sizeof(HEAP));
    init(h);
    init(h1);
    do{
    printf("Enter the data:");
    scanf("%d",&d);
    insert(h,d);
    h1->heap[++h1->heapsize]=d;
    printf("Enter 0 to stop:");
    scanf("%d",&ch);
    }while(ch);
    printf("\nTop down: ");
    display(h);
    printf("\nBottom up: ");
    insert_BottomUp(h1);
    display(h1);
    printf("Element deleted %d :",deleteElement(h));
    display(h);
}
