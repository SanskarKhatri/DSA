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
        l[i].data=i;
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
void indegree(struct node *l,int v)
{
    int count=0;
    struct node *t;
    for(int i=1;i<=l[0].data;i++)
    {
        t=&l[i];
        while(t->next!=NULL)
        {
            t=t->next;
            if(t->data==v)
                count++;
        }
    }
    printf("\nIndegree of %d is %d",v,count);
}
void outdegree(struct node *l,int v)
{
    struct node *t=&l[v];
    int count=0;
    while(t->next!=NULL)
    {
        count++;
        t=t->next;
    }
    printf("\nOutdegree of %d is %d",v,count);
}
int main()
{
    int ch,v;
    struct node l1[MAX_NODES];
    create_adjList(l1);
    display(l1);
    do{
        printf("\nEnter \n1.To find Indegree \n2.To find Outdegree \n3. To quit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the vertex");
            scanf("%d",&v);
            indegree(l1,v);
            break;
        case 2:
            printf("Enter the vertex");
            scanf("%d",&v);
            outdegree(l1,v);
            break;
        case 3:
            printf("Enter the starting vertex");
            scanf("%d",&v);
            init_visited()
            bfs(l1,v,visited);
            break;
        case 4:
            return;
        }
    }while(1);
    return 0;
}
