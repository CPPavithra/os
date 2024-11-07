#include <stdio.h>

void firstFit(int blocks[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }
    printf("First Fit: ");
    for (int i = 0; i < n; i++) printf("%d ", allocation[i]);
    printf("\n");
}

void bestFit(int blocks[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i] && (bestIdx == -1 || blocks[j] < blocks[bestIdx])) bestIdx = j;
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processes[i];
        }
    }
    printf("Best Fit: ");
    for (int i = 0; i < n; i++) printf("%d ", allocation[i]);
    printf("\n");
}

void worstFit(int blocks[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i] && (worstIdx == -1 || blocks[j] > blocks[worstIdx])) worstIdx = j;
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processes[i];
        }
    }
    printf("Worst Fit: ");
    for (int i = 0; i < n; i++) printf("%d ", allocation[i]);
    printf("\n");
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int m = sizeof(blocks) / sizeof(blocks[0]);
    int n = sizeof(processes) / sizeof(processes[0]);
    
    firstFit(blocks, m, processes, n);
    bestFit(blocks, m, processes, n);
    worstFit(blocks, m, processes, n);

    return 0;
}

