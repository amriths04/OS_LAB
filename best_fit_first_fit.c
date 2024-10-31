#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

// Structure to represent a memory block
typedef struct {
    int size;
    int allocated; // 0 if free, 1 if allocated
} MemoryBlock;

// Structure to represent a process
typedef struct {
    int size;
    int allocated_block; // -1 if not allocated, otherwise the block index
} Process;

// Function to display memory status
void displayMemoryStatus(MemoryBlock blocks[], int n) {
    printf("Memory Block Status:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d: Size = %d, %s\n", i+1, blocks[i].size, blocks[i].allocated ? "Allocated" : "Free");
    }
}

// Function to display process allocation status
void displayProcessStatus(Process processes[], int p) {
    printf("Process Allocation Status:\n");
    for (int i = 0; i < p; i++) {
        if (processes[i].allocated_block != -1) {
            printf("Process %d: Size = %d, Allocated to Block %d\n", i+1, processes[i].size, processes[i].allocated_block + 1);
        } else {
            printf("Process %d: Size = %d, Not Allocated\n", i+1, processes[i].size);
        }
    }
}

// First Fit Allocation
void firstFit(MemoryBlock blocks[], int n, Process processes[], int p) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i].size) {
                blocks[j].allocated = 1;
                processes[i].allocated_block = j;
                printf("Process %d (size %d) allocated to Block %d (First Fit)\n", i+1, processes[i].size, j+1);
                break;
            }
        }
        if (processes[i].allocated_block == -1) {
            printf("Process %d (size %d) could not be allocated (First Fit)\n", i+1, processes[i].size);
        }
    }
}

// Best Fit Allocation
void bestFit(MemoryBlock blocks[], int n, Process processes[], int p) {
    for (int i = 0; i < p; i++) {
        int best_index = -1;
        for (int j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i].size) {
                if (best_index == -1 || blocks[j].size < blocks[best_index].size) {
                    best_index = j;
                }
            }
        }
        if (best_index != -1) {
            blocks[best_index].allocated = 1;
            processes[i].allocated_block = best_index;
            printf("Process %d (size %d) allocated to Block %d (Best Fit)\n", i+1, processes[i].size, best_index+1);
        } else {
            printf("Process %d (size %d) could not be allocated (Best Fit)\n", i+1, processes[i].size);
        }
    }
}

// Main function
int main() {
    MemoryBlock blocks[MAX_BLOCKS];
    Process processes[MAX_PROCESSES];
    int n, p, choice;

    // Input number of memory blocks and their sizes
    printf("Enter the number of memory blocks (up to %d): ", MAX_BLOCKS);
    scanf("%d", &n);
    if (n > MAX_BLOCKS) {
        printf("Number of blocks exceeds the maximum limit.\n");
        return 1;
    }
    printf("Enter the sizes of each memory block:\n");
    for (int i = 0; i < n; i++) {
        printf("Size of block %d: ", i+1);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0; // Initially all blocks are free
    }

    // Input number of processes and their sizes
    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &p);
    if (p > MAX_PROCESSES) {
        printf("Number of processes exceeds the maximum limit.\n");
        return 1;
    }
    printf("Enter the sizes of each process:\n");
    for (int i = 0; i < p; i++) {
        printf("Size of process %d: ", i+1);
        scanf("%d", &processes[i].size);
        processes[i].allocated_block = -1; // Initially no processes are allocated
    }

    // Choose allocation method
    printf("\nChoose an allocation method:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Allocate memory based on user choice
    if (choice == 1) {
        firstFit(blocks, n, processes, p);
    } else if (choice == 2) {
        bestFit(blocks, n, processes, p);
    } else {
        printf("Invalid choice. Please select 1 or 2.\n");
        return 1;
    }

    // Display memory and process status after allocation
    printf("\nFinal memory blocks status:\n");
    displayMemoryStatus(blocks, n);

    printf("\nFinal process allocation status:\n");
    displayProcessStatus(processes, p);

    return 0;
}
