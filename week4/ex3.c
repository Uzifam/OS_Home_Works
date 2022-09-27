#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char * argv[]){
    char str[256];
    strcpy(str, argv[1]);

    int n =atoi(str);

    for(int i = 0; i < n; ++i){
        fork();
        sleep(5);
    }
    return EXIT_SUCCESS;
}
