#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    mkfifo("/tmp/ex1", 0666);

    char arr1[1024];
    while (1)
    {
        fd = open("/tmp/ex1", O_WRONLY);

        fgets(arr1, 1024, stdin);
        for(int i = 0; i < 1; ++i) {
            write(fd, arr1, strlen(arr1) + 1);
            sleep(1);
        }
    }
    close(fd);
    return 0;
}
