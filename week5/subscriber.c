// C program to implement one side of FIFO
// This side reads first, then reads
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
    mkfifo("/tmp/ex1", 0666);

    char str1[1024];
    while (1)
    {
        fd1 = open("/tmp/ex1",O_RDONLY);
        read(fd1, str1, 1024);
        printf("Publisher: %s\n", str1);

        sleep(1);
    }
    close(fd1);
    return 0;
}
