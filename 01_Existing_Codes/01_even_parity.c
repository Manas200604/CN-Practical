/*
 * PRACTICAL 1: EVEN PARITY
 * Source: Extracted exactly from existing 'error_detection.cpp' (parityCheck function).
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

void parityCheck() {
    char data[101];
    int choice, count = 0;

    printf("\nEnter data bits: ");
    readBinary(data, 100);

    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == '1')
            count++;
    }

    printf("\n1. Even Parity\n");
    printf("2. Odd Parity\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Parity Bit: %d\n", count % 2);
    }
    else if (choice == 2) {
        printf("Parity Bit: %d\n", (count % 2 == 0) ? 1 : 0);
    }
    else {
        printf("Invalid choice!\n");
    }
}

int main() {
    parityCheck();
    return 0;
}
