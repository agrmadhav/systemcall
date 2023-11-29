#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    int child_pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid > 0) { // Parent process
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        execlp("sort", "sort", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<fcntl.h>
// #include<sys/wait.h>
// #include<sys/types.h>
// #include<string.h>
// int main ()
// {   
//     int fd[2] ;
//     pipe(fd);
//     int pid = fork () ;
//     if (pid == 0)
//     {
//         close(fd[0]);
//         dup2(fd[1] , STDOUT_FILENO) ;
//         close(fd[1]);
//         execlp("ls", "ls" , "-l" ,NULL) ;
//         exit (0) ;
//     }
//     else
//     {
//         close(fd[1]);
//         char buffer [1024] ;
//         read(fd[0] , buffer , sizeof(buffer)) ;
//         printf("%s" , buffer) ;
//         close(fd[0]);
//     }
//     return 0 ;
// }


// CPP program to illustrate dup() 
// #include<stdio.h> 
// #include <unistd.h> 
// #include <fcntl.h> 

// int main() 
// { 
// 	// open() returns a file descriptor file_desc to a 
// 	// the file "dup.txt" here" 

// 	int file_desc = open("dup.txt", O_WRONLY | O_APPEND); 
	
// 	if(file_desc < 0) 
// 		printf("Error opening the file\n"); 
	
// 	// dup() will create the copy of file_desc as the copy_desc 
// 	// then both can be used interchangeably. 

// 	int copy_desc = dup(file_desc);
//     printf("%d %d\n",file_desc,copy_desc); 
		
// 	// write() will write the given string into the file 
// 	// referred by the file descriptors 

// 	write(copy_desc,"This will be output to the file named dup.txt\n", 46); 
		
// 	write(file_desc,"This will also be output to the file named dup.txt\n", 51); 
	
// 	return 0; 
// } 

// CPP program to illustrate dup2() 
// #include<stdlib.h> 
// #include<unistd.h> 
// #include<stdio.h> 
// #include<fcntl.h> 

// int main() 
// { 
// 	int file_desc = open("tricky.txt",O_WRONLY | O_APPEND); 
	
// 	// here the newfd is the file descriptor of stdout (i.e. 1) 
// 	dup2(file_desc, 1) ; 
		
// 	// All the printf statements will be written in the file 
// 	// "tricky.txt" 
// 	printf("I will be printed in the file tricky.txt\n"); 
	
// return 0; 
// } 


