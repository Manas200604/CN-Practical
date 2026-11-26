/*
 * PRACTICAL 11: TCP SERVER
 * Source: Computer Networks Practical Examination Study Handbook (Chapter 11, Page 57)
 * Network Layer / Domain: Transport / Application
 * Core Algorithm / Concept: Connection-Oriented POSIX Sockets
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    char buffer[1024] = {0};
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    // 1. Create TCP socket (IPv4, Stream)
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Configure server IP and Port 8080
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind socket to port and listen for incoming connections
    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 5);
    printf("TCP server waiting...\n");

    // 4. Accept incoming client connection
    client_fd = accept(server_fd, (struct sockaddr *)&addr, &len);

    // 5. Read message from client and send reply
    read(client_fd, buffer, sizeof(buffer) - 1);
    printf("Client says: %s\n", buffer);

    char reply[] = "Hello from TCP server";
    write(client_fd, reply, strlen(reply));

    // 6. Close both client and listening sockets
    close(client_fd);
    close(server_fd);

    return 0;
}
