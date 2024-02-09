#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;

int isCyclic(int cur, unsigned int order, unsigned int adjMat[order][order], unsigned int vis[], int par){
    vis[cur]=1;

    // for(int l=0;l<order;l++){
    //     printf("%d ",vis[l]);
    // } printf("\n");

    for(int i=0;i<order;i++){
        if(adjMat[cur][i]){
            if(!vis[i]){
                if(isCyclic(i,order,adjMat,vis,cur))
                    return 1;
            } else if(vis[i] && i!=par){
                return 1;
            }
        }
    }
    return 0;
}

unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order)
{
    int ans;
    unsigned int adjMat[order][order];
    unsigned int vis[order];
    for(int i=0;i<order;i++){
        vis[i]=0;
    }
    for(int i=0;i<order;i++){
        for(int j=0;j<order;j++){
            adjMat[i][j]=0;
        }
    }
    for(int i=0;i<order;i++){
        for(int j=0;j<n;j++){
            if(edges[j].first==i){
                adjMat[i][edges[j].second]=1;
            } else if(edges[j].second==i){
                adjMat[i][edges[j].first]=1;
            }
        }
    }

    // for(int i=0;i<order;i++){
    //     for(int j=0;j<order;j++){
    //         printf("%d ",adjMat[i][j]);
    //     } printf("\n");
    // }

    ans=isCyclic(0,order,adjMat,vis,0);
    return ans;
}
/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
        
    ans= cycle_finder(edges, n, order);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}
