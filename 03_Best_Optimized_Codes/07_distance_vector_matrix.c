/*
 * PRACTICAL 7: DISTANCE VECTOR ROUTING - DISTANCE MATRIX
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Computes all-pairs shortest path matrix using dynamic programming (Floyd-Warshall).
 * - Adjacency cost matrix represents network topology.
 * - Value 999 represents Infinity (no direct cable / link between routers).
 * - Distances to self (dist[i][i]) are always 0.
 * - Distance relaxation:
 *     if dist[i][k] + dist[k][j] < dist[i][j]:
 *         dist[i][j] = dist[i][k] + dist[k][j]
 */

#include <stdio.h>

#define INF 999
#define MAX 10

int main() {
    int n;
    int dist[MAX][MAX];
    int i, j, k;

    printf("========================================================\n");
    printf(" PRACTICAL 7: DISTANCE VECTOR ROUTING (DISTANCE MATRIX) \n");
    printf("========================================================\n");

    printf("Enter number of routers (nodes <= %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) return 1;

    printf("Enter cost matrix (%d for no direct link):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (scanf("%d", &dist[i][j]) != 1) return 1;
        }
    }

    // Distance Vector / Floyd-Warshall Relaxation
    // k = intermediate router, i = source router, j = destination router
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\n--- FINAL SHORTEST DISTANCE MATRIX ---\n");
    printf("       ");
    for (j = 0; j < n; j++) {
        printf("R%-3d ", j + 1);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("R%-3d: ", i + 1);
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf(" INF ");
            else
                printf("%4d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
