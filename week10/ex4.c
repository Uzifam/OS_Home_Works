#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *dir = opendir("tmp");
    struct dirent *dp;
    struct dirent *hard_link;

    while ((dp = readdir(dir)) != NULL)
    {
        int links = 0;
        DIR *tmp_dir1 = opendir("tmp");

        while ((hard_link = readdir(tmp_dir1)) != NULL)
        {
            if (dp->d_ino == hard_link->d_ino)
            {
                ++links;
            }
        }

        if (links >= 2)
        {
            printf("%s - ", dp->d_name);
            DIR *tmp_dir2 = opendir("tmp");
            while ((hard_link = readdir(tmp_dir2)) != NULL)
            {
                if (dp->d_ino == hard_link->d_ino)
                {
                    printf("%s", hard_link->d_name);
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
