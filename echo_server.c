#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main() {
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET; // Use IPv4
    hints.ai_socktype = SOCK_STREAM; // Use TCP

    int status = getaddrinfo("Localhost", "8080", &hints, &res);

    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (s < 0) {
        perror("socket creation failed");
        return 1;
    }

    if (bind(s, res->ai_addr, res->ai_addrlen) < 0) {
        perror("bind failed");
        return 1;
    }

    freeaddrinfo(res);

    listen(s, 10);

    int conn = accept(s, NULL, NULL);
    if (conn < 0) {
        perror("accept failed");
        return 1;
    }

    printf("Connection accepted\n");

    send(conn, "Hello, client!\n", 15, 0);
    close(conn);
    close(s);
    return 0;


}