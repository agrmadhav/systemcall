#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<math.h>
#define TARGET_VALUE 100

int race = 0;
pthread_mutex_t mutex;
pthread_cond_t condition;

void *addThread(void *arg) {
    for (int i = 0; i < TARGET_VALUE; i++) {
        pthread_mutex_lock(&mutex);
        race += 3;
        printf("Thread 1: Incremented race to %d\n", race);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *subtractThread(void *arg) {
    for (int i = 0; i < TARGET_VALUE; i++) {
        pthread_mutex_lock(&mutex);
        race -= 1;
        printf("Thread 2: Decremented race to %d\n", race);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *waitThread(void *arg) {
    pthread_mutex_lock(&mutex);
    while (race < TARGET_VALUE) {

        pthread_cond_wait(&condition, &mutex);
    }
    printf("Thread 3: Race has reached 100! Current race value: %d\n", race);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);

    // Create threads
    pthread_create(&thread1, NULL, addThread, NULL);
    pthread_create(&thread2, NULL, subtractThread, NULL);
    pthread_create(&thread3, NULL, waitThread, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);

    return 0;
}


/*
void *print(void *num)
{
    int *a = (int*)num;
    for ( int i = 0; i < 5; i++ )
    {
        printf ("hello world thread %d \n", *a);
    }
    pthread_exit(NULL);
} 
int main ()
{
    pthread_t thread[n] ;
    int thread_arg[n] ;
    for ( int i = 0; i < n; i++ )
    {
        thread_arg[i] = i+1 ;
        pthread_create(&thread[i], NULL, print,(void *)& thread_arg[i]); ;
    }
    for ( int i = 0; i < n; i++)
    {
        pthread_join(thread[i], NULL);
    }
    return 0 ;
}

*/

/*
void *print(void *num)
{
    printf("Hello World") ;
    pthread_exit(NULL) ;
} 
int main ()
{
    pthread_t thread ;
    pthread_attr_t mythread ;
    struct sched_param myThreadParam;
    pthread_attr_init(&mythread) ;
    pthread_create(&thread, &mythread, print , NULL) ;
    myThreadParam.sched_priority = HIGHPRIORIT;
    pthread_setschedparam(thread, SCHED_OTHER, &myThreadParam);
    pthread_join(thread, NULL) ;
    pthread_attr_destroy(&mythread) ;
    return 0 ;
}
*/

/*
struct threaddata {
    double num [100] ;
} ;
void *print(void *arg)
{
    struct threaddata * data = (struct threaddata *)arg;
    for ( int i = 1 ; i < 100 ; i ++)
    {
        data -> num [i]= sqrt((double)i) ;
    }
    pthread_exit (arg) ;
} 

int main ()
{
    pthread_t thread ;
    struct threaddata * data ;
    data = (struct threaddata *)malloc(sizeof(struct threaddata));
    pthread_create(&thread , NULL , print ,(struct threaddata *)data) ;
    pthread_join(thread , (void **)&data) ; 
    for ( int i = 0 ;i < 100 ; i ++ )
    {
        printf("%lf \n",data->num[i]);
    }
    return 0 ;
}
*/

/*
    #define n 10

#define HIGHPRIORIT 1
int balance = 1000 ;
pthread_mutex_t mutex ;
void *withdraw(void *arg)
{
    int * amt = (int *) arg ;
    pthread_mutex_lock(&mutex);
    balance -= *amt ;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL) ;
} 
void *deposit (void *arg)
{
    int * amt = (int *) arg ;
    pthread_mutex_lock(&mutex);
    balance += *amt ;
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL) ;
}
int main ()
{
    pthread_t thread;
    pthread_t tthread ;
    int withdraw_amt = 20 ;
    int deposit_amt = 10 ;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread, NULL,withdraw, (void *) &withdraw_amt) ;
    pthread_create(&tthread, NULL,deposit, (void *) &deposit_amt);
    pthread_join(thread, NULL) ;
    pthread_join(tthread, NULL) ;
    printf("%d " , balance) ;
    return 0 ;
}

*/