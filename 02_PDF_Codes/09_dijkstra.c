/*
 * PRACTICAL 9: DIJKSTRA'S SHORTEST PATH ALGORITHM
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 9, Page 46-47)
 * Network Layer / Domain: Network Layer
 * Core Algorithm / Concept: Single-Source Greedy Shortest Path
 */

#include <stdio.h>

int main() {
    int n, cost[10][10], dist[10];
    int visited[10] = {0};
    int src, u, min;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 for no link):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source router (1 to %d): ", n);
    scanf("%d", &src);
    src--; // Convert 1-based user input to 0-based array index

    // Step 1: Initialize distances from source
    for (int i = 0; i < n; i++) {
        dist[i] = cost[src][i];
    }
    dist[src] = 0;

    // Step 2: Find shortest path for all n routers
    for (int i = 0; i < n; i++) {
        min = 999;
        u = -1;

        // Pick the unvisited router u with minimum distance
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break; // Remaining routers are unreachable
        visited[u] = 1;

        // Relax all unvisited neighbors v of u
        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != 999 &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances from Router %d\n", src + 1);
    for (int i = 0; i < n; i++) {
        if (dist[i] == 999)
            printf("Router %d: Unreachable\n", i + 1);
        else
            printf("Router %d: %d\n", i + 1, dist[i]);
    }

    return 0;
}
