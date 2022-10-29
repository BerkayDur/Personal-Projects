// time_server.c     GCC time_server.c -o time_server.exe -lws2_32


#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif // _WIN32_WINNT
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


#if defined(_WIN32)
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())

#else
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>


int main(void)
{
    WSADATA d;
    if (WSAStartup(MAKEWORD(2,2),&d)){
        printf("Error when using WSAStartup function.");
        return -1;
    }

    printf("Configuring local address...\n");
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addinfo *bind_address;
    getaddrinfo(0, "8080", &hints, &bind_address);


    printf("Creating socket...\n");
    SOCKET socket_listen;
    socket_listen = socket(bind_address -> ai_family,
                           bind_address -> ai_socktype,
                           bind_address -> ai_protocol);


    if (!ISVALIDSOCKET(socket_listen)){
        printf("socket() failed. (%d)\n", GETSOCKETERRNO());
        return -1;
    }


    printf("Bind socket to local address...\n");
    if (bind(socket_listen,
             bind_address -> ai_addr,
             bind_address -> ai_addrlen)){
        printf("bind() failed. (%d)\n", GETSOCKETERRNO());
        return -1;
    }
    freeaddrinfo(bind_address);


    printf("Listening...\n");
    if (listen(socket_listen, 10) < 10){
        printf("listen() failed. (%d)\n", GETSOCKETERRNO());
        return -1;
    }


    printf("Waiting for connection...\n");
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    SOCKET socket_client = accept(socket_listen,
                                  (struct sockaddr*) &client_address,
                                  &client_len);
    if (!ISVALIDSOCKET(socket_client)){
        printf("accept() has failed. (%d)\n", GETSOCKETERRNO());
        return -1;
    }


    pritnf("Client is connected...");
    char address_buffer[100];
    getnameinfo((struct sockaddr*) &client_address,
                client_len,
                addres_buffer,
                sizeof(address_buffer),
                0,
                0,
                NI_NUMERICHOST);
    printf("%s\n", address_buffer);




    return 0;
}
