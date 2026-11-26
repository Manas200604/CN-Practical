/*
 * PRACTICAL 1: EVEN PARITY CHECK
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Sender counts '1' bits in original binary message.
 * - For EVEN PARITY, if the count of '1's is even, parity bit = 0; if odd, parity bit = 1.
 * - Sender transmits: [Data Bits] + [Parity Bit].
 * - Receiver counts total '1' bits in received frame:
 *     If total '1's % 2 != 0 -> Single-bit error detected!
 *     If total '1's % 2 == 0 -> No error detected (valid frame).
 */

#include <stdio.h>
#include <string.h>

int main() {
    char data[64];
    char frame[65];
    char received[65];
    int ones = 0;
    int i;
    int error = 0;

    printf("========================================\n");
    printf("     PRACTICAL 1: EVEN PARITY CHECK     \n");
    printf("========================================\n");

    // Step 1: Read binary data from user
    printf("Enter binary data bits (e.g. 1011001): ");
    if (scanf("%63s", data) != 1) return 1;

    // Validate binary input
    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] != '0' && data[i] != '1') {
            printf("Error: Only binary characters ('0' and '1') are allowed.\n");
            return 1;
        }
        if (data[i] == '1') {
            ones++;
        }
    }

    // Step 2: Append Even Parity Bit
    // Even parity makes the total number of 1s even.
    strcpy(frame, data);
    frame[i] = (ones % 2 == 0) ? '0' : '1';
    frame[i + 1] = '\0';

    printf("\n--- SENDER SIDE ---\n");
    printf("Original Data : %s\n", data);
    printf("Parity Bit    : %c (Ones count was %d -> Parity makes it even)\n", frame[i], ones);
    printf("Transmitted   : %s\n", frame);

    // Step 3: Simulate Receiver
    printf("\n--- RECEIVER SIDE ---\n");
    printf("Enter received frame (same length %d bits): ", (int)strlen(frame));
    if (scanf("%64s", received) != 1) return 1;

    // Check received length
    if (strlen(received) != strlen(frame)) {
        printf("Notice: Received frame length (%d) differs from sent frame (%d)!\n",
               (int)strlen(received), (int)strlen(frame));
    }

    // Step 4: Verify parity at receiver
    ones = 0;
    for (i = 0; received[i] != '\0'; i++) {
        if (received[i] == '1') {
            ones++;
        }
    }

    if (ones % 2 != 0) {
        error = 1;
    }

    printf("Total 1s received: %d\n", ones);
    if (error) {
        printf("Result: ERROR DETECTED! (Odd count of 1s indicates transmission error)\n");
    } else {
        printf("Result: NO ERROR DETECTED (Parity verified successfully)\n");
    }

    return 0;
}
