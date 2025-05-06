#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10
#define ARR_SIZE 1000000
float A[ARR_SIZE], B[ARR_SIZE], C[ARR_SIZE];
pthread_t threads[NUM_THREADS];
int sum = 0;
void init_arr(){
    for(int i=0; i<ARR_SIZE; i++)
    {
        A[i] = rand() % 1000;
        B[i] = rand() % 1000;
    }
}
void* func(void* arg){
    int thread_id = *((int*)arg);
    int start = thread_id * (ARR_SIZE/NUM_THREADS);
    int end = start + (ARR_SIZE/NUM_THREADS);
    for(int i=start; i< end; i++){
        C[i] = A[i] + B[i];
    }
    printf("thread id %d done\n", thread_id);
    pthread_exit(0);
}
    

int main(int argc, char* argv[])
{
    int thread_args[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++){
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, func, (void*)&thread_args[i]);
    }
    for(int i=0; i<NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
