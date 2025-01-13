#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Process
{
    int bt, at, ct, st, rt, tat, wt, pid, remaining;
    bool isStarted, isCompleted;
} Process;

int comparator(const void *p1, const void *p2)
{
    Process *a = (Process *)p1;
    Process *b = (Process *)p2;
    return a->at - b->at;
}

int comparatorPID(const void *p1, const void *p2)
{
    Process *a = (Process *)p1;
    Process *b = (Process *)p2;
    return a->pid - b->pid;
}

// Queue implementation
#define MAX 1000
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    // if (rear == MAX - 1) {
    //     printf("Queue overflow\n");
    //     return;  // Overflow condition
    // }

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue()
{
    // if (front == -1 || front > rear)
    // {
    //     printf("Queue underflow\n");
    //     return -1;  // Underflow condition
    // }

    int value = queue[front++];

    // Reset the queue when it's empty after dequeuing
    if (front > rear)
        front = rear = -1;

    return value;
}

// Check if queue is empty
bool isQueueEmpty()
{
    return front == -1;
}

int main()
{
    int n, totalActiveTime = 0;
    float avgRT = 0, avgTAT = 0, avgWT = 0;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    bool isVisited[n];
    Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for Process %d: ", i);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i;
        p[i].remaining = p[i].bt;
        p[i].isStarted = false;
        p[i].isCompleted = false;
        isVisited[i] = false;
    }
    qsort(p, n, sizeof(Process), comparator); // AT

    int currentTime = 0, completed = 0, index = -1, timeQuantum;
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    enqueue(0);
    isVisited[0] = true;

    printf("\nGantt Chart\n");
    while (completed != n)
    {
        index = dequeue();
        printf("P%d ", p[index].pid);
        if (!p[index].isStarted)
        {
            if (p[index].at > currentTime)
                p[index].st = p[index].at;
            else
                p[index].st = currentTime;

            currentTime = p[index].st;
            p[index].isStarted = true;
        }

        if (p[index].remaining > timeQuantum)
        {
            p[index].remaining -= timeQuantum;
            currentTime += timeQuantum;
        }
        else
        {
            currentTime += p[index].remaining;
            p[index].remaining = 0;
            p[index].ct = currentTime;
            p[index].rt = p[index].st - p[index].at;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].isCompleted = true;
            completed++;
        }

        // Add new processes to the queue
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= currentTime && !p[i].isCompleted && isVisited[i] == false)
            {
                enqueue(i);
                isVisited[i] = true;
            }
        }

        if (!p[index].isCompleted)
        {
            enqueue(index); // Re-enqueue the process if it's not completed
        }

        // If process arrival time is not yet there
        if (isQueueEmpty())
        {
            for (int i = 0; i < n; i++)
            {
                if (!p[i].isCompleted && !isVisited[i])
                {
                    enqueue(i);
                    isVisited[i] = true;
                    break;
                }
            }
        }
    }

    qsort(p, n, sizeof(Process), comparatorPID);

    float swt = 0, stat = 0, srt = 0;
    int total_active = 0;
    printf("\n========================================================================================================================\n");
    printf("| Process ID | Arrival Time | Burst Time | Start Time | Completion Time | Response Time | Waiting Time | Turnaround Time |");
    printf("\n========================================================================================================================\n");

    for (int i = 0; i < n; i++)
    {
        swt += p[i].wt;
        stat += p[i].tat;
        srt += p[i].rt;
        total_active += p[i].bt;
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
