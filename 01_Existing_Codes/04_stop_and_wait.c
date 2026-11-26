/*
 * PRACTICAL 4: STOP AND WAIT ARQ
 * Source: Extracted exactly from existing 'Sliding Window Mechanism.cpp' (stopAndWait function).
 * Original file: Sliding Window Mechanism.cpp
 */

#include <stdio.h>

int readNumber() {
    int x;

    while (scanf("%d", &x) != 1) {
        printf("Invalid input! Enter a number: ");
        while (getchar() != '\n');
    }

    return x;
}

int readPositive() {
    int x;

    while (1) {
        x = readNumber();

        if (x > 0)
            return x;

        printf("Invalid input! Enter a positive number: ");
    }
}

int readFrame(int n) {
    int x;

    while (1) {
        x = readNumber();

        if (x == -1 || (x >= 1 && x <= n))
            return x;

        printf("Invalid frame! Enter -1 or a frame between 1 and %d: ", n);
    }
}

void stopAndWait() {
    int n, lost;

    printf("\n========== STOP AND WAIT ARQ ==========\n");

    printf("Enter number of frames: ");
    n = readPositive();

    printf("Enter frame to simulate loss (-1 for no loss): ");
    lost = readFrame(n);

    for (int i = 1; i <= n; i++) {

        printf("\nSender: Sending Frame %d\n", i);

        if (i == lost) {
            printf("Frame %d lost!\n", i);
            printf("Sender: Timeout occurred\n");
            printf("Sender: Retransmitting Frame %d\n", i);
        }

        printf("Receiver: Frame %d received\n", i);
        printf("Receiver: ACK %d sent\n", i);
    }

    printf("\nAll frames transmitted successfully.\n");
}

int main() {
    stopAndWait();
    return 0;
}
