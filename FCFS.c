#include <stdio.h>

#define MAX 100

// Structure to hold process information
struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate FCFS scheduling
void FCFS(struct Process p[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calculate waiting time for each process
    p[0].waitingTime = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;
    }

    // Display results
    printf("\nFCFS Scheduling Results:\n");
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
    }

    // Call FCFS scheduling function
    FCFS(p, n);

    return 0;
}
