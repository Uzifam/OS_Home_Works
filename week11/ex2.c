#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main()
{
    struct dirent *boof_for_files;
    DIR *dir_for_task = opendir("/");
    boof_for_files = readdir(dir_for_task);

    while (boof_for_files != NULL)
    {
        printf("%s\n", boof_for_files->d_name);
        boof_for_files = readdir(dir_for_task);
    }

    closedir(dir_for_task);
    return 0;
}
