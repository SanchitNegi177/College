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
		printf("In the Child Process! PID: %d\n", getpid());
	}
	else
	{
		// this is the parent process
		printf("In the Parent Process! PID: %d, Child PID: %d\n", getpid(), pid);
	}
	return 0;
}
