//
//  main.c
//  Project_1_Chat_App
//
//  Created by Yaotong Lu on 2/6/20.
//  Copyright © 2020 Yaotong Lu. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

//struct addrinfo {
//    int              ai_flags;     // AI_PASSIVE, AI_CANONNAME, etc.
//    int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
//    int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
//    int              ai_protocol;  // use 0 for "any"
//    size_t           ai_addrlen;   // size of ai_addr in bytes
//    struct sockaddr *ai_addr;      // struct sockaddr_in or _in6
//    char            *ai_canonname; // full canonical hostname
//
//    struct addrinfo *ai_next;      // linked list, next node
//};
//
//struct sockaddr {
//    unsigned short    sa_family;    // address family, AF_xxx
//    char              sa_data[14];  // 14 bytes of protocol address
//};
//
//// (IPv4 only--see struct sockaddr_in6 for IPv6)
//
//struct sockaddr_in {
//    short int          sin_family;  // Address family, AF_INET
//    unsigned short int sin_port;    // Port number
//    struct in_addr     sin_addr;    // Internet address
//    unsigned char      sin_zero[8]; // Same size as struct sockaddr
//};

#define PORT 5001
#define BACKLOG 10

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    int getaddrinfo(const char *node,     // host name to connect to, or an IP address.
//                    const char *service,  // e.g. "http" or port number
//                    const struct addrinfo *hints,
//                    struct addrinfo **res);
    
    /*------------------------------------------Server---------------------------------------*/
    // 1. Create a server socket
    int server_socket =  socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    
    if(server_socket < 0)
    {
        printf("Cannot create socket, exit.");
        exit(-1);
    }

    bzero(&server_addr,sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    printf("Port: %d \n",ntohs(server_addr.sin_port));
    // 2. bind server socket to a port #
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Bind failed, exit.");
        exit(-2);
    }
    // 3. Listen
    if(listen(server_socket, BACKLOG) < 0)
    {
        fprintf(stderr, "Unable to listen on port %d, exit.", PORT);
        exit(-3);
    }
    /* Reference: Chapter_2_V7.01.ppt on page 43: Regular steps for socket programming*/
    
    /*--------------------------------------Client----------------------------------------*/
    
    
    
    return 0;
}
