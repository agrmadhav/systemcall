// Write a C program to create a child process using fork() system call. Also use wait()system call in parent process such that it gets the return status of its child, returnstatus must be printed on console.Hint: Use (i) WIFEXITED(ii)WEXITSTATUS(iii)WIFSIGNALEDPOSIX macros to print the exit status of child process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID=%d) is running.\n", getpid());
        // Simulate some work in the child process
        sleep(2);
        exit(252); // Exit with status 42
    } else {
        // Parent process
        printf("Parent process (PID=%d) waiting for the child to finish.\n", getpid());

        int status;
        wait(&status); // Wait for the child process to finish and obtain its exit status

        if (WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal: %d\n", WTERMSIG(status));
        } else {
            printf("Unexpected exit status\n");
        }
    }

    return 0;
}
