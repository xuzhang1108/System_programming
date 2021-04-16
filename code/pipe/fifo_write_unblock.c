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

int main() {
    int fd;
    fd = open("p1", O_WRONLY | O_NONBLOCK);
    if (fd == -1)
        ERR_EXIT("open error");

    printf("open succ\n");
    return 0;
}