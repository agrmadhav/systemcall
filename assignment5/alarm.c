#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int alarm_count = 0;

void alarm_handler(int signo) {
    if (signo == SIGALRM) {
        printf("Received SIGALRM signal\n");
        alarm_count++;

        if (alarm_count == 5) {
            printf("Maximum number of alarms reached. Exiting...\n");
            exit(0);
        } else {
            // Set the alarm again for 2 seconds
            alarm(5);
        }
    }
}

int main() {
    int seconds = 5;

    signal(SIGALRM, alarm_handler);

    printf("Setting alarm for %d seconds...\n", seconds);
    alarm(seconds);

    while (1) {
        // Wait for signals
        pause();
    }

    return 0;
}
