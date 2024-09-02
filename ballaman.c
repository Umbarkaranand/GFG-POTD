
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
struct edge{
    int u;
    int v;
    int w;
};

struct graph{
    int vert;
    int edge;
    struct edge *ed;
};
void display(int arr[],int size)
{
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

 void ballamanford(struct graph *g,int source)
{
    int i,j,u,v,w,vertex,edge;
    
    vertex=g->vert;
    edge=g->edge;
    int distance[vertex];
    
    for(i=0;i<vertex;i++)
    {
        distance[i]=INFINITY;
    }
    
    distance[source]=0;
    
    for(i=0;i<=(vertex-1);i++){
        for(j=0;j<edge;j++)
        {
            u=g->ed[j].u;
            v=g->ed[j].v;
            w=g->ed[j].w;
            
            if(distance[v]>distance[u]+w)
            {
                distance[v]=distance[u]+w;
            }
        }
	  
    }
    
     printf("Distance array: ");
           display(distance, vertex);
   
}


int main() {
    int i,source;
    
    struct graph *g=(struct graph *)malloc(sizeof(struct graph));
   
    g->edge=9;
    g->vert=5;

   g->ed=(struct edge *)malloc(g->edge * sizeof(struct edge));

    

    g->ed[0].u=0;
    g->ed[0].v=1;
    g->ed[0].w=4;

    g->ed[1].u=0;
    g->ed[1].v=2;
    g->ed[1].w=5;

    g->ed[2].u=1;
    g->ed[2].v=3;
    g->ed[2].w=5;

    g->ed[3].u=1;
    g->ed[3].v=4;
    g->ed[3].w=-3;

    g->ed[4].u=2;
    g->ed[4].v=4;
    g->ed[4].w=-3;

    g->ed[5].u=2;
    g->ed[5].v=3;
    g->ed[5].w=4;

    g->ed[6].u=3;
    g->ed[6].v=2;
    g->ed[6].w=-2;

    g->ed[7].u=4;
    g->ed[7].v=3;
    g->ed[7].w=6;

    g->ed[8].u=2;
    g->ed[8].v=1;
    g->ed[8].w=-2;

    printf("Enter Source Vertex : ");
    scanf("%d",&source);
    
    ballamanford(g,source);

    return 0;
}


