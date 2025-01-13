#include <stdio.h>
#include <unistd.h>
int main()
{
	execlp("ls", "ls", "/", NULL);
	// execlp("ls", "ls", "-l", NULL);
	perror("execlp"); // this will execute if execlp fails
	return 0;
}
