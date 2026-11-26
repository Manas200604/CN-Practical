/*
 * PRACTICAL 5: GO-BACK-N ARQ
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Sliding window protocol with sender window size W and receiver buffer 1.
 * - Multiple frames are transmitted concurrently within the window.
 * - If frame K is lost:
 *     Frames prior to K are acknowledged normally.
 *     Frame K fails, triggering timeout.
 *     Receiver discards all frames after K (receiver window = 1).
 *     Sender GOES BACK to frame K and retransmits K AND all subsequent frames in window.
 */

#include <stdio.h>

int main() {
    int n, window, lost;
    int base, end, i;

    printf("========================================\n");
    printf("        PRACTICAL 5: GO-BACK-N ARQ      \n");
    printf("========================================\n");

    printf("Enter total number of frames: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Enter window size (W <= %d): ", n);
    if (scanf("%d", &window) != 1 || window <= 0) return 1;
    if (window > n) window = n;

    printf("Enter frame number to simulate loss (1 to %d, or 0 for none): ", n);
    if (scanf("%d", &lost) != 1 || lost < 0 || lost > n) return 1;

    base = 1;
    printf("\n--- SIMULATION TRACE ---\n");

    while (base <= n) {
        end = base + window - 1;
        if (end > n) end = n;

        printf("\n[Sender Window] Frames [%d .. %d]\n", base, end);

        // Check if lost frame falls within this window
        if (lost >= base && lost <= end) {
            // Frames before lost frame succeed
            for (i = base; i < lost; i++) {
                printf("  Frame %d sent -> Receiver ACK %d received\n", i, i);
            }

            printf("  *** Frame %d is LOST! ***\n", lost);
            printf("  [Sender] Timeout occurred for Frame %d\n", lost);
            printf("  [Go-Back-N] Retransmitting entire window from frame %d to %d\n", lost, end);

            // Retransmit lost frame AND all subsequent frames in the window
            for (i = lost; i <= end; i++) {
                printf("  [Retransmission] Frame %d sent -> Receiver ACK %d received\n", i, i);
            }

            lost = 0; // Loss handled
        } else {
            // All frames in window transmit successfully
            for (i = base; i <= end; i++) {
                printf("  Frame %d sent -> Receiver ACK %d received\n", i, i);
            }
        }

        // Slide window forward
        base = end + 1;
    }

    printf("\nAll %d frames transmitted and acknowledged successfully.\n", n);
    return 0;
}
