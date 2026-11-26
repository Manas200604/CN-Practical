/*
 * PRACTICAL 10: IP SUBNETTING (CIDR)
 * Best Optimized & Corrected Version
 *
 * Concepts:
 * - Given an IPv4 address and CIDR prefix (/0 to /32):
 * - Subnet Mask calculation:
 *     For each octet, bits = CIDR - (i * 8).
 *     If bits >= 8: mask = 255
 *     If bits <= 0: mask = 0
 *     Else: mask = 256 - 2^(8 - bits)
 * - Network Address   = IP & Subnet_Mask
 * - Broadcast Address = Network_Address | (255 - Subnet_Mask)
 * - Usable Host Range : First = Network + 1, Last = Broadcast - 1
 * - Usable Hosts Count = 2^(32 - CIDR) - 2 (for CIDR <= 30)
 */

#include <stdio.h>
#include <math.h>

int main() {
    int ip[4], mask[4], network[4], broadcast[4];
    int first[4], last[4];
    int cidr, bits, i;

    printf("========================================\n");
    printf("      PRACTICAL 10: IP SUBNETTING (CIDR)\n");
    printf("========================================\n");

    printf("Enter IPv4 address (e.g. 192.168.1.75): ");
    if (scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]) != 4) {
        printf("Invalid IPv4 address format!\n");
        return 1;
    }

    // Validate octet range
    for (i = 0; i < 4; i++) {
        if (ip[i] < 0 || ip[i] > 255) {
            printf("Invalid IP octet: %d (must be 0-255)\n", ip[i]);
            return 1;
        }
    }

    printf("Enter CIDR prefix length (0 to 32): ");
    if (scanf("%d", &cidr) != 1 || cidr < 0 || cidr > 32) {
        printf("Invalid CIDR prefix! Must be between 0 and 32.\n");
        return 1;
    }

    // Calculate Mask, Network, and Broadcast per octet
    for (i = 0; i < 4; i++) {
        bits = cidr - (i * 8);
        if (bits >= 8) {
            mask[i] = 255;
        } else if (bits <= 0) {
            mask[i] = 0;
        } else {
            mask[i] = 256 - (int)pow(2, 8 - bits);
        }

        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (255 - mask[i]);
    }

    printf("\n--- SUBNETTING RESULTS ---\n");
    printf("Input IP Address  : %d.%d.%d.%d /%d\n", ip[0], ip[1], ip[2], ip[3], cidr);
    printf("Subnet Mask       : %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    printf("Network Address   : %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address : %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    if (cidr <= 30) {
        for (i = 0; i < 4; i++) {
            first[i] = network[i];
            last[i] = broadcast[i];
        }

        // First usable = Network Address + 1
        for (i = 3; i >= 0; i--) {
            if (++first[i] <= 255) break;
            first[i] = 0;
        }

        // Last usable = Broadcast Address - 1
        for (i = 3; i >= 0; i--) {
            if (--last[i] >= 0) break;
            last[i] = 255;
        }

        printf("First Usable IP   : %d.%d.%d.%d\n", first[0], first[1], first[2], first[3]);
        printf("Last Usable IP    : %d.%d.%d.%d\n", last[0], last[1], last[2], last[3]);
        printf("Total Usable Hosts: %.0f\n", pow(2, 32 - cidr) - 2);
    } else if (cidr == 31) {
        printf("Subnet Type       : /31 Point-to-Point Link (RFC 3021, 2 addresses)\n");
    } else {
        printf("Subnet Type       : /32 Single Host Route (Loopback/Host address)\n");
    }

    return 0;
}
