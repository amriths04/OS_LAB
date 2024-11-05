#include <stdio.h>

void roundRobin() {
    int n, quantum, time = 0, remainingProcesses;
    int arrivalTime[20], burstTime[20], remainingTime[20];
    int waitingTime[20] = {0}, turnaroundTime[20] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival and burst times:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    remainingProcesses = n;
    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= time && remainingTime[i] > 0) {
                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    waitingTime[i] = time - arrivalTime[i] - burstTime[i];
                    turnaroundTime[i] = time - arrivalTime[i];
                    remainingTime[i] = 0;
                    remainingProcesses--;
                }
            }
        }
    }

    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
}

int main() {
    roundRobin();
    return 0;
}
