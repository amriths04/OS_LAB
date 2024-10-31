#include <stdio.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

// Function to check if a page is in the frame
int isPageInFrame(int frames[], int num_frames, int page) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return 1; // Page found in frame
        }
    }
    return 0; // Page not found
}

// FIFO Page Replacement
int fifoPageReplacement(int pages[], int num_pages, int num_frames) {
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int next_replace_index = 0;

    // Initialize frames as empty
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        int current_page = pages[i];

        // Check if the page is not in frame (page fault occurs)
        if (!isPageInFrame(frames, num_frames, current_page)) {
            page_faults++;  // Increment page fault counter
            frames[next_replace_index] = current_page;  // Replace the page at the current index
            next_replace_index = (next_replace_index + 1) % num_frames;  // Update index for FIFO
        }
    }

    return page_faults;
}

// Main function
int main() {
    int pages[MAX_PAGES];
    int num_pages, num_frames;

    // Input number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    // Input page sequence
    printf("Enter the page sequence:\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    // Simulate FIFO Page Replacement
    int fifo_faults = fifoPageReplacement(pages, num_pages, num_frames);
    printf("FIFO Page Replacement - Page Faults: %d\n", fifo_faults);

    return 0;
}
