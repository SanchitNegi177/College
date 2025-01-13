#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the track numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    // Sort the track numbers
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int total_seek = 0, idx = 0;
    
    // Find the closest track index to the head
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= head)
        {
            idx = i;
            break;
        }
    }

    // SCAN logic (towards higher tracks first, then lower tracks)
    for (int i = idx; i < n; i++)
    {
        total_seek += abs(arr[i] - head);
        head = arr[i];
    }
    for (int i = idx-1; i >= 0; i--)
    {
        total_seek += abs(arr[i] - head);
        head = arr[i];
    }
    printf("Total seek movement: %d\n", total_seek);
    return 0;
}
