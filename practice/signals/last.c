#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#define NUM_THREADS 4
pthread_t threads[NUM_THREADS];

void sigusr1_handler(int signum){
    int i = gettid(), j = getppid(), k = getpid(); // i = kernel thread id
    fprintf(stdout, "thread %u receievd SIGUSR1 signal (parent=%u)[pid=%u] {tid=%u} \n", pthread_self(), j,k,i);
}

void* thread_func(void* arg)
{
    while(1) sleep(1); //keep the thread alive
    return NULL;
}
int main(int argc, char* argv[])
{
    signal(SIGUSR1, sigusr1_handler); //signal is registered by using singal func and passing signalnum and handler func as params
    for(int i=0; i<NUM_THREADS; i++)
    {
        if(pthread_create(&threads[i],NULL, thread_func, NULL)!=0) //4 threads created
            perror("pthread_create"); exit(EXIT_FAILURE);
    }
    int i = gettid(), j = getpid(), k = getppid();
    fprintf(stdout, "parent process ID: %u, process ID: %u, main() thread id: %u\n", k, j, i);
    fprintf(stdout, "thread IDs: 0=%u, 1=%u, 2=%u, 3=%u", threads[0], threads[1], threads[2], threads[3]);
    kill(j,SIGUSR1); //sigusr1 sent to kernel process
    pthread_kill(threads[2], SIGUSR1); //sigusr1 sent to 3rd thread 

    for(int i =0; i<NUM_THREADS; i++){
        if(pthread_join(threads[i], NULL)!=0){ //threads are ran
            perror("pthread_join");exit(EXIT_FAILURE);
        }
    }
    return 0;

}
