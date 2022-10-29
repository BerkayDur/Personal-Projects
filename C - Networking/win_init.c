/*win_init.c     gcc win_init.c -o win_init.exe -lws2_32    */

/*

#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")


int main(void)
{
    WSADATA d;

    if(WSAStartup(MAKEWORD(2,2),&d)){
        printf("Failed to initialized.\n");
        return -1;
    }

    WSACleanup();
    printf("Ok.\n");
    return 0;
}

*/
