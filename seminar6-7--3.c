#include <string.h>
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

    shmid = shmget(key, size, 0666|IPC_CREAT|IPC_EXCL);

    data = (char*)shmat(shmid, NULL, 0);

    const char *text = "hello world!";

    strncpy(data, text, size);

    printf("end of writing\n");

    shmdt(data);

    return 0;
}