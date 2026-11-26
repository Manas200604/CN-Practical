/*
 * PRACTICAL 8: DISTANCE VECTOR ROUTING - NEXT HOP
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 8, Page 41)
 * Network Layer / Domain: Network Layer
 * Core Algorithm / Concept: Bellman-Ford Table Relaxation
 */

#include <stdio.h>

int main() {
    int n, cost[10][10], dist[10][10], nextHop[10][10];
    int changed;

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 for no link):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
            // If no direct link (999), nextHop is -1; else direct neighbor j
            nextHop[i][j] = (cost[i][j] == 999) ? -1 : j;
        }
    }

    // Repeat Bellman-Ford relaxation until no routing table changes
    do {
        changed = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (cost[i][k] != 999 && dist[k][j] != 999 &&
                        cost[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        nextHop[i][j] = k;
                        changed = 1;
                    }
                }
            }
        }
    } while (changed);

    printf("\nRouting tables:\n");
    for (int i = 0; i < n; i++) {
        printf("\nRouter %d\n", i + 1);
        printf("Destination  Cost  Next hop\n");
        for (int j = 0; j < n; j++) {
            printf("%5d        %4d    ", j + 1, dist[i][j]);
            if (nextHop[i][j] == -1)
                printf("-\n");
            else
                printf("%d\n", nextHop[i][j] + 1);
        }
    }

    return 0;
}
