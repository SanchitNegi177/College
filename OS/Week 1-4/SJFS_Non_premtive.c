#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
typedef struct Process
{
    int pid, st, ct, bt, at, rt, wt, tat;
    bool isCompleted;
} Process;

int main()
{
    int n, swt = 0, stat = 0, srt = 0;
    float awt = 0, atat = 0, art = 0;
    float cpu = 0;

    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("\n");

    Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("Enter arrival time and burst time of process %d : ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].isCompleted = false;
    }

    int currTime = 0, total_active = 0, completed = 0;
    int gantt[n];
    int gantt_indx = 0;
    
    while (completed != n)
    {
        int minIndex = -1;
        int minBt = INT_MAX;

        // Find the process with the shortest burst time that's already arrived and not completed
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currTime && !p[i].isCompleted && p[i].bt < minBt)
            {
                minBt = p[i].bt;
                minIndex = i;
            }
        }

        if (minIndex != -1)
        {
            // If a valid process is found, execute it
            p[minIndex].st = currTime;
            p[minIndex].ct = p[minIndex].st + p[minIndex].bt;
            p[minIndex].tat = p[minIndex].ct - p[minIndex].at;
            p[minIndex].wt = p[minIndex].tat - p[minIndex].bt;
            p[minIndex].rt = p[minIndex].st - p[minIndex].at;

            total_active += p[minIndex].bt;
            currTime = p[minIndex].ct;

            p[minIndex].isCompleted = 1;
            completed++;
            gantt[gantt_indx++] = p[minIndex].pid;
        }
        else
        {
            // If no process is ready to execute, increment current time to wait for next arrival
            currTime++;
        }
    }

    printf("\nGANTT CHART\n ");
    for (int i = 0; i < n; i++)
        printf("P%d ", gantt[i]);

    // Printing the results with proper formatting
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

    awt = (1.0 * swt) / n;
    atat = (1.0 * stat) / n;
    art = (1.0 * srt) / n;

    // int total_time = p[n - 1].ct - p[0].at;
    int total_time = currTime;
    cpu = (((float)total_active) / total_time) * 100;

    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Response Time: %.2f", art);

    float throughput = (float)n / total_time;
    printf("\nThroughput: %.2f", throughput);
    printf("\nCPU utilization: %.2f%% \n", cpu);

    return 0;
}
