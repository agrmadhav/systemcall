// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/wait.h>

// int main(){
//     int pid;
//     for(int i=0;i<10;i++){
//         pid = fork();
//         if(pid == 0){
//             printf("Child %d : ProcessId = %d ParentId = %d\n",
//                                                 i+1,getpid(),getppid());
//             exit(0);
//         }
//         // else{
//         //     wait(NULL);
//         // }
//     }
//     for(int i=0;i<10;i++){
//         wait(NULL);
//     }
//     return 0;
// }
// C program to create a chain of process 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

// Driver Code 
int main() 
{ 
	int pid; 

	// Iterate in the range [0, 2] 
	for (int i = 0; i < 10; i++) { 
		pid = fork(); 

		if (pid > 0) { 
			// Print the parent process 
			printf("Parent process ID is %d\n", 
				getpid()); 
			break; 
		} 
		else { 
			// Print the child process 
			printf("Child process ID is %d Parent = %d\n", 
				getpid(),getppid()); 
		} 
	} 

	return 0; 
} 
