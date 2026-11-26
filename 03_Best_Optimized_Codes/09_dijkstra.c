/*
 * PRACTICAL 9: DIJKSTRA'S SHORTEST PATH ALGORITHM
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Single-source shortest path algorithm for non-negative link weights.
 * - Used in Link-State routing protocols like OSPF.
 * - Greedy approach:
 *     1. Initialize source router distance to 0, all other routers to INF.
 *     2. Repeat N times:
 *        a. Pick unvisited node 'u' with minimum dist[u].
 *        b. Mark 'u' as visited.
 *        c. Relax neighbors: if dist[u] + cost[u][v] < dist[v], update dist[v].
 */

#include <stdio.h>

#define INF 999
#define MAX 10

int main() {
    int n;
    int cost[MAX][MAX];
    int dist[MAX];
    int visited[MAX] = {0};
    int src, u, min;
    int i, j, v;

    printf("========================================================\n");
    printf("   PRACTICAL 9: DIJKSTRA'S SHORTEST PATH ALGORITHM      \n");
    printf("========================================================\n");

    printf("Enter number of routers (nodes <= %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter cost matrix (%d for no direct link):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &cost[i][j]) != 1) return 1;
        }
    }

    printf("Enter source router (1 to %d): ", n);
    if (scanf("%d", &src) != 1 || src < 1 || src > n) return 1;
    src--; // Convert to 0-based array index

    // Step 1: Initialize distances from source
    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;

    // Step 2: Dijkstra Greedy Relaxation Loop
    for (i = 0; i < n; i++) {
        min = INF;
        u = -1;

        // Find unvisited vertex with minimum distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        // If no reachable unvisited node remains, terminate early
        if (u == -1) break;

        visited[u] = 1;

        // Relax neighbors of u
        for (v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Step 3: Print shortest path results
    printf("\n--- SHORTEST DISTANCES FROM ROUTER %d ---\n", src + 1);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("Router %d -> Router %d : Unreachable (No Path)\n", src + 1, i + 1);
        } else {
            printf("Router %d -> Router %d : Minimum Cost = %d\n", src + 1, i + 1, dist[i]);
        }
    }

    return 0;
}
