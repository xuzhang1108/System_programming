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
    //int ret = execl("./hello", "hello", NULL);
    
    if(ret == -1)
        perror("execl error");
    printf("Exiting main ...\n");
    return 0;
}