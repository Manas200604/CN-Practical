/*
 * PRACTICAL 4: STOP-AND-WAIT ARQ
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 4, Page 21)
 * Network Layer / Domain: Data Link / Transport
 * Core Algorithm / Concept: Single-Frame Flow & Error Control
 */

#include <stdio.h>

int main() {
    int n, lost;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter frame number to lose (0 for none): ");
    scanf("%d", &lost);

    // Loop through each frame one by one
    for (int i = 1; i <= n; i++) {
        printf("Sending frame %d\n", i);
        if (i == lost) {
            // Simulate frame loss, timeout, and single retransmission
            printf("Frame %d lost! Timeout...\n", i);
            printf("Retransmitting frame %d\n", i);
            printf("ACK received for frame %d\n", i);
            lost = 0; // Reset lost so it succeeds on retransmission
        } else {
            printf("ACK received for frame %d\n", i);
        }
    }

    return 0;
}
