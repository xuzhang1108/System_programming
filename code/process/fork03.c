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

int gval = 100;

int main() {
    signal(SIGCHLD, SIG_IGN);
    printf("before fork pid = %d\n", getpid());

    pid_t pid;
    pid = fork();
    if (pid == -1) {
        ERR_EXIT("fork error");
    }

    if (pid > 0) {
        printf("this is parent pid = %d childpid = %d\n", getpid(), pid);
        sleep(1);
    } 
    else if (pid == 0) {
        printf("this is child pid = %d parentpid = %d\n", getpid(), getppid());
    }

    return 0;
}