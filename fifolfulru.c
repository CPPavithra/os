#include <stdio.h>

void fifo(int pages[], int n, int frames) {
    int frame[frames], f_index = 0, faults = 0;
    for (int i = 0; i < frames; i++) frame[i] = -1;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) if (frame[j] == pages[i]) { found = 1; break; }
        if (!found) { frame[f_index] = pages[i]; f_index = (f_index + 1) % frames; faults++; }
    }
    printf("FIFO: %d faults\n", faults);
}

void lfu(int pages[], int n, int frames) {
    int frame[frames], freq[frames], faults = 0;
    for (int i = 0; i < frames; i++) { frame[i] = -1; freq[i] = 0; }
    for (int i = 0; i < n; i++) {
        int found = 0, min_freq = __INT_MAX__, replace_index = -1;
        for (int j = 0; j < frames; j++) if (frame[j] == pages[i]) { found = 1; freq[j]++; break; }
        if (!found) {
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) { frame[j] = pages[i]; freq[j] = 1; faults++; found = 1; break; }
                if (freq[j] < min_freq) { min_freq = freq[j]; replace_index = j; }
            }
            if (!found) { frame[replace_index] = pages[i]; freq[replace_index] = 1; faults++; }
        }
    }
    printf("LFU: %d faults\n", faults);
}

void lru(int pages[], int n, int frames) {
    int frame[frames], last_used[frames], faults = 0;
    for (int i = 0; i < frames; i++) { frame[i] = -1; last_used[i] = -1; }
    for (int i = 0; i < n; i++) {
        int found = 0, replace_index = -1, oldest_time = -1;
        for (int j = 0; j < frames; j++) if (frame[j] == pages[i]) { found = 1; last_used[j] = i; break; }
        if (!found) {
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) { frame[j] = pages[i]; last_used[j] = i; faults++; found = 1; break; }
                if (last_used[j] < oldest_time || oldest_time == -1) { oldest_time = last_used[j]; replace_index = j; }
            }
            if (!found) { frame[replace_index] = pages[i]; last_used[replace_index] = i; faults++; }
        }
    }
    printf("LRU: %d faults\n", faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(pages) / sizeof(pages[0]), frames = 3;
    fifo(pages, n, frames);
    lfu(pages, n, frames);
    lru(pages, n, frames);
    return 0;
}

