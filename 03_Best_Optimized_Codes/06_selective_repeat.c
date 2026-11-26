/*
 * PRACTICAL 6: SELECTIVE REPEAT ARQ
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Sliding window protocol with sender and receiver window size W.
 * - Receiver buffers valid out-of-order frames and sends individual ACKs.
 * - If frame K is lost:
 *     Only frame K is retransmitted when timeout expires.
 *     Other frames in the window that were received correctly are NOT retransmitted!
 */

#include <stdio.h>

int main() {
    int n, window, lost;
    int base, end, i;

    printf("========================================\n");
    printf("    PRACTICAL 6: SELECTIVE REPEAT ARQ   \n");
    printf("========================================\n");

    printf("Enter total number of frames: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter window size (W <= %d): ", n);
    if (scanf("%d", &window) != 1 || window <= 0) return 1;
    if (window > n) window = n;

    printf("Enter frame number to simulate loss (1 to %d, or 0 for none): ", n);
    if (scanf("%d", &lost) != 1 || lost < 0 || lost > n) return 1;

    printf("\n--- SIMULATION TRACE ---\n");

    for (base = 1; base <= n; base += window) {
        end = base + window - 1;
        if (end > n) end = n;

        printf("\n[Sender Window] Frames [%d .. %d]\n", base, end);

        // First pass: Transmit all frames in current window
        for (i = base; i <= end; i++) {
            if (i == lost) {
                printf("  *** Frame %d is LOST! ***\n", i);
            } else {
                printf("  Frame %d sent -> Receiver accepted, ACK %d received\n", i, i);
            }
        }

        // Selective Retransmission: Retransmit ONLY the lost frame
        if (lost >= base && lost <= end) {
            printf("  [Sender] Timeout for Frame %d\n", lost);
            printf("  [Selective Repeat] Retransmitting ONLY Frame %d\n", lost);
            printf("  Frame %d retransmitted -> Receiver accepted, ACK %d received\n", lost, lost);
            lost = 0; // Loss handled
        }
    }

    printf("\nAll %d frames transmitted and acknowledged successfully.\n", n);
    return 0;
}
