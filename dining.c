#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
sem_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;
    printf("Philosopher %d is thinking.\n", id);
    sem_wait(&forks[id]);
    sem_wait(&forks[(id+1) % N]);
    printf("Philosopher %d is eating.\n", id);
    sem_post(&forks[id]);
    sem_post(&forks[(id+1) % N]);
    printf("Philosopher %d finished eating.\n", id);
}

int main() {
    pthread_t threads[N];
    int ids[N];
    for(int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
        ids[i] = i;
    }
    for(int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }
    for(int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

