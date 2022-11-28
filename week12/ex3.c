#include <stdio.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
    FILE *f2;
    f2 = fopen("ex3.txt", "w");

    const char *keySignal = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event pushButten;
    ssize_t rd;
    int fd;

    fd = open(keySignal, O_RDONLY);
    int allButten[5000];
    for(int i = 0; i < 5000; ++i)allButten[i] = 0;
    while (true) {
        read(fd, &pushButten, sizeof(pushButten));
        if (pushButten.value == 1 || pushButten.value == 2)
            allButten[pushButten.code] = pushButten.time.tv_sec;


        int flag = 0;
        for (int i = 0; i < 300; i++)
            if (allButten[i] == pushButten.time.tv_sec) flag++;

            else if (pushButten.value == 0)
                allButten[pushButten.code] = -1;

        if (allButten[KEY_P] == pushButten.time.tv_sec && allButten[KEY_E] == pushButten.time.tv_sec && flag == 2)
            fprintf(f2,"I passed the Exam!\n");
        if (allButten[KEY_C] == pushButten.time.tv_sec && allButten[KEY_A] == pushButten.time.tv_sec &&
            allButten[KEY_P] == pushButten.time.tv_sec && flag == 3)
            fprintf(f2, "Get some cappuccino!\n");
        if (allButten[KEY_O] == pushButten.time.tv_sec && allButten[KEY_S] == pushButten.time.tv_sec && flag == 2)
            fprintf(f2,"I think the OS course was very useful\n");
    }
    return 0;
}
