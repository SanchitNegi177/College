#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 100

int main() {
    pid_t child_pid;
    key_t shm_key = ftok("shmfile", 65);

    int shm_id = shmget(shm_key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        perror("Shared memory creation failed");
        return 1;
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        char *shm_ptr = (char *)shmat(shm_id, NULL, 0);
        strcpy(shm_ptr, "Hello from Child");
        printf("Child wrote: %s\n", shm_ptr);
        shmdt(shm_ptr);
    } else {
        wait(NULL);
        
        char *shm_ptr = (char *)shmat(shm_id, NULL, 0);
        printf("Parent read: %s\n", shm_ptr);
        strcpy(shm_ptr, "Hello from Parent");
        printf("Parent wrote: %s\n", shm_ptr);

        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}
