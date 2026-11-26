/*
 * PRACTICAL 8: DISTANCE VECTOR ROUTING - NEXT HOP TABLE
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Computes routing table for every router with Destination, Cost, and Next-Hop router.
 * - Uses Bellman-Ford style distributed relaxation until convergence.
 * - cost[i][j]: direct link cost (constant).
 * - dist[i][j]: current shortest known distance from router i to j.
 * - nextHop[i][j]: the neighbor router through which router i routes traffic to j.
 */

#include <stdio.h>

#define INF 999
#define MAX 10

int main() {
    int n;
    int cost[MAX][MAX];
    int dist[MAX][MAX];
    int nextHop[MAX][MAX];
    int changed;
    int i, j, k;

    printf("========================================================\n");
    printf("  PRACTICAL 8: DISTANCE VECTOR ROUTING (NEXT HOP TABLE) \n");
    printf("========================================================\n");

    printf("Enter number of routers (nodes <= %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter cost matrix (%d for no direct link):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &cost[i][j]) != 1) return 1;
            dist[i][j] = cost[i][j];

            // If directly connected neighbor, nextHop is j; if no link, nextHop is -1
            if (i == j)
                nextHop[i][j] = i;
            else if (cost[i][j] == INF)
                nextHop[i][j] = -1;
            else
                nextHop[i][j] = j;
        }
    }

    // Bellman-Ford Iterative Table Exchange until stable
    do {
        changed = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (cost[i][k] != INF && dist[k][j] != INF &&
                        cost[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        nextHop[i][j] = k;
                        changed = 1;
                    }
                }
            }
        }
    } while (changed);

    printf("\n================ FINAL ROUTING TABLES ================\n");
    for (i = 0; i < n; i++) {
        printf("\nRouting Table for Router %d:\n", i + 1);
        printf("-------------------------------------\n");
        printf(" Destination    Cost        Next Hop \n");
        printf("-------------------------------------\n");
        for (j = 0; j < n; j++) {
            printf("   Router %-2d   ", j + 1);
            if (dist[i][j] == INF) {
                printf("  INF        -      \n");
            } else {
                printf("  %4d      Router %-2d\n", dist[i][j], nextHop[i][j] + 1);
            }
        }
    }

    return 0;
}
