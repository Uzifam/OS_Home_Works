#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    FILE *f2;
    f2 = fopen("ex2.txt", "w");

    const char *keySignal = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event event;
    ssize_t rd;
    int fd;

    fd = open(keySignal, O_RDONLY);
    while (true) {
        rd = read(fd, &event, sizeof event);
        if (event.type == EV_KEY && event.value == 0)
            fprintf(f2,"%s 0x%04x (%d)\n", "RELEASED", (int)event.code, (int)event.code);
            else if (event.type == EV_KEY && event.value == 1)
            fprintf(f2,"%s 0x%04x (%d)\n", "PRESSED", (int)event.code, (int)event.code);
    }

    return 1;
}
