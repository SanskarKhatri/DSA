#include<stdio.h>
#define MAX_NODES 10
typedef struct graph
{
    int vertex;
    int adj_mat[MAX_NODES][MAX_NODES];
}GRAPH;
int f=-1,r=-1;
void create_graph(GRAPH *g)
{
    int from,to;
    printf("\nEnter the no. of vertex");
    scanf("%d",&g->vertex);
    for(int i=1;i<=g->vertex;i++)
    {
        for(int j=1;j<=g->vertex;j++)
            g->adj_mat[i][j]=0;
    }
    while(1)
    {
        printf("\nEnter the edge (v1 v2):");
        scanf("%d %d",&from,&to);
        if(from>0 && from<=g->vertex && to>0 && to<=g->vertex)
           g->adj_mat[from][to]=1; //Edge exists;
        else
            break;
    }
}
void display(GRAPH *g)
{
    for(int i=1;i<=g->vertex;i++)
    {
        printf("\n");
        for(int j=1;j<=g->vertex;j++)
            printf("%d ",g->adj_mat[i][j]);
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
 int bfs_conn(GRAPH *g)
 {
     int source,*queue,*visited,v,i;
     printf("\nEnter the source vertex");
     scanf("%d",&source);
     v=g->vertex;
     queue=(int*)calloc(v,sizeof(int));
     visited=(int*)calloc(v+1,sizeof(int));
     enqueue(queue,source);
     visited[source]=1;
     printf("\n%d ",source);
     while(!isempty(queue))
     {
         i=dequeue(queue);
         for(int j=1;j<=v;j++)
         {
            if(g->adj_mat[i][j]==1 && visited[j]==0)
            {
                enqueue(queue,j);
                visited[j]=1;
                printf("%d ",j);
            }
         }
     }
    for(int i=1;i<g->vertex;i++)
    {
        if(!visited[i])
            return 0;
    }
    return 1;
 }
int main()
{
    GRAPH g1;
    int ch,v;
    create_graph(&g1);
    while(1)
    {
        printf("\nEnter your choice");
        printf("\n1.Display");
        printf("\n2.BFS");
        printf("\n4.Quit");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1://Display
            display(&g1);
            break;
        case 2:
            if(bfs_conn(&g1))
                printf("\nConnected");
            else
                printf("\nNot Connected");
            break;
        case 3://Quit
            return;
        }
    }
}
