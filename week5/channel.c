#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    while(true){
    int fd[2];
    if(pipe(fd) == -1) {
        printf("Error");
        return 1;
    };
        int id = fork();
        if (id == 0) {
            close(fd[0]);
            char line[1024];
            printf("Publisher text ");
            gets(line);
            write(fd[1], &line, 1024);
            close(fd[1]);
            return 0;
        } else {
            close(fd[1]);
            char line[1024];
            read(fd[0], &line, 1024);
            close(fd[0]);
            printf("Subscriver text:\n");
            puts(line);
        }
    }
}
