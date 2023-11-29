#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("Received SIGINT signal\n");
    } else if (signo == SIGHUP) {
        printf("Received SIGHUP signal\n");
    } else if (signo == SIGTERM) {
        printf("Received SIGTERM signal\n");
    }
}

int main(){
    signal(SIGINT, signal_handler);
    signal(SIGHUP, signal_handler);
    signal(SIGTERM, signal_handler);
    printf("Process is running. Waiting for signals...\n");

    // Keep running until SIGQUIT is received
    while (1) {
        sleep(1);
    }

    return 0;
}