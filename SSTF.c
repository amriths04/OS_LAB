#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void SSTF() {
    int requests[MAX], seekSequence[MAX], visited[MAX] = {0};
    int n, head, seekCount = 0, choice;

    while (1) {
        printf("\nDisk Scheduling - SSTF Algorithm\n");
        printf("1. Enter requests\n");
        printf("2. Run SSTF algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the number of requests: ");
            scanf("%d", &n);
            printf("Enter the requests: ");
            for (int i = 0; i < n; i++) {
                scanf("%d", &requests[i]);
            }
            printf("Enter the initial head position: ");
            scanf("%d", &head);
        }
        else if (choice == 2) {
            seekCount = 0;

            for (int i = 0; i < n; i++) {
                int minDistance = 100000;
                int index = -1;

                // Find the closest unvisited request
                for (int j = 0; j < n; j++) {
                    if (!visited[j]) {
                        int distance = abs(head - requests[j]);
                        if (distance < minDistance) {
                            minDistance = distance;
                            index = j;
                        }
                    }
                }

                if (index == -1) break; // No more unvisited requests

                // Move to the closest request and update seek count
                visited[index] = 1;
                seekCount += abs(head - requests[index]);
                head = requests[index];
                seekSequence[i] = head;
            }

            printf("\nSeek Sequence: ");
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    printf("%d ", seekSequence[i]);
                }
            }
            printf("\nTotal Seek Count: %d\n", seekCount);
        }
        else if (choice == 3) {
            exit(0);
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    SSTF();
    return 0;
}
