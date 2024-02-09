#include <stdio.h>
#define MAX_NODES 50

typedef struct graph
{
    int no_vertex;
    int visited[MAX_NODES];
    int adj[MAX_NODES][MAX_NODES];
}GRAPH;

void create_graph(GRAPH *g)
{
    int from,to;
    while(1)
        {
        printf("\nEnter the Edge(From_vertex To_vertex)");
        scanf("%d %d",&from,&to);
        if(from>0 && from<=g->no_vertex && to>0 && to<=g->no_vertex)
            g->adj[from][to]=1;
        else
            break;
        }
}
void indegree(GRAPH *g,int v)
{
int count=0;
for(int i=1;i<=g->no_vertex;i++)
    if(g->adj[i][v]==1)
        count++;
printf("\nIndegree of vertex %d = %d",v,count);
}
void outdegree(GRAPH *g,int v)
{
int count=0;
for(int i=1;i<=g->no_vertex;i++)
    if(g->adj[v][i]==1)
        count++;
printf("\nOutdegree of vertex %d = %d",v,count);
}
void display(GRAPH *g)
{
for(int i=1;i<=g->no_vertex;i++)
    {
       for(int j=1;j<=g->no_vertex;j++){
            printf("%d ",g->adj[i][j]);}
       printf("\n");
    }
}
void init_visited(GRAPH *g)
{
    for(int i=1;i<=g->no_vertex;i++)
        g->visited[i]=0;
}
void dfs(GRAPH *g,int v)
{
    printf("%d",v);
    g->visited[v]=1;
   for(int i=1;i<=g->no_vertex;i++)
    {
        if(g->adj[v][i]==1 && g->visited[i]==0)
        {
           dfs(g,i);
        }
    }
}
int main()
{
    int v,ch;
    GRAPH g1={};
    printf("\nEnter the no of vertex");
    scanf("%d",&g1.no_vertex);
    create_graph(&g1);

    do{
    printf("\n Enter your choice: \n\t1. indegreeb \n\t2.Outdegree\n\t3.Display\n\t4.Exit\n\t5.DFS");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\nEnter the vertex:");
        scanf("%d",&v);
        indegree(&g1,v);
        break;
    case 2:
        printf("\nEnter the vertex:");
        scanf("%d",&v);
        outdegree(&g1,v);
        break;
    case 3:
        display(&g1);
        break;
    case 4:
        return 0;
    case 5:
        printf("\nEnter the starting vertex");
        scanf("%d",&v);
        init_visited(&g1);
        dfs(&g1,v);
        break;
    }
    }while(1);
    return 0;
}
