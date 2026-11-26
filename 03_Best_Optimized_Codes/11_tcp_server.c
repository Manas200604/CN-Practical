/*
 * PRACTICAL 11: TCP SERVER
 * Best Optimized & Cross-Platform Version (POSIX Linux & Windows Winsock)
 *
 * Concepts:
 * - Connection-oriented, reliable stream socket (SOCK_STREAM).
 * - Steps:
 *     1. Initialize socket API (WSAStartup on Windows).
 *     2. socket(): Create listening socket.
 *     3. bind(): Bind IP and Port (8080).
 *     4. listen(): Listen for incoming connection requests.
 *     5. accept(): Accept incoming client (returns dedicated client socket).
 *     6. recv() / send(): Exchange messages.
 *     7. close(): Close client and server sockets.
 */

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
    typedef int socklen_t;
    #define CLOSE_SOCKET(s) closesocket(s)
#else
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #define CLOSE_SOCKET(s) close(s)
#endif

int main() {
#ifdef _WIN32
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Winsock initialization failed.\n");
        return 1;
    }
#endif

    int server_fd, client_fd;
    char buffer[1024] = {0};
    struct sockaddr_in addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    printf("========================================\n");
    printf("         PRACTICAL 11: TCP SERVER       \n");
    printf("========================================\n");

    // 1. Create TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Socket creation failed!\n");
        return 1;
    }

    // 2. Configure server address (Port 8080, INADDR_ANY)
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        printf("Bind failed on port 8080! Check if port is already in use.\n");
        CLOSE_SOCKET(server_fd);
        return 1;
    }

    // 4. Listen for incoming connections
    if (listen(server_fd, 5) != 0) {
        printf("Listen failed!\n");
        CLOSE_SOCKET(server_fd);
        return 1;
    }

    printf("TCP Server started successfully.\n");
    printf("Listening on port 8080... Waiting for client to connect...\n");

    // 5. Accept incoming client connection
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        printf("Accept failed!\n");
        CLOSE_SOCKET(server_fd);
        return 1;
    }

    printf("[Connection Established] Client connected successfully!\n");

    // 6. Receive message from client
    memset(buffer, 0, sizeof(buffer));
    int bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read > 0) {
        printf("Client says: %s\n", buffer);
    }

    // 7. Send reply to client
    const char *reply = "Hello from TCP Server! Connection confirmed.";
    send(client_fd, reply, (int)strlen(reply), 0);
    printf("Reply sent to client.\n");

    // 8. Clean up and close sockets
    CLOSE_SOCKET(client_fd);
    CLOSE_SOCKET(server_fd);

#ifdef _WIN32
    WSACleanup();
#endif

    printf("Connection closed cleanly.\n");
    return 0;
}
