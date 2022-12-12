#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
int main()
{
    // char buff[50];
    DIR *d;
    struct dirent *da;
    d = opendir(".");
    // getcwd(buff, sizeof(buff));
    // DIR *dir = opendir(buff);
    // struct dirent *info;
    // while (info = readdir(dir))
    //{
    // printf("%s \t", info->d_name);
    // }
    // printf("\n");
    while (da = readdir(d))
    {
        printf("%s\n", da->d_name);
    }
    return 0;
}
