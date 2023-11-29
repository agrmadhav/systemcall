#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%d \n" , argc);
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int pipefd[2];
    int child_pid;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    int status ;
    if (child_pid > 0) { // Parent process
        // Close the reading end of the pipe in the parent
        close(pipefd[0]);

        // Write the command to the writing end of the pipe
        write(pipefd[1], argv[1], strlen(argv[1]) + 1);

        // Close the writing end of the pipe
        close(pipefd[1]);

        // Wait for the child process to finish
        wait(NULL);
    } else { // Child process
        // Close the writing end of the pipe in the child
        close(pipefd[1]);

        // Redirect standard input to the reading end of the pipe
        dup2(pipefd[0], STDIN_FILENO);

        // Close the unused file descriptor
        close(pipefd[0]);

        // Invoke a new xterm terminal to display the man page

        execlp("xterm", "xterm", "-e", "sh", "-c", "man", NULL);

        // If execlp fails
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}
