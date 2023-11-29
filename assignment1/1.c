#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child: Process ID = %d, Parent ID = %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent: Process ID = %d, Child ID = %d, Owner ID = %d\n", getpid(), pid, getuid());
        wait(NULL);  // Wait for the child to exit
    }

    return 0;
}
