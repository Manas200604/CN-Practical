/*
 * PRACTICAL 5: GO-BACK-N ARQ
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 5, Page 26)
 * Network Layer / Domain: Data Link / Transport
 * Core Algorithm / Concept: Sliding Window Cumulative Retransmission
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

    int base = 1; // First frame of the current window

    while (base <= n) {
        int end = base + window - 1;
        if (end > n) {
            end = n; // Do not exceed total frames
        }

        printf("\nSending window %d to %d\n", base, end);

        // Check if the lost frame falls inside current window [base, end]
        if (lost >= base && lost <= end) {
            // Frames before 'lost' are acknowledged normally
            for (int i = base; i < lost; i++) {
                printf("ACK received for frame %d\n", i);
            }

            printf("Frame %d lost!\n", lost);
            printf("Go back and retransmit frames %d to %d\n", lost, end);

            // Retransmit lost frame AND all subsequent frames in window
            for (int i = lost; i <= end; i++) {
                printf("Retransmitted frame %d: ACK received\n", i);
            }
            lost = 0; // Loss handled
        } else {
            // No loss in this window: all frames succeed
            for (int i = base; i <= end; i++) {
                printf("Frame %d sent -> ACK received\n", i);
            }
        }

        // Slide the window forward
        base = end + 1;
    }

    return 0;
}
