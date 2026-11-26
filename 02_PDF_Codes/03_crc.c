/*
 * PRACTICAL 3: CRC - XOR DIVISION
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 3, Page 15-16)
 * Network Layer / Domain: Data Link Layer
 * Core Algorithm / Concept: Polynomial Modulo-2 Division
 */

#include <stdio.h>
#include <string.h>

// Function to perform Modulo-2 (XOR) division
void divide(char data[], char gen[]) {
    int n = strlen(data);
    int g = strlen(gen);
    for (int i = 0; i <= n - g; i++) {
        // Divide only when current leading bit is '1'
        if (data[i] == '1') {
            for (int j = 0; j < g; j++) {
                // XOR: same bits give '0', different bits give '1'
                data[i + j] = (data[i + j] == gen[j]) ? '0' : '1';
            }
        }
    }
}

int main() {
    char msg[50], gen[20], frame[100], temp[100];
    int m, g, error = 0;

    printf("Enter data bits: ");
    scanf("%49s", msg);

    printf("Enter generator bits: ");
    scanf("%19s", gen);

    m = strlen(msg);
    g = strlen(gen);

    // Step 1: Copy message and append (g - 1) zeros
    strcpy(frame, msg);
    for (int i = 0; i < g - 1; i++) {
        frame[m + i] = '0';
    }
    frame[m + g - 1] = '\0';

    // Step 2: Divide temp copy to get remainder
    strcpy(temp, frame);
    divide(temp, gen);

    // Step 3: Append remainder (last g-1 bits of temp) to frame
    for (int i = 0; i < g - 1; i++) {
        frame[m + i] = temp[m + i];
    }
    printf("Transmitted frame: %s\n", frame);

    // Step 4: Receiver checks received frame
    printf("Enter received frame: ");
    scanf("%99s", temp);
    divide(temp, gen);

    // Step 5: Check if any '1' remains in remainder
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == '1') {
            error = 1;
        }
    }

    if (error)
        printf("Error detected\n");
    else
        printf("Frame is valid\n");

    return 0;
}
