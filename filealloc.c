#include <stdio.h>

void sequentialFileAllocation(int blocks[], int n) {
    printf("Sequential File Allocation: ");
    for (int i = 0; i < n; i++) printf("%d ", blocks[i]);
    printf("\n");
}

void indexedFileAllocation(int index[], int blocks[], int n) {
    printf("Indexed File Allocation: ");
    for (int i = 0; i < n; i++) printf("Block[%d] -> %d ", index[i], blocks[i]);
    printf("\n");
}

int main() {
    int sequentialBlocks[] = {0, 1, 2, 3, 4};
    int indexedIndex[] = {0, 1, 2, 3, 4};
    int indexedBlocks[] = {100, 200, 300, 400, 500};
    
    int sequentialSize = sizeof(sequentialBlocks) / sizeof(sequentialBlocks[0]);
    int indexedSize = sizeof(indexedIndex) / sizeof(indexedIndex[0]);
    
    sequentialFileAllocation(sequentialBlocks, sequentialSize);
    indexedFileAllocation(indexedIndex, indexedBlocks, indexedSize);

    return 0;
}

