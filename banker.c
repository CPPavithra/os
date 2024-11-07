#include <stdio.h>

#define N 3
#define M 3

int available[M] = {3, 3, 2};
int max[N][M] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}};
int allocation[N][M] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}};
int need[N][M];

void calculateNeed() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

int isSafe() {
    int work[M], finish[N] = {0}, safeSeq[N], count = 0;
    for (int i = 0; i < M; i++) work[i] = available[i];
    while (count < N) {
        int found = 0;
        for (int i = 0; i < N; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < M; j++)
                    if (need[i][j] > work[j])
                        break;
                if (j == M) {
                    for (int k = 0; k < M; k++)
                        work[k] += allocation[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) return 0;
    }
    printf("Safe Sequence: ");
    for (int i = 0; i < N; i++) printf("%d ", safeSeq[i]);
    return 1;
}

int main() {
    calculateNeed();
    if (!isSafe()) printf("System is not in a safe state.\n");
    return 0;
}

