#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

int main ( void ) {
    int CommonAncestorPid = getpid();
    fork();
    fork();
    clock_t t = clock();
    int ParentPid = getppid(), currentPid = getpid();
    if(currentPid != CommonAncestorPid && ParentPid != CommonAncestorPid){
        kill(currentPid, SIGKILL);
    }
    printf("PID:%d     Parent PID:%d\nTime:%ld\n\n", currentPid, ParentPid, t);
    return EXIT_SUCCESS;
}

