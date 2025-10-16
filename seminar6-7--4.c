#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    key_t key = 1234;

    size_t size = 1024;

    int shmid;
    char *data;

    shmid = shmget(key, size, 0666);

    data = (char*)shmat(shmid, NULL, 0);

    printf("read === %s\n", data);

    shmdt(data);

    shmctl(shmid, IPC_RMID, NULL);

    printf("segment deleete");

    return 0;
}