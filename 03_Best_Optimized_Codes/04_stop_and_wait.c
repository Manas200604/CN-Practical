/*
 * PRACTICAL 4: STOP-AND-WAIT ARQ
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Flow control & error control protocol.
 * - Sender sends 1 frame and waits for its Acknowledgement (ACK).
 * - If frame is lost:
 *     Sender timeout occurs.
 *     Sender retransmits the lost frame.
 *     Receiver receives frame and returns ACK.
 * - Once ACK is received, sender moves to the next frame.
 */

#include <stdio.h>

int main() {
    int n, lost;
    int i;

    printf("========================================\n");
    printf("     PRACTICAL 4: STOP-AND-WAIT ARQ     \n");
    printf("========================================\n");

    printf("Enter total number of frames to send: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of frames!\n");
        return 1;
    }

    printf("Enter frame number to simulate loss (1 to %d, or 0 for no loss): ", n);
    if (scanf("%d", &lost) != 1 || lost < 0 || lost > n) {
        printf("Invalid loss choice!\n");
        return 1;
    }

    printf("\n--- SIMULATION TRACE ---\n");
    for (i = 1; i <= n; i++) {
        printf("\n[Sender]   Sending Frame %d\n", i);

        if (i == lost) {
            printf("[Network]  *** Frame %d is LOST! ***\n", i);
            printf("[Sender]   Timeout waiting for ACK %d...\n", i);
            printf("[Sender]   Retransmitting Frame %d\n", i);
            printf("[Receiver] Frame %d received successfully -> Sending ACK %d\n", i, i);
            printf("[Sender]   ACK %d received\n", i);
            lost = 0; // Loss handled, retransmission successful
        } else {
            printf("[Receiver] Frame %d received successfully -> Sending ACK %d\n", i, i);
            printf("[Sender]   ACK %d received\n", i);
        }
    }

    printf("\nAll %d frames sent and acknowledged successfully.\n", n);
    return 0;
}
