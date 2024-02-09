//Adjacency List
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10

struct node
{
    int data;//vertex
    struct node *next;
};
int f=-1,r=-1;
void create_graph(struct node *l)
{
    int v,from,to;
    printf("\nEnter the no. of vertices:");
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
        if(from<1 || from>v ||to<1 || to>v)
            return;
        struct node *t,*nn;
        nn=(struct node*)malloc(sizeof(struct node));
        t=&l[from];
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
       printf("\n%d=>",t->data);//optional
       while(t->next!=NULL)
       {
           t=t->next;
           printf("%d ",t->data);
       }
    }
}
int isempty(int *q)
{
    return (f==r && f==-1);
}
void enqueue(int *q,int data)
{
    if(isempty(q))
        f++;
    q[++r]=data;
}

int dequeue(int *q)
{
    int d=q[f];
    if(f==r && f!=-1)//one element condition
    {
        f=r=-1;
    }
    else
        f++;
    return d;
}
 int bfs_path(struct node *l)//change
 {
     int source,dest,*queue,*visited,v,i,flag=0;
     struct node *t;//change
     printf("\nEnter the source and destination vertex");
     scanf("%d %d",&source,&dest);
     v=l[0].data;//change
     queue=(int*)calloc(v,sizeof(int));
     visited=(int*)calloc(v+1,sizeof(int));
     enqueue(queue,source);
     visited[source]=1;
     printf("\n%d ",source);
     while(!isempty(queue))
     {
         i=dequeue(queue);
         t=&l[i];//change //Assign to a temp pointer
         //for(int j=1;j<=v;j++)
         while(t->next!=NULL)//change
         {
            t=t->next;
            if(visited[t->data]==0)
            {
                enqueue(queue,t->data);
                visited[t->data]=1;
                printf("%d ",t->data);
                if(t->data==dest)
                {
                    flag=1;
                    return flag;
                }
            }
         }
     }
     return flag;
 }
void init_visited(int *visited, int v)
{
    for(int i=0;i<=v;i++)
        visited[i]=0;
}

int main()
{
    int ch,v,start,visited[MAX_NODES];
    struct node l1[MAX_NODES];
    create_graph(l1);
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1.Display");
        printf("\n2.BFS");
        printf("\n3.Quit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1://Display
            display(l1);
            break;
        case 2://BFS
            if(bfs_path(l1))
                printf("Path found");
            else
                printf("Path not found");
            break;
        case 3://Quit
            return;
        }
    }
}
