/*
 * PRACTICAL 2: HAMMING CODE (7,4)
 * Source: Extracted exactly from existing 'error_detection.cpp' (hammingCode function).
 * Original file: error_detection.cpp
 */

#include <stdio.h>
#include <string.h>

void readBinary(char str[], int max) {
    int valid;

    while (1) {
        scanf("%s", str);

        valid = 1;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != '0' && str[i] != '1') {
                valid = 0;
                break;
            }
        }

        if (valid && strlen(str) <= max)
            return;

        printf("Invalid input! Enter only 0 and 1: ");
    }
}

void hammingCode() {
    char data[5];
    int h[7];

    printf("\nEnter 4 data bits: ");
    readBinary(data, 4);

    if (strlen(data) != 4) {
        printf("Please enter exactly 4 bits!\n");
        return;
    }

    h[2] = data[0] - '0';
    h[4] = data[1] - '0';
    h[5] = data[2] - '0';
    h[6] = data[3] - '0';

    h[0] = h[2] ^ h[4] ^ h[6];
    h[1] = h[2] ^ h[5] ^ h[6];
    h[3] = h[4] ^ h[5] ^ h[6];

    printf("Hamming Code: ");

    for (int i = 0; i < 7; i++)
        printf("%d", h[i]);

    printf("\n");
}

int main() {
    hammingCode();
    return 0;
}
