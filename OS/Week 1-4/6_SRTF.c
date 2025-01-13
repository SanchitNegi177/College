#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct process
{
    int at, bt, st, ct, tat, wt, rt, pid, burst;
    bool isCompleted, isStarted;
} process;

int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for Process %d \n", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].burst = p[i].bt;
        p[i].isCompleted = false;
        p[i].isStarted = false;
    }

    int completed = 0, currentTime = 0;
    int total_active = 0;

    printf("\nGANTT CHART\n");
    while (completed != n)
    {
        int minIndex = -1, minBt = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!p[i].isCompleted && p[i].at <= currentTime && p[i].burst < minBt)
            {
                minBt = p[i].burst;
                minIndex = i;
            }
        }

        if (minIndex == -1)
        {
            currentTime++;
        }
        else
        {
            printf("P%d ", p[minIndex].pid); // gantt chart

            if (!p[minIndex].isStarted)
            {
                p[minIndex].st = currentTime;
                p[minIndex].rt = p[minIndex].st - p[minIndex].at;
                p[minIndex].isStarted = true;
            }

            p[minIndex].burst--;
            total_active++; // Increment total active time when a process is executing
            currentTime++;

            if (p[minIndex].burst == 0)
            {
                p[minIndex].ct = currentTime;
                p[minIndex].tat = p[minIndex].ct - p[minIndex].at;
                p[minIndex].wt = p[minIndex].tat - p[minIndex].bt;
                p[minIndex].isCompleted = true;
                completed++;
            }
        }
    }

    float swt = 0, stat = 0, srt = 0;
    printf("\n========================================================================================================================\n");
    printf("| Process ID | Arrival Time | Burst Time | Start Time | Completion Time | Response Time | Waiting Time | Turnaround Time |");
    printf("\n========================================================================================================================\n");

    for (int i = 0; i < n; i++)
    {
        swt += p[i].wt;
        stat += p[i].tat;
        srt += p[i].rt;
        printf("|     %2d     |      %3d      |     %3d    |     %3d    |        %3d      |      %3d     |      %3d     |       %3d      |\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].rt, p[i].wt, p[i].tat);
    }
    printf("\n=========================================================================================================================\n");

    float avg_wt = swt / n;
    float avg_tat = stat / n;
    float avg_response = srt / n;
    float throughput = (float)n / currentTime;
    float cpu_utilization = (float)total_active / currentTime * 100;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Response Time: %.2f\n", avg_response);
    printf("Throughput: %.2f\n", throughput);
    printf("CPU Utilization: %.2f%%\n", cpu_utilization);

    return 0;
}
