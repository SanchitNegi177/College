#include <stdio.h>

int main()
{
    int n, m, i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m], finish[n], ans[n], ind = 0;
    // Input max matrix
    printf("Enter the max matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d Max: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d Allocation: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input available resources or Resource Vector
    printf("Enter the available resources: ");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    // Initialize finish flags
    for (k = 0; k < n; k++)
    {
        finish[k] = 0;
    }

    // Calculate the need matrix
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                // If the process is not yet finished
                int flag = 1;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 0; // If resources needed are more than available
                        break;
                    }
                }

                if (flag == 1)
                {
                    // If the process can be completed
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                    {
                        avail[y] += alloc[i][y];
                    }
                    finish[i] = 1; // Mark process as completed
                }
            }
        }
    }

    // Check if all processes are finished
    int flag = 1;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            // If any process is not finished
            flag = 0;
            break;
        }
    }

    // If system is in a safe state, print the safe sequence
    if (flag == 1)
    {
        printf("The system is in a safe state.\n");
        printf("Safe sequence: ");
        for (i = 0; i < n - 1; i++)
        {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }
    else
    {
        printf("The system is not in a safe state.\n");
    }

    return 0;
}
