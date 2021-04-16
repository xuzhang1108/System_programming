#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#define ERR_EXIT(m)\
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while (0)

typedef struct 
{
    int a;
    int b;
} TEST;

TEST g_data;

void handler(int sig) {
    printf("%d %d\n", g_data.a, g_data.b);
    alarm(1);
}

int main() {
    TEST zeros = {0, 0};
    TEST ones = {1,1};

    if (signal(SIGALRM, handler) == SIG_ERR)
        ERR_EXIT("signal error");

    g_data = zeros;
    alarm(1);
    for (;;) {
        g_data = zeros;
        g_data = ones;
    }
       
    return 0;
}