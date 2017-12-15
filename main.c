#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char **argv) {
    system("clear");
    if (argc != 3 ) {
        puts("Give me more arguments!");
        exit(1);
    }
    int socketIsAwesome;
    int portNumber;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    int n;

    socketIsAwesome = socket(AF_INET, SOCK_STREAM, 0);
    if (socketIsAwesome < 0) perror("Problem during socket creation => ");


    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("getHostByName error => ");
        exit(1);
    }

    //setting things to 0
    bzero((char *) &serv_addr, sizeof(serv_addr));
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, (size_t) server->h_length);
    portNumber = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons((uint16_t) portNumber);

    if (connect(socketIsAwesome, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Problem during connecting to server => ");
        exit(1);
    } else {
        puts("Connection established.");
    }

    while(1){
        puts("Please ");
    }

    return 0;
}
