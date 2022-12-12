#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    char fname[50];
    printf("Enter file name: ");
    scanf("%s", fname);
    fflush(stdin);
    int r = open(fname, O_CREAT | O_APPEND | O_RDWR, S_IRWXU);
    if (r != -1)
    {
        printf("Open successful\n");
        char str[50], buff[50];

        if (read(r, str, 50) != -1)
        {
            printf("Read successful\n");
            printf("File content:  %s\n", str);
            printf("Enter string to be appended: ");
            scanf("%s", buff);
            int l = strlen(buff);
            if (write(r, buff, l) != -1)
            {
                printf("Write successful\n");
            }
            else
                printf("Write unsuccessful\n");
        }
        else
            printf("Read unsuccessful\n");
    }
    else
        printf("Open unsuccessful\n");
    /*char buf[]="Hello";
    int retwr = write(r,buf,5);
    printf("%d\n",retwr)*/
    close(r);
    return 0;
};
