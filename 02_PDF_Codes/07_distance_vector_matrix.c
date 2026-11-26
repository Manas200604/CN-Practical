/*
 * PRACTICAL 7: DISTANCE VECTOR ROUTING - DISTANCE MATRIX
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 7, Page 36)
 * Network Layer / Domain: Network Layer
 * Core Algorithm / Concept: All-Pairs Shortest Path (Floyd-Warshall)
 */

#include <stdio.h>

int main() {
    int n, dist[10][10];

    printf("Enter number of routers: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 for no link):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    // k = intermediate router, i = source router, j = destination router
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != 999 && dist[k][j] != 999 &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
