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
    int outfd;
    outfd = open("Makefile2", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (outfd == -1)
        ERR_EXIT("open error");
    
    int infd;
    infd = open("tp", O_RDONLY);
    if (infd == -1)
        ERR_EXIT("creat error");

    char buf[1024] = {0};
    int n;
    while ((n = read(infd, buf, 1024)) > 0)
    {
        write(outfd, buf, n);
    }

    close(infd);
    close(outfd);
    unlink("tp");
    return 0;
    
}
