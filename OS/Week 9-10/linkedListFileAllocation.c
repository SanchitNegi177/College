#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 201

int disk[LIMIT];

typedef struct block
{
    int blockNumber;
    struct block *next;
} block;

typedef struct File
{
    char name;
    block *startBlock;
    int blockCnt;
} File;

block *createBlock(int blockNumber)
{
    block *newBlock = (block *)malloc(sizeof(block));
    newBlock->blockNumber = blockNumber;
    newBlock->next = NULL;
    return newBlock;
}

void freeBlocks(block *start)
{
    while (start)
    {
        block *temp = start; 
        disk[temp->blockNumber] = 0;
        start = start->next;
        free(temp);
    }
}

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
        printf("Enter starting block of file %d: ", i + 1);
        int startingBlock;
        scanf("%d", &startingBlock);
        printf("Enter no of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].blockCnt);

        files[i].startBlock = NULL;
        block *current = NULL;

        printf("Enter blocks for file %d: ", i + 1);
        int blockCount = 0;
        for (int j = 0; j < files[i].blockCnt; j++)
        {
            int blockNumber;
            scanf("%d", &blockNumber);
            
            if (disk[blockNumber] == 0)
            {
                disk[blockNumber] = 1;
                block *newBlock = createBlock(blockNumber);
                if (!files[i].startBlock)
                {
                    files[i].startBlock = newBlock;
                }
                else
                {
                    current->next = newBlock;
                }
                current = newBlock;
                blockCount++;
            }
            else break;
        }

        if (blockCount < files[i].blockCnt)
        {
            printf("\nFile %c not allocated completely due to insufficient free blocks.\n", files[i].name);
            freeBlocks(files[i].startBlock);
            files[i].startBlock = NULL;
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
            printf("Start block: %d\n", files[i].startBlock ? files[i].startBlock->blockNumber : -1);
            printf("No. of blocks: %d\n", files[i].blockCnt);
            printf("Blocks occupied: ");
            
            block *current = files[i].startBlock;
            while (current)
            {
                printf("%d ", current->blockNumber);
                current = current->next;
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
