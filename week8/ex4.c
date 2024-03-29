#include <malloc.h>
#include <unistd.h>
#include <sys/resource.h>
#include <string.h>

int main() {
    int* ptr[10];
    size_t size = 1024 * 1024*100;
    struct rusage usage;
    for(int i = 0; i < 10; ++i){
        ptr[i] = (int *)malloc(size);
        memset(ptr[i], 0, size / sizeof(int));
        getrusage(RUSAGE_SELF, &usage);
        printf("memory usage: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
    for(int i = 0; i < 10; ++i)free(ptr[i]);
    return (0);
}
