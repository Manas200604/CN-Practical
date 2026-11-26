/*
 * PRACTICAL 5: GO-BACK-N ARQ
 * Source: Extracted exactly from existing 'Sliding Window Mechanism.cpp' (goBackN function).
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

void goBackN() {
    int n, window, lost;

    printf("\n========== GO-BACK-N ARQ ==========\n");

    printf("Enter number of frames: ");
    n = readPositive();

    printf("Enter window size: ");
    while (1) {
        window = readPositive();

        if (window <= n)
            break;

        printf("Window size cannot be greater than %d: ", n);
    }

    printf("Enter frame to simulate loss (-1 for no loss): ");
    lost = readFrame(n);

    int i = 1;

    while (i <= n) {

        int end = i + window - 1;

        if (end > n)
            end = n;

        printf("\nSending Window: ");

        for (int j = i; j <= end; j++)
            printf("%d ", j);

        printf("\n");

        if (lost >= i && lost <= end) {

            for (int j = i; j < lost; j++)
                printf("Receiver: Frame %d received, ACK %d sent\n", j, j);

            printf("Frame %d lost!\n", lost);
            printf("Sender: Timeout occurred for Frame %d\n", lost);

            printf("Go-Back-N: Retransmitting from Frame %d\n", lost);

            for (int j = lost; j <= end; j++) {
                printf("Sender: Retransmitting Frame %d\n", j);
                printf("Receiver: Frame %d received, ACK %d sent\n", j, j);
            }

            lost = -1;
        }
        else {
            for (int j = i; j <= end; j++)
                printf("Receiver: Frame %d received, ACK %d sent\n", j, j);
        }

        i = end + 1;
    }

    printf("\nAll frames transmitted successfully.\n");
}

int main() {
    goBackN();
    return 0;
}
