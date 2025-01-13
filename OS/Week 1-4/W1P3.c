#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
int main()
{
	pid_t pid1, pid2;
	pid1 = fork();
	if (pid1 < 0)
	{
		printf("Fork failed for 1st child.\n");
		return 1;
	}
	if (pid1 == 0)
	{
		printf("1st child (Listing files):\n");
		execlp("/bin/ls", "ls", "/", NULL);
		printf("This won't be printed if execl() is successful.\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		printf("Parent: 1st child has finished execution.\n");
		pid2 = fork();
		if (pid2 < 0)
		{
			printf("Fork failed for 2nd child.\n");
			return 1;
		}
		if (pid2 == 0)
		{
			sleep(5);
			printf("2nd child: My parent has died, I am now an orphan.\n");
		}
		else
		{
			printf("Parent process is exiting before 2nd child finishes.\n");
			
		}
	}
	return 0;
}