#include <stdio.h>

void FCFS(int processes[], int n, int burst_time[]) {
    int wait_time[n], turn_around_time[n];
    int total_wait = 0, total_turn_around = 0;

    wait_time[0] = 0;

    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
        total_wait += wait_time[i];
    }

    for (int i = 0; i < n; i++) {
        turn_around_time[i] = burst_time[i] + wait_time[i];
        total_turn_around += turn_around_time[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], wait_time[i], turn_around_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wait/n);
    printf("Average Turn-Around Time: %.2f\n", (float)total_turn_around/n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Process %d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }

    FCFS(processes, n, burst_time);

    return 0;
}

