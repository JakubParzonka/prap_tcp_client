#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv) {
    system("clear");
    if (argc != 3) {
        puts("Invalid number of arguments");
        exit(1);
    }
    int sock_fd;
    int port_nr;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    int n;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Problem during socket creation => ");
    }



    return 0;
}