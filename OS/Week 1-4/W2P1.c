#include <stdio.h>
#include <dirent.h>
int main()
{
	DIR *d= opendir("/");
	struct dirent *dir; 
	if (d == NULL)
	{
		perror("Error");
	}
	else
	{
		printf("Contents of directory:\n");
		while ((dir = readdir(d)) != NULL)
		{
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
	return 0;
}
