#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Process
{
    int at, bt, st, ct, pid, tat, rt, wt, q;
    bool isCompleted;
} process;

int comp(const void *a, const void *b)
{
    if(((process *)a)->at != ((process *)b)->at)
        return ((process *)a)->at - ((process *)b)->at;
    else
        return ((process *)a)->pid - ((process *)b)->pid;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst time and Arrival time for Process %d: ", i );
        scanf("%d %d", &p[i].bt, &p[i].at);
        p[i].pid = i ;
        p[i].q = 1; // Normal priority
        p[i].isCompleted = false;
    }

    // Set high priority tasks
    printf("Enter the number of high priority tasks: ");
    int temp;
    scanf("%d", &temp);
    printf("Enter the PID of high priority tasks: ");
    for (int i = 0; i < temp; i++)
    {
        int id;
        scanf("%d", &id);
        p[id].q = 0; // Mark as high priority (lower q value)
    }

    int completed = 0, currentTime = 0, totalActiveTime = 0;
    qsort(p, n, sizeof(process), comp); // Sort by arrival time

    printf("\nGANTT CHART\n");
    while (completed != n)
    {
        int idx = -1;
        // Find high priority task first
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currentTime && !p[i].isCompleted && p[i].q == 0)
            {
                idx = i;
                break;
            }
        }

        // If no high priority task, find normal priority
        if (idx == -1)
        {
            for (int i = 0; i < n; i++)
            {
                if (p[i].at <= currentTime && !p[i].isCompleted && p[i].q == 1)
                {
                    idx = i;
                    break;
                }
            }
        }

        // If no task found, increase currentTime
        if (idx == -1)
        {
            currentTime++;
        }
        else
        {
            printf("P%d ",p[idx].pid);

            // Process the selected task
            p[idx].st = currentTime;
            p[idx].ct = p[idx].st + p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;  // Response Time = Start Time - Arrival Time
            p[idx].tat = p[idx].ct - p[idx].at; // Turnaround Time = Completion Time - Arrival Time
            p[idx].wt = p[idx].tat - p[idx].bt; // Waiting Time = Turnaround Time - Burst Time

            p[idx].isCompleted = true;
            completed++;
            totalActiveTime += p[idx].bt; // Add burst time to total active time
            currentTime = p[idx].ct;
        } // Move current time to the process's completion time
    }

    int swt = 0, stat = 0;

    // Output the results for each process
    printf("\n========================================================================================================================\n");
    printf("| Process ID | Arrival Time | Burst Time | Start Time | Completion Time | Response Time | Waiting Time | Turnaround Time |");
    printf("\n========================================================================================================================\n");

    for (int i = 0; i < n; i++)
    {
        swt += p[i].wt;
        stat += p[i].tat;
        printf("|     %2d     |      %3d      |     %3d    |     %3d    |        %3d      |      %3d     |      %3d     |       %3d      |\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].rt, p[i].wt, p[i].tat);
    }
    printf("\n=========================================================================================================================\n");

    float awt = 1.0 * swt / n, atat = 1.0 * stat / n;
    int totalCpuTime = currentTime;
    float cpuUtilization = 1.0*totalActiveTime / totalCpuTime * 100;
    float throughput = 1.0*n / totalCpuTime;

    // CPU Utilization and Throughput
    printf("\nAverage WT: %.2f\n", awt);
    printf("Average TAT: %.2f\n", atat);
    printf("CPU Utilization: %.2f%%\n", cpuUtilization);
    printf("Throughput: %.2f processes/unit time\n", throughput);

    return 0;
}
