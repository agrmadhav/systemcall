#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void createProcessTree(int height,int currHeight){
    if (currHeight == height) {
        // printf("Leaf: Process ID = %d, Parent ID = %d\n", getpid(), getppid());
        exit(0);
    }
    for(int i=0;i<2;i++){
        int pid = fork();
        if(pid == 0){
            printf("Level %d : Process ID = %d, Parent ID = %d\n",
            currHeight + 1, getpid(), getppid()); 
            createProcessTree(height,currHeight+1);
            exit(0);
        }
        // else{
        //     wait(NULL);
        // }
    }
    for(int i=0;i<2;i++){
        wait(NULL);
    }
}

int main(){
    createProcessTree(3,0);
    return 0;
}