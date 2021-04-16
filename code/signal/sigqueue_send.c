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

void handler(int sig, siginfo_t *info, void *ctx) {
    printf("recv a sig %d data = %d\n", sig, info->si_value.sival_int);
} 

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage %s pid\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid;
    pid = atoi(argv[1]);
    union sigval v;
    v.sival_int = 100;
    sigqueue(pid, SIGINT, v);
    return 0;
}
