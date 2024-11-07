#include <stdio.h>

void priorityScheduling(int n, int burst_time[], int priority[]) {
    int wait_time[n], total_wait = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(priority[j] > priority[j + 1]) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;
            }
        }
    }
    wait_time[0] = 0;
    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
        total_wait += wait_time[i];
    }
    printf("Process\tPriority\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, priority[i], burst_time[i], wait_time[i]);
    }
    printf("Average Waiting Time: %f\n", (float)total_wait/n);
}

int main() {
    int burst_time[] = {5, 7, 3};
    int priority[] = {2, 1, 3};
    int n = sizeof(burst_time) / sizeof(burst_time[0]);
    priorityScheduling(n, burst_time, priority);
    return 0;
}

