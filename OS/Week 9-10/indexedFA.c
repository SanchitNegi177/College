#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 201
#define MAX_BLOCKS 50
int disk[LIMIT];

typedef struct File
{
    char name;
    int *indexBlock;
    int noOfBlocks;
} File;

int main()
{
    memset(disk, 0, sizeof(disk));
    printf("Enter number of files: ");
    int n;
    scanf("%d", &n);

    File files[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i + 1);
        scanf(" %c", &files[i].name);
        printf("Enter no of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].noOfBlocks);

        files[i].indexBlock = (int *)malloc(files[i].noOfBlocks * sizeof(int));
        int allocatedBlocks = 0;

        printf("Enter blocks for file %d: ", i + 1);
        for (int j = 0; j < files[i].noOfBlocks; j++)
        {
            int blockNumber;
            scanf("%d", &blockNumber);
            if (disk[blockNumber] == 0)
            {
                disk[blockNumber] = 1;
                files[i].indexBlock[allocatedBlocks] = blockNumber;
                allocatedBlocks++;
            }
            else break;
        }

        if (allocatedBlocks < files[i].noOfBlocks)
        {
            printf("\nFile %c not allocated completely due to insufficient free blocks.\n", files[i].name);
            free(files[i].indexBlock);
            files[i].indexBlock = NULL;
        }
    }

    printf("\nEnter the file name to be searched: ");
    char searchName;
    scanf(" %c", &searchName);
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (files[i].name == searchName)
        {
            found = 1;
            printf("\nFile Name: %c\n", files[i].name);
            printf("Index block: ");
            
            printf("\nNo. of blocks: %d\n", files[i].noOfBlocks);
            printf("Blocks occupied: ");

            if (files[i].indexBlock)
            {
                for (int j = 0; j < files[i].noOfBlocks; j++)
                {
                    printf("%d ", files[i].indexBlock[j]);
                }
            }
            else
            {
                printf("No index allocated\n ");
            }
            printf("\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nFile %c not found.\n", searchName);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        if (files[i].indexBlock)
        {
            free(files[i].indexBlock);
        }
    }
    return 0;
}
