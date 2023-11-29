
#include <stdio.h>
#include <pthread.h>

void *helloWorld(void *threadNum) {
    int num = *((int *)threadNum);
    for (int i = 0; i < 5; ++i) {
        printf("Hello, World (thread %d)\n", num);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threadIDs[10];
    int threadNums[10];

    for (int i = 0; i < 10; ++i) {
        threadNums[i] = i + 1;
        pthread_create(&threadIDs[i], NULL, helloWorld, (void *)&threadNums[i]);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(threadIDs[i], NULL);
    }

    return 0;
}

// #include<stdio.h>
// #include<pthread.h>

// void printHello(void* threadnum){
//     int num = *(int*) threadnum;
//     for(int i=0;i<num;i++){
//         printf("Hello world  %d\n", i+1);
//     }
//     pthread_exit(NULL);
// }

// int main(){
//     pthread_t thread_id[10];
//     int thread_num[10];
//     for(int i=0;i<10;i++){
//         thread_num[i] = i+1;
//         pthread_create(&thread_id[i], NULL, printHello, (void *)&thread_num[i]);
//     }
//     for(int i=0;i<10;i++){
//         pthread_join(thread_id[i],NULL);
//     }
//     return 0;
// }