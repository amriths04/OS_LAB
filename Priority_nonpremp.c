#include <stdio.h>

void nonPreemptivePriority() {
    int n, completed = 0, time = 0, highestPriority;
    int arrivalTime[20], burstTime[20], priority[20];
    int waitingTime[20] = {0}, turnaroundTime[20] = {0}, isCompleted[20] = {0};
    float totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time and priority:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &arrivalTime[i], &burstTime[i], &priority[i]);
    }

    while (completed < n) {
        highestPriority = -1;
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= time && isCompleted[i] == 0 && (highestPriority == -1 || priority[i] < priority[highestPriority])) {
                highestPriority = i;
            }
        }

        if (highestPriority == -1) {
            time++;
            continue;
        }

        time += burstTime[highestPriority];
        waitingTime[highestPriority] = time - arrivalTime[highestPriority] - burstTime[highestPriority];
        turnaroundTime[highestPriority] = time - arrivalTime[highestPriority];
        isCompleted[highestPriority] = 1;
        completed++;
        totalWT += waitingTime[highestPriority];
        totalTAT += turnaroundTime[highestPriority];
    }

    printf("\nProcess\tArrival\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, arrivalTime[i], burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("Average Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    nonPreemptivePriority();
    return 0;
}
