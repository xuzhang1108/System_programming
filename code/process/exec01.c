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
    
int main(){
    printf("Entering main ....\n");
    printf("pid = %d\n", getppid());

    //execlp("./exec_print_pid", "exec_print_pid", NULL);  //将当前进程替换掉
    int ret = execlp("exec_print_pid", "exec_print_pid", NULL);
    if (ret == -1)
        perror("execlp error");
        
    printf("Exiting main ...\n");
    return 0;
}