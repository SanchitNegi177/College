#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int pipefds[2];
    pid_t pid;
    char writeMsg[] = "Message from Child";
    char readMsg[100];
    // Create a pipe
    if (pipe(pipefds) == -1)
    {
        perror("Pipe failed");
        return 1;
    }
    pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    if (pid == 0)
    {
        // Child process
        close(pipefds[0]); // Close reading end
        write(pipefds[1], writeMsg, strlen(writeMsg) + 1);
        close(pipefds[1]); // Close writing end
    }
    else
    {
        // Parent process
        close(pipefds[1]); // Close writing end
        read(pipefds[0], readMsg, sizeof(readMsg));
        printf("Parent read: %s\n", readMsg);
        close(pipefds[0]); // Close reading end
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/ipc.h>
// #include <sys/msg.h>
// #include <unistd.h>
// #include <string.h>
// #include <errno.h>

// // Define message buffer structure
// struct msg_buffer {
//     long msg_type;
//     char msg_text[100];
// } message;

// int main() {
//     key_t key;
//     int msgid;

//     // Ensure the file for ftok exists
//     const char *file_path = "progfile";
//     FILE *file = fopen(file_path, "w");
//     if (file == NULL) {
//         perror("Error creating progfile");
//         exit(EXIT_FAILURE);
//     }
//     fclose(file);

//     // Generate unique key
//     if ((key = ftok(file_path, 65)) == -1) {
//         perror("ftok");
//         exit(EXIT_FAILURE);
//     }

//     // Create message queue
//     if ((msgid = msgget(key, 0666 | IPC_CREAT)) == -1) {
//         perror("msgget");
//         exit(EXIT_FAILURE);
//     }

//     message.msg_type = 1; // Message type 1

//     pid_t pid = fork();
//     if (pid == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (pid == 0) { // Child process
//         // Prepare and send message
//         strcpy(message.msg_text, "Message from Child");
//         if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
//             perror("msgsnd");
//             exit(EXIT_FAILURE);
//         }
//         printf("Child sent: %s\n", message.msg_text);
//     } 
//     else { // Parent process
//         // Wait to receive message
//         if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
//             perror("msgrcv");
//             exit(EXIT_FAILURE);
//         }
//         printf("Parent read: %s\n", message.msg_text);

//         // Destroy the message queue
//         if (msgctl(msgid, IPC_RMID, NULL) == -1) {
//             perror("msgctl");
//             exit(EXIT_FAILURE);
//         }
//     }

//     return 0;
// }
