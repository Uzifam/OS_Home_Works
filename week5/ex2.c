#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include <string.h>

struct Thread{
    int i;
    int *id;
    char message[256];
};

struct Thread thread[10];
int j = 0;

void * func(void *arg) {
    thread[j].i = j;
   strcpy(thread[j].message, "Thread ");
    char boof[10];
    sprintf(boof, "%d", j);
    strcat(thread[j].message, boof);
    strcat(thread[j].message, " is created\n");
    thread[j].id = (int *)arg;
}
int main(void) {
    pthread_t thred[10];

    for(j = 0; j < 10; ++j){
        pthread_create(&(thred[j]), NULL, &func, (void *)(&(thred[j])));
        printf("Hello from thread: %d\n", j);
        printf("Thread %d exits\n", j);
        pthread_join(thred[j], NULL);
    }


     pthread_exit(NULL);



    return 0;
}
