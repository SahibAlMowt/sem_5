#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd[2];
    int result;

    size_t size;

    char resstring[14];


    if(pipe(fd) < 0)
    {
        printf("can't create pipe\n");
        exit(-1);
    }

    result = fork();

    if(result)
    {
        printf("can't fork child\n");
        exit(-1);
    }
    else if(result > 0)
    {
        close(fd[0]);

        size = write(fd[1], "hello world", 14);

        if(size != 14)
        {
            printf("can't write all string\n");
            exit(-1);
        }

        close(fd[1]);
        printf("parent exit");
    }
    else
    {
        close(fd[1]);

        size = read(fd[0], resstring, 14);

        if(size < 0)
        {
            printf("can't read string\n");

            exit(-1);
        }

        printf("%s\n", resstring);

        close(fd[0]);
    }

    return 0;
}