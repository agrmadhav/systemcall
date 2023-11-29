#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: not enough arguments\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("In the CHILD process Trying to Copy\n");
        printf("Child Process ID: %d, Parent ID: %d, Process Group: %d\n", getpid(), getppid(), getpgrp());

        // Uncomment the following line for execv
        // char *args[] = {"cp", "-p", "-i", argv[1], argv[2], NULL};
        // execv("/bin/cp", args);

        // Comment out the following line for execv
        execl("/bin/cp", "cp", "-p", "-i", argv[1], argv[2], NULL);

        // If exec fails, print an error message
        perror("exec");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
        printf("In the PARENT process\n");
        printf("Original Process ID: %d, Parent Is: %d, Process Group is: %d\n", getpid(), getppid(), getpgrp());
    }

    return 0;
}
