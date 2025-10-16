#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    size_t size;
    char string[] = "Hello world";
    (void)umask(0);

    if((fd = open("myfile.txt", O_WRONLY | O_CREAT, 0666)) < 0)
    {
        printf("can't open file\n");
        exit(-1);
    }

    size = write(fd, string, 14);

    if(size != 14)
    {
        printf("can't all string\n");
        exit(-1);
    }

    if(close(fd) < 0)
    {
        printf("can't close file\n");
    }

    return 0;
}