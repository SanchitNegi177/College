#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Process
{
    int pid, at, bt, st, ct, rt;
    int tat, wt;
}process;

int compare(const void *p1, const void *p2)
{
    int a = (( process *)p1)->at;
    int b = (( process *)p2)->at;
    if (a != b)
        return a - b;
    else
        return (( process *)p1)->pid - (( process *)p2)->pid;
}

int main()
{
    int n, total_active = 0;
    float swt = 0, stat = 0;
    float awt = 0, atat = 0, cpu = 0;
    int sbt = 0;
    printf("Enter the number of process\n");
    scanf("%d", &n);

    process p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("Enter arrival time and burst time of process %d : ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }
    qsort(p, n, sizeof( process), compare);

    int currTime = 0;
    for (int i = 0; i < n; i++)
    {
        // process not arrived yet
        if (currTime < p[i].at)
        {
            p[i].st = p[i].at;
        }
        // already arrived
        else
        {
            p[i].st = currTime;
        }

        p[i].ct = p[i].st + p[i].bt;
        p[i].rt = p[i].st - p[i].at;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_active += p[i].bt;

        currTime = p[i].ct;
    }

    printf("\nGANTT CHART \n");
    for (int i = 0; i < n; i++)
        printf("P%d ", p[i].pid);

    printf("\n=========================================================================================================\n");
    printf("| Process ID | Arrival Time | Burst Time | Start Time | Completion Time | Waiting Time | Turnaround Time |");
    printf("\n=========================================================================================================\n");
    for (int i = 0; i < n; i++)
    {
        swt += p[i].wt;
        stat += p[i].tat;
        printf("|     %2d     |      %3d      |     %3d    |     %3d    |        %3d      |      %3d     |       %3d      |\n",
               p[i].pid, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("\n=========================================================================================================\n");

    awt = swt / n;
    atat = stat / n;
    int total_time =  currTime;
    
    cpu = ((float)(total_active) / total_time * 100);
    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f", atat);
    float throughput = (float)n / total_time;
    printf("\nThroughput: %.2f", throughput);
    printf("\nCPU utilization: %.2f%% ", cpu);
}