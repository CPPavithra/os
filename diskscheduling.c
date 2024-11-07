#include <stdio.h>

void fcfs(int arr[], int n, int head) {
    int seek_count = 0;
    for (int i = 0; i < n; i++) {
        seek_count += abs(arr[i] - head);
        head = arr[i];
    }
    printf("FCFS Seek Count: %d\n", seek_count);
}

void scan(int arr[], int n, int head, int size) {
    int seek_count = 0, left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < head) left++;
        if (arr[i] > head) right++;
    }
    for (int i = left - 1; i >= 0; i--) seek_count += abs(arr[i] - head), head = arr[i];
    for (int i = left; i < n; i++) seek_count += abs(arr[i] - head), head = arr[i];
    printf("SCAN Seek Count: %d\n", seek_count);
}

void cscan(int arr[], int n, int head, int size) {
    int seek_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > head) {
            seek_count += abs(arr[i] - head);
            head = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        seek_count += abs(arr[i] - head);
        head = arr[i];
    }
    printf("CSCAN Seek Count: %d\n", seek_count);
}

int main() {
    int arr[] = {98, 183, 41, 122, 14, 124, 65, 67};
    int n = sizeof(arr) / sizeof(arr[0]);
    int head = 53, size = 200;
    
    fcfs(arr, n, head);
    scan(arr, n, head, size);
    cscan(arr, n, head, size);

    return 0;
}

