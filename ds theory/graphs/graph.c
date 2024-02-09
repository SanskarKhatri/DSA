#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 20
typedef struct graph{
    int vertex;
    int matrix[MAX_NODES][MAX_NODES];
} GRAPH;
void create_graph(GRAPH *g){
    int v,from,to;
    printf("\nEnter the number of vertex:");
    scanf("%d",&g->vertex);
    for(int i=1;i<=g->vertex;i++){
        for(int j=1;j<=g->vertex;j++){
            g->matrix[i][j]=0;
        }
    }
    while(1){
        printf("\nEnter the edge (v1 v2):");
        scanf("%d %d",&from,&to);
        if(from>0 && from<=g->vertex && to>0 && to<=g->vertex && from!=to){
            g->matrix[from][to]=1; //for directed graph
            //g->matrix[to][from]=1; //for undirected graph
        } else {
            return;
        }
    }
}
void display(GRAPH *g){
    for(int i=1;i<=g->vertex;i++){
        printf("\n");
        for(int j=1;j<=g->vertex;j++){
            printf("%d ",g->matrix[i][j]);
        }
    }
}
void indegree(GRAPH *g,int v){
    int count=0;
    for(int i=0;i<=g->vertex;i++){
        if(g->matrix[i][v]==1){
            count++;
        }
    }
    printf("\nThe indegree of the vertex %d is %d.",v,count);
}
void outdegree(GRAPH *g,int v){
    int count=0;
    for(int i=0;i<=g->vertex;i++){
        if(g->matrix[v][i]==1){
            count++;
        }
    }
    printf("\nThe outdegree of the vertex %d is %d.",v,count);
}
int main(){
    int ch,v;
    GRAPH g1;
    create_graph(&g1);
    while(1){
        printf("\nEnter the choice:");
        printf("\n1.Display");
        printf("\n2.Indegree of the node");
        printf("\n3.Outdegree of the node");
        printf("\n4.DFS\n");
        printf("\n4.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                display(&g1);
                break;
            case 2:
                printf("\nEnter the vertex:");
                scanf("%d",&v);
                indegree(&g1,v);
                break;
            case 3:
                printf("\nEnter the vertex:");
                scanf("%d",&v);
                outdegree(&g1,v);
                break;
            case 4:
                printf("\nEnter the source:");
                scanf("%d",&v);
                dfs(g1,v);
            case 5:
                exit(0);
                break;
        }
    }
}