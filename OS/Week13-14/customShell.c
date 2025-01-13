#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>
#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

void executeCommand(char *cmd, char **args);
void parseCommand(char *cmd, char **args);
void changeDirectory(char *dir);
void listFiles();
void moveFile(char *src, char *dest);
void displayFile(char *file);
void copyFile(char *src, char *dest);

int main()
{
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    while (1)
    {
        printf("myShell> ");
        fgets(cmd, MAX_CMD_LENGTH, stdin);
        cmd[strcspn(cmd, "\n")] = 0; // Remove newline character
        if (strlen(cmd) == 0)
            continue;
        parseCommand(cmd, args);
        if (strcmp(args[0], "exit") == 0)
            break;
        else if (strcmp(args[0], "ls") == 0)
            listFiles();
        else if (strcmp(args[0], "mv") == 0)
        {
            if (args[1] && args[2])
                moveFile(args[1], args[2]);
            else
                printf("mv: missing arguments\n");
        }
        else if (strcmp(args[0], "cat") == 0)
        {
            if (args[1])
            {
                if (args[2])
                    copyFile(args[1], args[2]);

                else
                    displayFile(args[1]);
            }
            else
            {
                printf("cat: missing arguments\n");
            }
        }
        else if (strcmp(args[0], "cd") == 0)
        {
            if (args[1])
                changeDirectory(args[1]);
            else
                printf("cd: missing directory\n");
        }
        else
        {
            executeCommand(cmd, args);
        }
    }
    return 0;
}

void parseCommand(char *cmd, char **args)
{
    char *token = strtok(cmd, " ");
    int i = 0;
    while (token != NULL)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
}

void executeCommand(char *cmd, char **args)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        return;
    }

    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("Command not found or not executable");
        }
        exit(0);
    }

    else
    {
        wait(NULL);
    }
}

void changeDirectory(char *dir)
{
    if (chdir(dir) != 0)
        perror("cd failed");
}

void listFiles()
{
    DIR *d = opendir(".");
    struct dirent *dir;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    else
    {
        perror("ls failed");
    }
}

void moveFile(char *src, char *dest)
{
    if (rename(src, dest) != 0)
        perror("mv failed");
}

void displayFile(char *file)
{
    FILE *f = fopen(file, "r");
    if (!f)
    {
        perror("cat failed");
        return;
    }
    char ch;
    while ((ch = fgetc(f)) != EOF)
    {
        putchar(ch);
    }
    fclose(f);
}

void copyFile(char *src, char *dest)
{
    FILE *srcFile = fopen(src, "r");
    if (!srcFile)
    {
        perror("copyFile failed");
        return;
    }
    FILE *destFile = fopen(dest, "w");
    if (!destFile)
    {
        perror("copyFile failed");
        fclose(srcFile);
        return;
    }
    char ch;
    while ((ch = fgetc(srcFile)) != EOF)
    {
        fputc(ch, destFile);
    }
    fclose(srcFile);
    fclose(destFile);
}
