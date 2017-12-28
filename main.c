#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

const int buffer_size = 1024;

int main(int argc, char **argv) {
    system("clear");
    if (argc < 3) {
        puts("Give me more arguments!");
        exit(1);
    }
    int socketIsAwesome;
    int portNumber;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *buffer;
    ssize_t x;

    buffer = (char *) malloc(buffer_size);

    socketIsAwesome = socket(AF_INET, SOCK_STREAM, 0);
    if (socketIsAwesome < 0) perror("creating socket operation error ");


    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("getHostByName error ");
        exit(1);
    }
//  setting things to 0
    bzero((char *) &serv_addr, sizeof(serv_addr));
    bcopy(server->h_addr, (char *) &serv_addr.sin_addr.s_addr, (size_t) server->h_length);
    portNumber = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons((uint16_t) portNumber);

    if (connect(socketIsAwesome, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect operation error ");
        exit(1);
    } else {
        puts("Connection established.");
    }

//  getting user input
    printf("Input your numbers: ");
    fgets(buffer, buffer_size, stdin);

    x = write(socketIsAwesome, buffer, buffer_size);
    if (x < 0) {
        perror("write operation error ");
        exit(1);
    }

    x = read(socketIsAwesome, buffer, buffer_size);
    if (x < 0) {
        perror("read operation error ");
        exit(1);
    }

    printf("Message from server: %s\n", buffer);


    return 0;
}
