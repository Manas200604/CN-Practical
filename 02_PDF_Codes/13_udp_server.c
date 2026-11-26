/*
 * PRACTICAL 12: UDP SERVER
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 12, Page 63)
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
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    // 1. Create UDP datagram socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // 2. Configure server address and bind to Port 8080
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    printf("UDP server waiting...\n");

    // 3. Receive datagram and record sender's address in 'client'
    recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&client, &len);
    printf("Client says: %s\n", buffer);

    // 4. Send reply back to 'client' address
    char reply[] = "Hello from UDP server";
    sendto(sock, reply, strlen(reply), 0,
           (struct sockaddr *)&client, len);

    close(sock);

    return 0;
}
