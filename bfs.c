#include <stdio.h>
#define n 6

int a[n][n], visited[n];
int q[20], r = -1, f = -1;

void bfs(int v)
{
    visited[v] = 1;
    printf("%d ", v);

    q[++r] = v;

    while (f != r)
    {
        int current = q[++f];

        for (int i = 0; i < n; i++)
        {
            if (a[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                printf("%d ", i);
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int v;
    printf("Enter matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting point: ");
    scanf("%d", &v);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        q[i] = 0;
    }

    printf("BFS traversal: ");
    bfs(v);

    return 0;
}
