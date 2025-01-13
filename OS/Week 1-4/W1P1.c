#include <stdio.h>
#include <unistd.h>
int main()
{
	// create a child process
	pid_t pid = fork();
	if (pid < 0)
	{
		// fork failed
		printf("Fork Failed!\n");
		return 1;
	}
	else if (pid == 0)
	{
		// this is the child process
		printf("Currently in the Child Process! PID: %d\n", getpid());
	}
	else
	{
		// this is the parent process
		printf("Currently in the Parent Process! PID: %d\n" ,getpid());
	}
	return 0;
}
