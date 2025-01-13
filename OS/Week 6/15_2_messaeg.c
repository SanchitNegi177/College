#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <string.h>

#define MSG_SIZE 100

struct msg_data
{
    long msg_type;
    char content[MSG_SIZE];
};

int main()
{
    pid_t child_pid;
    key_t key = ftok("msgqueue", 65);
    int queue_id = msgget(key, 0666 | IPC_CREAT); 

    if (queue_id == -1)
    {
        perror("Message queue creation failed");
        return 1;
    }

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0)
    {
        struct msg_data msg;
        msg.msg_type = 1;
        strcpy(msg.content, "Hello from Child");

        msgsnd(queue_id, &msg, sizeof(msg.content), 0);
        printf("Child sent: %s\n", msg.content);

        msgrcv(queue_id, &msg, sizeof(msg.content), 2, 0);
        printf("Child received: %s\n", msg.content);
    }
    else
    {
        struct msg_data msg;

        msgrcv(queue_id, &msg, sizeof(msg.content), 1, 0);
        printf("Parent received: %s\n", msg.content);

        msg.msg_type = 2;
        strcpy(msg.content, "Hello from Parent");

        msgsnd(queue_id, &msg, sizeof(msg.content), 0);
        printf("Parent sent: %s\n", msg.content);

        wait(NULL);
        
        
    }

    return 0;
}
