#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 201

int disk[LIMIT];

typedef struct Process
{
    char name;
    int startingBlock;
    int noOfBlocks;
    int blockOccupied[LIMIT];
} process;

int main()
{
    memset(disk, 0, sizeof(disk));
    printf("Enter the number of files: ");
    int n;
    scanf("%d", &n);
    process p[n];

    for (int i = 0; i < n; i++)
    {
        getchar();
        printf("Enter file %d name: ", i + 1);
        scanf("%c", &p[i].name);
        printf("Enter file %d starting block: ", i + 1);
        scanf("%d", &p[i].startingBlock);
        printf("Enter file %d number of blocks required: ", i + 1);
        scanf("%d", &p[i].noOfBlocks);
        memset(p[i].blockOccupied, 0, sizeof(p[i].blockOccupied)); // Initialize occupied blocks
    }

    // Allocate blocks for each file
    for (int i = 0; i < n; i++)
    {
        int reqBlock = 0;
        int flag = 1;

        for (int j = p[i].startingBlock; j < p[i].startingBlock + p[i].noOfBlocks && j < LIMIT; j++)
        {
            if (disk[j] == 1)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            int indx = 0;
            for (int j = p[i].startingBlock; j < p[i].startingBlock + p[i].noOfBlocks && j < LIMIT; j++)
            {
                disk[j] = 1;
                p[i].blockOccupied[indx++] = j;
            }
        }
        else
        {
            printf("\nFile %c not allocated due to insufficient free blocks.\n", p[i].name);
        }
    }

    // Search for a file by name
    getchar();
    char searchName;
    printf("\nEnter file name to be searched: ");
    scanf("%c", &searchName);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].name == searchName)
        {
            found = 1;
            printf("\nFile Details:\n");
            printf("Name: %c\n", p[i].name);
            printf("Starting Block: %d\n", p[i].startingBlock);
            printf("Number of Blocks: %d\n", p[i].noOfBlocks);
            printf("Blocks Occupied: ");
            for (int j = 0; j < p[i].noOfBlocks && p[i].blockOccupied[j] != 0; j++)
            {
                printf("%d ", p[i].blockOccupied[j]);
            }
            printf("\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nFile %c not found.\n", searchName);
    }

    return 0;
}