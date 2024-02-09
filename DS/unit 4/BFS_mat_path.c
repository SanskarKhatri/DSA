#include <stdio.h>
#include<stdlib.h>
#define MAX_NODES 50

typedef struct graph
{
    int no_vertex;
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
void display(GRAPH *g)
{
for(int i=1;i<=g->no_vertex;i++)
    {
       for(int j=1;j<=g->no_vertex;j++){
            printf("%d ",g->adj[i][j]);}
       printf("\n");
    }
}
int isvisited(int *visited,int v,int *unvisited)
{
    for(int i=1;i<=v;i++)
    {
      if(visited[i]==0)
      {
          *unvisited=i;
          return 0;
      }
    }
    return 1;
}
void enqueue(int *queue,int ele,int *f,int *r)
{
    if(*f==*r && *f==-1)//empty
        (*f)++;
    queue[++(*r)]=ele;
}
int dequeue(int *queue,int *f,int *r)
{
    if(*f==*r)//one element
    {
        *f=*r=-1;
    }
    return queue[(*f)++];
}
void bfs(GRAPH *g)
{
    int v,start,dest,*visited,*queue,flag=1,f=-1,r=-1,i,j;
    int unvisited;
    v=g->no_vertex;
    //Get starting vertex
    printf("\nEnter the source vertex and destination vertex:");
    scanf("%d %d",&start,&dest);
    //create a visited array and queue and initialize
    visited=(int *)calloc(v+1,sizeof(int));
    queue=(int *)calloc(v+1,sizeof(int));

    //Traverse
    do{
    visited[start]=1;
    printf("%d ",start);
    enqueue(queue,start,&f,&r);
    while(f!=r && r!=-1)//if not empty
    {
    i=dequeue(queue,&f,&r);
    for(j=1;j<=v;j++){
        if(g->adj[i][j]==1 && visited[j]==0)
            {
            visited[j]=1;
            printf("%d ",j);
            enqueue(queue,j,&f,&r);
            if(j==dest)
            {
             printf("There exists a path between %d and %d",start,dest);
             return;
            }
            }
        }
    }
    if(isvisited(visited,v,&unvisited))
        flag=0;//if all the nodes are visited
    else
        start=unvisited;
    }while(flag);

}
int main()
{
    int v,ch;
    GRAPH g1={};
    printf("\nEnter the no of vertex");
    scanf("%d",&g1.no_vertex);
    create_graph(&g1);

    do{
    printf("\n Enter your choice: 3.Display\n\t4.BFS\n\t5.Exit");
    scanf("%d",&ch);
    switch(ch)
    {
    case 3:
        display(&g1);
        break;
    case 4:
        bfs(&g1);
        break;
    case 5:
        return 0;
    }
    }while(1);
    return 0;
}
