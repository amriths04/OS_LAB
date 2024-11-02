#include <stdio.h>

int main() {
    int frames, pages, i, j, pos, faults = 0, time = 0;
    
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    
    int pageRefs[pages], frame[frames], access_time[frames];
    
    printf("Enter the page reference string: ");
    for (i = 0; i < pages; i++) {
        scanf("%d", &pageRefs[i]);
    }
    
    for (i = 0; i < frames; i++) {
        frame[i] = -1; // Initialize frames as empty
        access_time[i] = -1; // Initialize access times as unused
    }

    for (i = 0; i < pages; i++) {
        int found = 0;
        
        // Check if the page is already in a frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == pageRefs[i]) {
                found = 1;
                access_time[j] = ++time; // Update access time
                break;
            }
        }
        
        if (!found) { // Page fault occurs
            int oldest = time, lru_index = -1;
            
            // Find the least recently used (LRU) page
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) { // Empty frame found
                    lru_index = j;
                    break;
                }
                if (access_time[j] < oldest) { // Find oldest access time
                    oldest = access_time[j];
                    lru_index = j;
                }
            }
            
            // Replace the LRU page
            frame[lru_index] = pageRefs[i];
            access_time[lru_index] = ++time; // Set current access time
            faults++; // Increment page fault count
        }

        // Print current frame state
        printf("Frames after accessing page %d: ", pageRefs[i]);
        for (j = 0; j < frames; j++) {
            
                printf("%d ", frame[j]);
            
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
