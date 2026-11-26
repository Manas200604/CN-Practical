/*
 * PRACTICAL 12: UDP CLIENT
 * Best Optimized & Cross-Platform Version (POSIX Linux & Windows Winsock)
 *
 * Concepts:
 * - Connectionless datagram socket (SOCK_DGRAM).
 * - Sends datagram directly to destination server without connect().
 * - recvfrom(): Awaits reply datagram from server.
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
    struct sockaddr_in server;
    socklen_t server_len = sizeof(server);

    printf("========================================\n");
    printf("         PRACTICAL 12: UDP CLIENT       \n");
    printf("========================================\n");

    // 1. Create UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("Socket creation failed!\n");
        return 1;
    }

    // 2. Set server address (127.0.0.1:8080)
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 3. Send datagram directly to server
    const char *msg = "Hello from UDP Client!";
    sendto(sock, msg, (int)strlen(msg), 0,
           (struct sockaddr *)&server, sizeof(server));
    printf("Datagram sent to server: \"%s\"\n", msg);

    // 4. Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    printf("Waiting for reply from server...\n");
    int bytes_read = recvfrom(sock, buffer, sizeof(buffer) - 1, 0,
                              (struct sockaddr *)&server, &server_len);

    if (bytes_read > 0) {
        printf("Server replied: %s\n", buffer);
    }

    // 5. Close socket
    CLOSE_SOCKET(sock);

#ifdef _WIN32
    WSACleanup();
#endif

    printf("UDP Client closed cleanly.\n");
    return 0;
}
