#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include<stdlib.h>


void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("Child process received SIGINT signal\n");
    } else if (signo == SIGHUP) {
        printf("Child process received SIGHUP signal\n");
    } else if (signo == SIGTERM) {
        printf("Child process received SIGTERM signal\n");
    }
}

int main() {
    int child_pid = fork();

    if (child_pid == 0) {
        // Child process
        signal(SIGINT, signal_handler);
        signal(SIGHUP, signal_handler);
        signal(SIGTERM, signal_handler);

        printf("Child process is running. Waiting for signals...\n");

        while (1) {
            sleep(1);
        }

    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process sending signals to the child process...\n");

        // Send signals to the child process
        sleep(2);
        kill(child_pid, SIGINT);

        sleep(2);
        kill(child_pid, SIGHUP);

        sleep(2);
        kill(child_pid, SIGTERM);

        sleep(2);
        printf("Parent process is terminating...\n");
        kill(child_pid, SIGQUIT);

    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
