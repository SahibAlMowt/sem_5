#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    printf("UID:%d\nGID:%d\n", getuid(), getgid());
    return 0;
}