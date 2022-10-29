// wint_init.c        GCC win_init.c -o win_init.exe -liphlpapi -lws2_32

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif // _WIN32_WINNT

#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "iphlpapi.lib")

int main(void)
{
    WSADATA d;

    if (WSAStartup(MAKEWORD(2,2),&d)){
        printf("WSAStartup has failed!\n");
        return -1;
    }

    DWORD asize = 20000;

    PIP_ADAPTER_ADDRESSES adapters;

    do{
        adapter = (PIP_ADAPTER_ADDRESSES) malloc(asize);

        if (!adapters){
            printf("Failed to allocate %ld bytes for adapters.\n", asize);
            WSACleanup();
            return -1;
        }

        int r = GetAdaptersAddresses(AF_UNSPEC, GAA_FLAG_INCLUDE_PREFIX, 0, adapters, &asize);

        if (r == ERROR_BUFFER_OVERFLOW){
            printf("GetAdaptersAddresses wants %ld bytes.\n",asize);
            free(adapters);
        }
        else if(r == ERROR_SUCCESS){
            break;
        }
        else{
            printf("Unknown error from GetAdaptersAddresses: %d\n",r);
            free(adapters);
            WSACleanup();
            return -1;
        }
    } while(!adapters);





}
