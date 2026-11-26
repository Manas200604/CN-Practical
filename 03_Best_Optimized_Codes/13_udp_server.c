/*
 * PRACTICAL 12: UDP SERVER
 * Best Optimized & Cross-Platform Version (POSIX Linux & Windows Winsock)
 *
 * Concepts:
 * - Connectionless datagram socket (SOCK_DGRAM).
 * - No handshake, no connection state.
 * - recvfrom(): Blocks until a datagram arrives and captures sender's IP/port.
 * - sendto(): Sends response datagram back directly to sender.
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

    int sock;
    char buffer[1024] = {0};
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

    printf("========================================\n");
    printf("         PRACTICAL 12: UDP SERVER       \n");
    printf("========================================\n");

    // 1. Create UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("Socket creation failed!\n");
        return 1;
    }

    // 2. Configure server address (Port 8080, INADDR_ANY)
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    // 3. Bind socket to port
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) != 0) {
        printf("Bind failed on port 8080!\n");
        CLOSE_SOCKET(sock);
        return 1;
    }

    printf("UDP Server started successfully.\n");
    printf("Waiting for datagram packet on port 8080...\n");

    // 4. Receive datagram and capture client's address
    memset(buffer, 0, sizeof(buffer));
    int bytes_read = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
                              (struct sockaddr *)&client, &client_len);

    if (bytes_read > 0) {
        printf("Received %d bytes from %s:%d\n", bytes_read,
               inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        printf("Client says: %s\n", buffer);
    }

    // 5. Send reply datagram back to client
    const char *reply = "Hello from UDP Server! Datagram received.";
    sendto(sock, reply, (int)strlen(reply), 0,
           (struct sockaddr *)&client, client_len);
    printf("Reply sent to client.\n");

    // 6. Close socket
    CLOSE_SOCKET(sock);

#ifdef _WIN32
    WSACleanup();
#endif

    printf("UDP Server shut down cleanly.\n");
    return 0;
}
