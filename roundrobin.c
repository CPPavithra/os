#include <stdio.h>

void roundRobin(int processes[], int n, int burst_time[], int quantum) {
    int rem_bt[n], wait_time[n], total_wait = 0, time = 0;
    for (int i = 0; i < n; i++) {
        rem_bt[i] = burst_time[i];
        wait_time[i] = 0;
    }
    int done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0;
                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wait_time[i] = time - burst_time[i];
                    rem_bt[i] = 0;
                }
            }
        }
    } while (!done);
    for (int i = 0; i < n; i++) total_wait += wait_time[i];
    printf("Average Waiting Time: %f\n", (float)total_wait / n);
}

int main() {
    int processes[] = {1, 2, 3};
    int burst_time[] = {5, 7, 3};
    int quantum = 4;
    int n = sizeof(processes) / sizeof(processes[0]);
    roundRobin(processes, n, burst_time, quantum);
    return 0;
}

