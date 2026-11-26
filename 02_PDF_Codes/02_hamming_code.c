/*
 * PRACTICAL 2: HAMMING CODE (7,4)
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 2, Page 10)
 * Network Layer / Domain: Data Link Layer
 * Core Algorithm / Concept: Single-Bit Error Correction
 */

#include <stdio.h>

int main() {
    int h[8] = {0}; // Index 1 to 7 used (index 0 unused)
    int p1, p2, p4, error;
    int d1, d2, d3, d4;

    // Step 1: Read 4 space-separated data bits
    printf("Enter 4 data bits: ");
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

    // Step 2: Place data bits at positions 3, 5, 6, 7
    h[3] = d1;
    h[5] = d2;
    h[6] = d3;
    h[7] = d4;

    // Step 3: Calculate even parity bits at positions 1, 2, 4
    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    printf("Hamming code: ");
    for (int i = 1; i <= 7; i++) {
        printf("%d", h[i]);
    }
    printf("\n");

    // Step 4: Read 7 received bits (space-separated)
    printf("Enter received 7 bits: ");
    for (int i = 1; i <= 7; i++) {
        scanf("%d", &h[i]);
    }

    // Step 5: Compute syndrome bits p1, p2, p4
    p1 = h[1] ^ h[3] ^ h[5] ^ h[7];
    p2 = h[2] ^ h[3] ^ h[6] ^ h[7];
    p4 = h[4] ^ h[5] ^ h[6] ^ h[7];

    // Convert binary syndrome (p4 p2 p1) into decimal position
    error = p4 * 4 + p2 * 2 + p1;

    if (error == 0) {
        printf("No error\n");
    } else {
        printf("Error at position %d\n", error);
        h[error] = h[error] ^ 1; // Flip the corrupted bit
        printf("Corrected code: ");
        for (int i = 1; i <= 7; i++) {
            printf("%d", h[i]);
        }
        printf("\n");
    }

    return 0;
}
