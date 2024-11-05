#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void SCAN() {
    int n, head, total = 0;
    int req[MAX], seq[MAX];
    
    // Input: number of requests, requests array, and initial head position
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    // Sort the request array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    
    // Determine direction based on proximity to midpoint
    int dir = 0; // 0 for left, 1 for right
    int half = req[n - 1] / 2;
    if (head > half) {
        dir = 1;
    }

    // Find index of the first request greater than the head
    int index;
    for (index = 0; index < n; index++) {
        if (req[index] > head) {
            break;
        }
    }

    int seqi = 0;

    // SCAN in the determined direction
    if (dir == 0) {  // Moving left
        // Service requests to the left of the head
        for (int i = index - 1; i >= 0; i--) {
            total += abs(head - req[i]);
            seq[seqi++] = req[i];
            head = req[i];
        }
        // After reaching the start, move to the right
        for (int i = index; i < n; i++) {
            total += abs(head - req[i]);
            seq[seqi++] = req[i];
            head = req[i];
        }
    } else {  // Moving right
        // Service requests to the right of the head
        for (int i = index; i < n; i++) {
            total += abs(head - req[i]);
            seq[seqi++] = req[i];
            head = req[i];
        }
        // After reaching the end, move to the left
        for (int i = index - 1; i >= 0; i--) {
            total += abs(head - req[i]);
            seq[seqi++] = req[i];
            head = req[i];
        }
    }

    // Print the results
    printf("\nSeek Sequence: ");
    for (int i = 0; i < seqi; i++) {
        printf("%d ", seq[i]);
    }
    printf("\nTotal Seek Count: %d\n", total);
}

int main() {
    SCAN();
    return 0;
}
