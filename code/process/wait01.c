#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
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
    
int main(){
    pid_t pid;
    pid = fork();
    if (pid == -1)
        ERR_EXIT("fork error");

    if (pid == 0) {
        sleep(3);
        printf("this is child\n");
        exit(100);
    }
    
    int ret;
    printf("this is parent\n");
    int status;
    ret = waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        printf("child exited normal exit status = %d\n", WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("child exited abnormal signal number = %d\n", WTERMSIG(status));
    return 0;
}