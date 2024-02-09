#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10
struct node
{
    int data;
    struct node *next;
};

void create_adjList(struct node *l)
{
    int v,from,to;
    printf("\nEnter the no of vertex: ");
    scanf("%d",&v);
    l[0].data=v;
    l[0].next=NULL;
    for(int i=1;i<=v;i++)
    {
        l[i].data=0;
        l[i].next=NULL;
    }
   while(1)
    {
    printf("\nEnter the edge(v1 v2):");
    scanf("%d %d",&from,&to);
    if(from<=0 || from>v || to<=0 || to>v)
        return;
    struct node *t,*nn;
    t=&l[from];
    nn=(struct node*)malloc(sizeof(struct node));
    while(t->next!=NULL)
        t=t->next;
    t->next=nn;
    nn->data=to;
    nn->next=NULL;
    }
}
void display(struct node *l)
{
    struct node *t;
    for(int i=1;i<=l[0].data;i++)
    {
        t=&l[i];
        printf("\n%d=>",t->data);
        while(t->next!=NULL)
        {
            t=t->next;
            printf("%d ",t->data);
        }
    }
}

void init_visited(struct node *l)
{
    for(int i=1;i<=l[0].data;i++)
    {
        l[i].data=0;
    }
}
void print_dfs_path(struct node *l,int start,int dest,int *visited,int *path)
{
    static int count;
    struct node *t=&l[start];
    //printf("%d ",v);
    path[count++]=start;
    visited[start]=1;
    if(start==dest)
        {
            printf("\n");
            for(int i=0;i<count;i++)
                printf("%d ",path[i]);
        }
    else{
    while(t->next!=NULL)
    {
        t=t->next;
         if(visited[t->data]==0)
            print_dfs_path(l,t->data,dest,visited,path);
    }
    }
    visited[start]=0;
    count--;
}
int main()
{
    int ch,v,start,dest;
    struct node l[MAX_NODES];
    int *path,*visited;
    create_adjList(l);
    display(l);
    path=(int *)calloc(l[0].data,sizeof(int));
    visited=(int *)calloc(l[0].data,sizeof(int));
    printf("\nEnter the source and destination vertex:");
    scanf("%d %d",&start,&dest);
    print_dfs_path(l,start,dest,visited,path);
    return 0;
}
