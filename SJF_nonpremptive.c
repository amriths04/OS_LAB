#include <stdio.h>

#define MAX 100

// Structure to hold process information
struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completed;
};

// Function to calculate Non-Preemptive SJF scheduling
void SJF(struct Process p[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int completed = 0, currentTime = 0;

    while (completed != n) {
        int shortestIndex = -1;
        int minBurstTime = __INT_MAX__;

        // Find the process with the shortest burst time that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && !p[i].completed && p[i].burstTime < minBurstTime) {
                minBurstTime = p[i].burstTime;
                shortestIndex = i;
            }
        }

        // If no process has arrived yet, increment the current time
        if (shortestIndex == -1) {
            currentTime++;
            continue;
        }

        // Process the selected shortest job
        currentTime += p[shortestIndex].burstTime;
        p[shortestIndex].waitingTime = currentTime - p[shortestIndex].arrivalTime - p[shortestIndex].burstTime;
        p[shortestIndex].turnaroundTime = currentTime - p[shortestIndex].arrivalTime;
        p[shortestIndex].completed = 1;
        completed++;

        totalWaitingTime += p[shortestIndex].waitingTime;
        totalTurnaroundTime += p[shortestIndex].turnaroundTime;
    }

    // Display results
    printf("\nNon-Preemptive SJF Scheduling Results:\n");
    printf("PID\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }

    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    struct Process p[MAX];
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].completed = 0;  // Initialize as not completed
    }

    // Call SJF scheduling function
    SJF(p, n);

    return 0;
}
