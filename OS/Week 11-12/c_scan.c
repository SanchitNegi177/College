#include <stdio.h>
#include <stdlib.h>

void cscanDiskScheduling(int requests[], int n, int head, int diskSize)
{
    int totalMovement = 0, currentHead = head;
    int i, j, index=0 ;
    // Sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (requests[j] > requests[j + 1])
            {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (requests[i] >= head)
            index = i; break;
    }


    printf("\nSequence of disk access: %d", head);
    for (i = index; i < n; i++)
    {
        totalMovement += abs(currentHead - requests[i]);
        currentHead = requests[i];
        printf(" -> %d", requests[i]);
    }

    totalMovement += abs(currentHead - (diskSize - 1));
    
    currentHead = diskSize - 1;
    printf(" -> %d", diskSize - 1);
    totalMovement += abs(currentHead - 0);
    currentHead = 0;
    printf(" -> 0");

    for (i = 0; i < index; i++)
    {
        totalMovement += abs(currentHead - requests[i]);
        currentHead = requests[i];
        printf(" -> %d", requests[i]);
    }
    printf("\n\nTotal head movement: %d\n", totalMovement);
}

int main()
{
    int n, head, diskSize;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);
    printf("Enter the total disk size: ");
    scanf("%d", &diskSize);
    cscanDiskScheduling(requests, n, head, diskSize);
    return 0;
}
