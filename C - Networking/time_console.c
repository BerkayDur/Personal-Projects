// time_console.c     gcc time_console.c -o time_console.exe

#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t timer;
    time(&timer);

    printf("Local time is: %s", ctime(&timer));

    return 0;
}


