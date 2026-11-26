/*
 * PRACTICAL 3: CRC (CYCLIC REDUNDANCY CHECK)
 * Source: Extracted exactly from existing 'error_detection.cpp' (crc function).
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

void crc() {
    char data[101], generator[31];
    int n, m;
    int temp[130], divisor[30];

    printf("\nEnter data bits: ");
    readBinary(data, 100);

    printf("Enter generator bits: ");
    readBinary(generator, 30);

    n = strlen(data);
    m = strlen(generator);

    for (int i = 0; i < n; i++)
        temp[i] = data[i] - '0';

    for (int i = 0; i < m; i++)
        divisor[i] = generator[i] - '0';

    for (int i = n; i < n + m - 1; i++)
        temp[i] = 0;

    for (int i = 0; i < n; i++) {
        if (temp[i] == 1) {
            for (int j = 0; j < m; j++)
                temp[i + j] = temp[i + j] ^ divisor[j];
        }
    }

    printf("CRC Remainder: ");

    for (int i = n; i < n + m - 1; i++)
        printf("%d", temp[i]);

    printf("\n");
}

int main() {
    crc();
    return 0;
}
