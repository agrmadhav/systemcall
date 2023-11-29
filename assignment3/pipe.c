#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
// #define BUFFER_SIZE 1024

// int main(){
//     int pipefd[2];
//     char buffer[BUFFER_SIZE];
//     pipe(pipefd);
//     int childpid = fork();
//     if(childpid > 0){
//         close(pipefd[0]); // close the reading end of the pipe
//         char *message = "Hello Duniya!!!!" ;
//         write(pipefd[1], message , strlen(message)+1);
//         close(pipefd[1]);
//     }
//     else if(childpid == 0){
//         close(pipefd[1]);
//         read(pipefd[0],buffer,BUFFER_SIZE);
//         printf("Child Process mai data aaya hai : %s\n",buffer);
//         close(pipefd[0]);
//     }
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// #define BUFFER_SIZE 256

// int main() {
//     int pipefd[2];
//     int child_pid;
//     char buffer[BUFFER_SIZE];

//     // Create a pipe
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }

//     // Fork a child process
//     child_pid = fork();

//     if (child_pid == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     }

//     if (child_pid > 0) { // Parent process
//         // Close the reading end of the pipe in the parent
//         close(pipefd[0]);

//         // String to be sent
//         const char *message = "Hello, child!";

//         // Write the string to the writing end of the pipe
//         write(pipefd[1], message, strlen(message) + 1);

//         // Close the writing end of the pipe
//         close(pipefd[1]);
//     } else { // Child process
//         // Close the writing end of the pipe in the child
//         close(pipefd[1]);

//         // Read the string from the reading end of the pipe
//         read(pipefd[0], buffer, BUFFER_SIZE);

//         // Close the reading end of the pipe
//         close(pipefd[0]);

//         // Print the received string in the child process
//         printf("Child process received: %s\n", buffer);
//     }

//     return 0;
// }


// C program to illustrate 
// pipe system call in C 
#define MSGSIZE 16 
char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 
char* msg3 = "hello, world #3"; 

int main() 
{ 
	char inbuf[MSGSIZE]; 
	int p[2], i; 

	if (pipe(p) < 0) 
		exit(1); 

	/* continued */
	/* write pipe */

	write(p[1], msg1, MSGSIZE); 
	write(p[1], msg2, MSGSIZE); 
	write(p[1], msg3, MSGSIZE); 

	for (i = 0; i < 3; i++) { 
		/* read pipe */
		read(p[0], inbuf, MSGSIZE); 
		printf("%s\n", inbuf); 
	} 
	return 0; 
} 
