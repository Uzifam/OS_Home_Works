#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void){
    printf("Hello this is new shell, ( Enter 'quit' for exit)\n");
    char command[256];
    int MainPID = getpid();
    while(strcmp("quit", command)){
        gets(command);
        if(!(strcmp("quit", command)))
            break;
        fork();
        if(getpid() != MainPID) {
            system(command);
            exit(0);
        }
    }
    return EXIT_SUCCESS;

}
