#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void makeArrays(int *u, int *v){
    for(int i = 0; i < 120; ++i){
        *(u + i) = rand() % 121;
        *(v + i) = rand() % 121;
    }
}

int dotprod(int u[], int v[], int start, int end){

    int result = 0;

    for (int i = start; i < end; i++){
        result += u[i] * v[i];
    }

    return result;
}

int main ( void ) {
    FILE *pFile = fopen("temp.txt", "a");
    int u[120], v[120];
    makeArrays(u, v);
    int n, MainPID = getpid();
    scanf("%d", &n);

    for(int i = 0; i < n; ++i){
        fork();
        if(getpid() != MainPID) {
            fprintf(pFile, "%d ",dotprod(u, v, i * (120 / n), (i + 1) * (120 / n) - 1));
            exit(0);
        }

    }
    //Waiting
    pid_t wpid;
    int status;
    while ((wpid = wait(&status)) > 0);

    close(pFile);
    pFile = fopen("temp.txt", "r");
    long long answer = 0, boof;
    for(int i = 0; i < n; ++i){
        fscanf(pFile, "%d", &boof);
        answer += boof;
    }
    close(pFile);
    pFile = fopen("temp.txt", "w");
    fprintf(pFile, "%lld", answer);
    close(pFile);

    return EXIT_SUCCESS;
}
