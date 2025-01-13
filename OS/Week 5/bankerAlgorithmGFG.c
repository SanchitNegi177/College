// Banker's Algorithm
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

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {

                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            flag = 0;
            printf("Deadlock Detected \n");
            break;
        }
    }

    if (flag == 1)
    {
        printf("No Deadlock \nSAFE Sequence\n");
        for (int i = 0; i < n - 1; i++)
            printf("P%d -> ", ans[i]);
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}