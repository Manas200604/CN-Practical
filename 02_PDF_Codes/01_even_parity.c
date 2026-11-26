/*
 * PRACTICAL 1: EVEN PARITY CHECK
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 1, Page 4)
 * Network Layer / Domain: Data Link Layer
 * Core Algorithm / Concept: Single-Bit Error Detection
 */

#include <stdio.h>
#include <string.h>

int main() {
    char data[50], frame[51], received[51];
    int ones = 0, i, error = 0;

    // Step 1: Read input binary data from user
    printf("Enter data bits: ");
    scanf("%49s", data);

    // Step 2: Count number of '1's in original data
    for (i = 0; data[i] != '\0'; i++) {
        if (data[i] == '1') {
            ones++;
        }
    }

    // Step 3: Copy data to frame and append even parity bit
    strcpy(frame, data);
    frame[i] = (ones % 2 == 0) ? '0' : '1';
    frame[i + 1] = '\0';

    printf("Transmitted frame: %s\n", frame);

    // Step 4: Simulate receiver reading the frame
    printf("Enter received frame: ");
    scanf("%50s", received);

    // Step 5: Count '1's in received frame
    ones = 0;
    for (i = 0; received[i] != '\0'; i++) {
        if (received[i] == '1') {
            ones++;
        }
    }

    // Step 6: Check if total '1's is odd (error) or even (no error)
    if (ones % 2 != 0) {
        error = 1;
    }

    if (error)
        printf("Error detected\n");
    else
        printf("No error detected\n");

    return 0;
}
