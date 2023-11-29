#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sched.h>

#define HIGHPRIORITY 99

void *threadFunction(void *arg) {
    // Thread logic goes here
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_attr_t attr;
    struct sched_param param;

    // Initialize thread attributes
    pthread_attr_init(&attr);

    // Create the thread with default attributes
    if (pthread_create(&tid, &attr, threadFunction, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        exit(EXIT_FAILURE);
    }

    // Set thread priority to HIGHPRIORITY
    param.sched_priority = HIGHPRIORITY;
    if (pthread_setschedparam(tid, SCHED_FIFO, &param) != 0) {
        fprintf(stderr, "Error setting thread priority\n");
        exit(EXIT_FAILURE);
    }

    // Wait for the thread to finish
    if (pthread_join(tid, NULL) != 0) {
        fprintf(stderr, "Error joining thread\n");
        exit(EXIT_FAILURE);
    }

    // Destroy thread attributes
    pthread_attr_destroy(&attr);

    return 0;
}
