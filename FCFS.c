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
    int currentTime = 0;

    // Sort processes by arrival time (if not already sorted)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrivalTime > p[j].arrivalTime) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        // If the process arrives after the current time, update current time to its arrival time
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }

        // Waiting time = current time - arrival time
        p[i].waitingTime = currentTime - p[i].arrivalTime;

        // Turnaround time = waiting time + burst time
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;

        // Update current time after processing this job
        currentTime += p[i].burstTime;

        // Accumulate total waiting time and turnaround time for averages
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
