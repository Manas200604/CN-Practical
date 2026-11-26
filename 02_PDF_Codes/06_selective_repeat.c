/*
 * PRACTICAL 6: SELECTIVE REPEAT ARQ
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 6, Page 31)
 * Network Layer / Domain: Data Link / Transport
 * Core Algorithm / Concept: Sliding Window Selective Retransmission
 */

#include <stdio.h>

int main() {
    int n, window, lost;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("Enter frame to lose (0 for none): ");
    scanf("%d", &lost);

    // Slide window in steps of 'window'
    for (int base = 1; base <= n; base += window) {
        int end = base + window - 1;
        if (end > n) {
            end = n;
        }

        printf("\nSending window %d to %d\n", base, end);

        // Transmit every frame in the window; good frames are ACKed immediately
        for (int i = base; i <= end; i++) {
            if (i == lost) {
                printf("Frame %d lost!\n", i);
            } else {
                printf("Frame %d received: ACK\n", i);
            }
        }

        // Retransmit ONLY the lost frame if it was in this window
        if (lost >= base && lost <= end) {
            printf("Retransmitting only frame %d\n", lost);
            printf("Frame %d received: ACK\n", lost);
            lost = 0;
        }
    }

    return 0;
}
