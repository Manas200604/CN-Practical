/*
 * PRACTICAL 10: IP SUBNETTING (CIDR)
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 10, Page 51-52)
 * Network Layer / Domain: Network Layer
 * Core Algorithm / Concept: Bitwise Masking & Host Addressing
 */

#include <stdio.h>
#include <math.h>

int main() {
    int ip[4], mask[4], network[4], broadcast[4];
    int cidr, bits;

    printf("Enter IP address (4 octets): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter CIDR prefix (0-32): ");
    scanf("%d", &cidr);

    if (cidr < 0 || cidr > 32) {
        printf("Invalid CIDR\n");
        return 1;
    }

    // Calculate Subnet Mask, Network Address, and Broadcast Address per octet
    for (int i = 0; i < 4; i++) {
        bits = cidr - i * 8;
        if (bits >= 8)
            mask[i] = 255;
        else if (bits <= 0)
            mask[i] = 0;
        else
            mask[i] = 256 - (int)pow(2, 8 - bits);

        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (255 - mask[i]);
    }

    printf("Subnet mask: ");
    for (int i = 0; i < 4; i++)
        printf("%d%s", mask[i], i == 3 ? "\n" : ".");

    printf("Network address: ");
    for (int i = 0; i < 4; i++)
        printf("%d%s", network[i], i == 3 ? "\n" : ".");

    printf("Broadcast address: ");
    for (int i = 0; i < 4; i++)
        printf("%d%s", broadcast[i], i == 3 ? "\n" : ".");

    if (cidr <= 30) {
        int first[4], last[4];
        for (int i = 0; i < 4; i++) {
            first[i] = network[i];
            last[i] = broadcast[i];
        }

        // Add 1 to network address (with carry across octets)
        for (int i = 3; i >= 0; i--) {
            if (++first[i] <= 255) break;
            first[i] = 0;
        }

        // Subtract 1 from broadcast address (with borrow across octets)
        for (int i = 3; i >= 0; i--) {
            if (--last[i] >= 0) break;
            last[i] = 255;
        }

        printf("First usable: ");
        for (int i = 0; i < 4; i++)
            printf("%d%s", first[i], i == 3 ? "\n" : ".");

        printf("Last usable: ");
        for (int i = 0; i < 4; i++)
            printf("%d%s", last[i], i == 3 ? "\n" : ".");

        printf("Usable hosts: %.0f\n", pow(2, 32 - cidr) - 2);
    } else if (cidr == 31) {
        printf("/31: point-to-point subnet (2 addresses)\n");
    } else {
        printf("/32: single host address\n");
    }

    return 0;
}
