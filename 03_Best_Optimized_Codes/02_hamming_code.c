/*
 * PRACTICAL 2: HAMMING CODE (7,4)
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - 4 Data bits (d1, d2, d3, d4) are encoded into 7-bit codeword.
 * - Bit positions (1-indexed):
 *     Bit 1: P1 (Parity bit 1) -> checks positions 1, 3, 5, 7
 *     Bit 2: P2 (Parity bit 2) -> checks positions 2, 3, 6, 7
 *     Bit 3: D1 (Data bit 1)
 *     Bit 4: P4 (Parity bit 4) -> checks positions 4, 5, 6, 7
 *     Bit 5: D2 (Data bit 2)
 *     Bit 6: D3 (Data bit 3)
 *     Bit 7: D4 (Data bit 4)
 * - Syndrome calculation at receiver gives exact 1-based error position:
 *     error = (p4 * 4) + (p2 * 2) + (p1 * 1)
 * - If error == 0: No error.
 * - If error > 0: Bit at position 'error' is flipped back to correct it!
 */

#include <stdio.h>

int main() {
    int h[8] = {0}; // 1-based indexing: h[1] to h[7] used, h[0] ignored
    int d1, d2, d3, d4;
    int p1, p2, p4, error;
    int i;

    printf("========================================\n");
    printf("    PRACTICAL 2: HAMMING CODE (7,4)     \n");
    printf("========================================\n");

    // Step 1: Input 4 data bits
    printf("Enter 4 data bits separated by space (d1 d2 d3 d4): ");
    if (scanf("%d %d %d %d", &d1, &d2, &d3, &d4) != 4) {
        printf("Invalid input! Please enter 4 integers.\n");
        return 1;
    }

    // Step 2: Assign data bits to positions 3, 5, 6, 7
    h[3] = d1;
    h[5] = d2;
    h[6] = d3;
    h[7] = d4;

    // Step 3: Compute Even Parity bits at positions 1, 2, 4
    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    printf("\n--- SENDER SIDE ---\n");
    printf("Generated Hamming Code (bits 1 to 7): ");
    for (i = 1; i <= 7; i++) {
        printf("%d", h[i]);
    }
    printf("\n");
    printf("Bit positions : [1:P1=%d, 2:P2=%d, 3:D1=%d, 4:P4=%d, 5:D2=%d, 6:D3=%d, 7:D4=%d]\n",
           h[1], h[2], h[3], h[4], h[5], h[6], h[7]);

    // Step 4: Input received 7 bits
    printf("\n--- RECEIVER SIDE ---\n");
    printf("Enter received 7 bits separated by space: ");
    for (i = 1; i <= 7; i++) {
        if (scanf("%d", &h[i]) != 1) return 1;
    }

    // Step 5: Calculate Syndrome Bits
    p1 = h[1] ^ h[3] ^ h[5] ^ h[7];
    p2 = h[2] ^ h[3] ^ h[6] ^ h[7];
    p4 = h[4] ^ h[5] ^ h[6] ^ h[7];

    error = (p4 * 4) + (p2 * 2) + (p1 * 1);

    printf("Syndrome (P4 P2 P1): %d %d %d -> Error Position: %d\n", p4, p2, p1, error);

    if (error == 0) {
        printf("Result: NO ERROR DETECTED in received code.\n");
    } else {
        printf("Result: SINGLE-BIT ERROR DETECTED at position %d!\n", error);
        h[error] = h[error] ^ 1; // Correct the bit
        printf("Automatically Corrected Code: ");
        for (i = 1; i <= 7; i++) {
            printf("%d", h[i]);
        }
        printf("\n");
        printf("Recovered Data Bits (D1 D2 D3 D4): %d %d %d %d\n", h[3], h[5], h[6], h[7]);
    }

    return 0;
}
