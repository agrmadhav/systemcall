// Use fork-exec combination to create a child process. The child process invoke a new program “firefox” using “exec” while parent process continue to exectute ls command with command-line argument -l in current directory.

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
        execlp("firefox", "firefox", NULL);  // Execute the "firefox" program
        perror("exec");
        exit(EXIT_FAILURE);  // This should not be reached if exec is successful
    } else {
        // Parent process
        wait(NULL);  // Wait for the child process to exit

        // Continue with the parent process
        printf("Parent process executing 'ls -l'\n");
        execlp("ls", "ls", "-l", NULL);  // Execute the "ls" program with the "-l" argument
        perror("exec");
        exit(EXIT_FAILURE);  // This should not be reached if exec is successful
    }

    return 0;
}

