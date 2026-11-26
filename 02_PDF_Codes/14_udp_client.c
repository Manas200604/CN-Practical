/*
 * PRACTICAL 12: UDP CLIENT
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 12, Page 64)
 * Network Layer / Domain: Transport / Application
 * Core Algorithm / Concept: Connectionless Datagram Sockets
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    char buffer[1024] = {0};
    struct sockaddr_in server;
    socklen_t len = sizeof(server);

    // 1. Create UDP datagram socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. Specify destination server IP and Port 8080
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Send datagram directly to server (no connect() needed)
    char msg[] = "Hello from UDP client";
    sendto(sock, msg, strlen(msg), 0,
           (struct sockaddr *)&server, sizeof(server));

    // 4. Receive reply from server
    recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&server, &len);
    printf("Server says: %s\n", buffer);

    close(sock);

    return 0;
}
