/*
 * PRACTICAL 11: TCP CLIENT
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 11, Page 58)
 * Network Layer / Domain: Transport / Application
 * Core Algorithm / Concept: Connection-Oriented POSIX Sockets
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    char buffer[1024] = {0};
    struct sockaddr_in server;

    // 1. Create TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Set target server IP (localhost) and Port 8080
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Connect to server (triggers TCP 3-way handshake)
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    // 4. Send message and read server's response
    char msg[] = "Hello from TCP client";
    write(sock, msg, strlen(msg));

    read(sock, buffer, sizeof(buffer) - 1);
    printf("Server says: %s\n", buffer);

    // 5. Close socket
    close(sock);

    return 0;
}
