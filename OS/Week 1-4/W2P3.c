#include <stdio.h>
#include <unistd.h>
#include <string.h>

void writeInFile(char *filename, char *content)
{
	FILE *f = fopen(filename, "w");
	if (f == NULL)
	{
		perror("open");
		return;
	}
	fprintf(f, "%s", content);
	fclose(f);
}

void printMatching(char *file1, char *file2)
{
	FILE *fp1 = fopen(file1, "r");
	FILE *fp2 = fopen(file2, "r");
	if (!fp1 || !fp2)
	{
		perror("Error opening file");
		return;
	}
	char line1[256], line2[256];
	// rewind(fp2); // set the file pointer to the start

	while (fgets(line1, sizeof(line1), fp1) != NULL && fgets(line2, sizeof(line2), fp2) != NULL)
	{
		if (strcmp(line1, line2) == 0)
		{
			printf(" %s", line1);
		}
	}

	fclose(fp1);
	fclose(fp2);
}
int main()
{
	char mydetails[] = "Name: Sanchit Negi\nAge: 21\nDepartment: CSE\n";
	char frienddetails[] = "Name: Sid Pok\nAge: 21\nDepartment: CSE\n";

	writeInFile("myDetail.txt", mydetails);
	writeInFile("otherUserDetail.txt", frienddetails);

	printf("Matching lines in both files:\n");
	printMatching("myDetail.txt", "otherUserDetail.txt");
	return 0;
}
