/*
 * PRACTICAL 9: DIJKSTRA'S SHORTEST PATH ALGORITHM
 * Source: Extracted exactly from existing 'dijkstra.cpp'.
 * Original file: dijkstra.cpp
 */

#include <stdio.h>

int main()
{
    int n, cost[10][10], dist[10];
    int visited[10] = {0};
    int src, u, min;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source router: ");
    scanf("%d", &src);

    src--;

    for(int i = 0; i < n; i++)
        dist[i] = cost[src][i];

    dist[src] = 0;

    for(int i = 0; i < n; i++)
    {
        min = 999;
        u = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && cost[u][v] != 999 &&
               dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances:\n");

    for(int i = 0; i < n; i++)
    {
        printf("Router %d : %d\n", i + 1, dist[i]);
    }

    return 0;
}
