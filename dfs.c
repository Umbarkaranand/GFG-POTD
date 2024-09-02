#include<stdio.h>
#define n 6

int graph[n][n],visited[n];

void dfs(int i)
{
	int j;
	printf("%d ",i);
	visited[i]=1;
	
	
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]==1 && !visited[j])
			{
				dfs(j);
			}
		}
	
}

int main()
{
	printf("Enter Matrix : ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	
	for(int i=0;i<n;i++)
		visited[i]=0;
	int source;
	printf("Enter starting vertex : ");
	scanf("%d",&source);
	
	printf("\n DFS Traversal is : \n");
	dfs(source);
	
	return 0;
}