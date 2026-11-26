/*
 * PRACTICAL 11: TCP CLIENT
 * Best Optimized & Cross-Platform Version (POSIX Linux & Windows Winsock)
 *
 * Concepts:
 * - Connects to TCP server on 127.0.0.1:8080.
 * - Triggers TCP 3-way handshake (SYN, SYN-ACK, ACK).
 * - Sends message and awaits server response.
 */

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
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
    struct sockaddr_in server;

    printf("========================================\n");
    printf("         PRACTICAL 11: TCP CLIENT       \n");
    printf("========================================\n");

    // 1. Create TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation failed!\n");
        return 1;
    }

    // 2. Set server address (127.0.0.1:8080)
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Connect to server
    printf("Connecting to TCP Server at 127.0.0.1:8080...\n");
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) != 0) {
        printf("Connection failed! Make sure the TCP server is running first.\n");
        CLOSE_SOCKET(sock);
        return 1;
    }

    printf("Connected to TCP Server!\n");

    // 4. Send message to server
    const char *msg = "Hello from TCP Client!";
    send(sock, msg, (int)strlen(msg), 0);
    printf("Message sent to server: \"%s\"\n", msg);

    // 5. Receive server's reply
    memset(buffer, 0, sizeof(buffer));
    int bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read > 0) {
        printf("Server replied: %s\n", buffer);
    }

    // 6. Close socket
    CLOSE_SOCKET(sock);

#ifdef _WIN32
    WSACleanup();
#endif

    printf("Client disconnected cleanly.\n");
    return 0;
}
