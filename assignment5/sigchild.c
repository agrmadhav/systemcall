#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void sigchld_handler(int signo) {
    if (signo == SIGCHLD) {
        int status;
        pid_t pid = wait(&status);

        if (WIFEXITED(status)) {
            printf("Child process %d terminated with exit status: %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("Child process %d terminated abnormally\n", pid);
        }
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler);

    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child process is running...\n");
        sleep(3);
        printf("Child process is terminating...\n");
        return 42;
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent process waiting for SIGCHLD signal...\n");
        while (1) {
            sleep(1);
        }
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
