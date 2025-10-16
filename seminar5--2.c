#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd[2];
    size_t size;

    char string[] = "hello world";

    char resstring[14];

    if(pipe(fd) < 0)
    {
        printf("can't create pipe\n");
    }
    //ne dopisal
}