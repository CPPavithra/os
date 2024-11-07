#include <stdio.h>

void SJF(int processes[], int n, int burst_time[]) {
    int wait_time[n], total_wait = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(burst_time[j] > burst_time[j + 1]) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;
            }
        }
    }
    wait_time[0] = 0;
    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
        total_wait += wait_time[i];
    }
    printf("Process\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i]);
    }
    printf("Average Waiting Time: %f\n", (float)total_wait/n);
}

int main() {
    int processes[] = {1, 2, 3};
    int burst_time[] = {5, 7, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    SJF(processes, n, burst_time);
    return 0;
}

