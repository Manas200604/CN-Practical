/*
 * PRACTICAL 3: CYCLIC REDUNDANCY CHECK (CRC)
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Modulo-2 division using binary XOR operations (no carry, no borrow).
 * - Sender appends (g - 1) zeros to the data message (g = length of generator).
 * - Sender divides padded data by generator to get (g - 1) remainder bits (CRC checksum).
 * - Sender transmits: Frame = Message + CRC Remainder.
 * - Receiver divides received frame by same generator polynomial:
 *     If remainder is all zeros -> Frame is valid (no error).
 *     If remainder has any 1   -> Transmission error detected!
 */

#include <stdio.h>
#include <string.h>

// Modulo-2 XOR division function
void modulo2Divide(char data[], const char gen[]) {
    int n = (int)strlen(data);
    int g = (int)strlen(gen);
    int i, j;

    for (i = 0; i <= n - g; i++) {
        // Divide only when leading bit of current window is '1'
        if (data[i] == '1') {
            for (j = 0; j < g; j++) {
                data[i + j] = (data[i + j] == gen[j]) ? '0' : '1';
            }
        }
    }
}

int main() {
    char msg[100];
    char gen[50];
    char frame[200];
    char temp[200];
    int m, g, i, error = 0;

    printf("========================================\n");
    printf("   PRACTICAL 3: CRC (MODULO-2 XOR)      \n");
    printf("========================================\n");

    // Step 1: Input message and generator bits
    printf("Enter data bits (e.g. 110101): ");
    if (scanf("%99s", msg) != 1) return 1;

    printf("Enter generator polynomial bits (e.g. 1011): ");
    if (scanf("%49s", gen) != 1) return 1;

    m = (int)strlen(msg);
    g = (int)strlen(gen);

    if (g <= 1) {
        printf("Error: Generator must be at least 2 bits long.\n");
        return 1;
    }

    // Step 2: Append (g - 1) zeros to message
    strcpy(frame, msg);
    for (i = 0; i < g - 1; i++) {
        frame[m + i] = '0';
    }
    frame[m + g - 1] = '\0';

    // Step 3: Compute CRC remainder using division
    strcpy(temp, frame);
    modulo2Divide(temp, gen);

    // Append remainder (last g-1 bits of temp) to message
    for (i = 0; i < g - 1; i++) {
        frame[m + i] = temp[m + i];
    }
    frame[m + g - 1] = '\0';

    printf("\n--- SENDER SIDE ---\n");
    printf("Original Data     : %s\n", msg);
    printf("Generator Poly    : %s\n", gen);
    printf("CRC Remainder     : %s\n", &frame[m]);
    printf("Transmitted Frame : %s\n", frame);

    // Step 4: Simulate Receiver
    printf("\n--- RECEIVER SIDE ---\n");
    printf("Enter received frame: ");
    if (scanf("%199s", temp) != 1) return 1;

    modulo2Divide(temp, gen);

    // Check if remainder is all zeros
    error = 0;
    for (i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == '1') {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("Result: ERROR DETECTED! (Remainder is non-zero)\n");
    } else {
        printf("Result: FRAME IS VALID (Remainder is all zeros, no error)\n");
    }

    return 0;
}
