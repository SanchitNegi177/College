#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("Enter number of free blocks\n");
    int n;
    scanf("%d", &n);
    int block[n];
    printf("Enter %d blocks\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes\n");
    int m;
    scanf("%d", &m);
    printf("Enter %d processes\n", m);
    int process[m];
    for (int j = 0; j < m; j++)
        scanf("%d", &process[j]);

    int occupied[n];
    for (int i = 0; i < n; i++)
        occupied[i] = false;

    int ans[m];
    for (int j = 0; j < m; j++)
        ans[j] = -1;

    for (int j = 0; j < m; j++)
    {
        int maxi = -1;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            int diff = block[i] - process[j];
            if (!occupied[i] && process[j] <= block[i] && maxi < diff)
            {
                maxi = diff;
                index = i;
            }
        }
        if (index != -1)
        {
            ans[j] = index + 1;
            occupied[index] = true;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (ans[j] == -1)
        {
            printf("%d - No free block allocated\n", process[j]);
        }
        else
        {
            printf("%d - %d\n", process[j], ans[j]);
        }
    }
}