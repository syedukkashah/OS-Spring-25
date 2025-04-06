#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "pthread.h"
#define NUM_THREADS 4
#define ARRSIZE 1000000
int global_arr[ARRSIZE];
void init_arr(){
	for(int i=0; i<ARRSIZE; i++)
		global_arr[i] = rand() % 1000;
}
void *sum_arr(void* arg) //compute phase (parallel execution)
{
	int thread_id = *((int*)arg);
	int start = thread_id * (ARRSIZE/NUM_THREADS);
	int end = start + (ARRSIZE/NUM_THREADS);
	int sum = 0;
	for (int i=start; i<end; i++)
		sum+=global_arr[i];

	return (void*)(long)sum;
}
int main(){
	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS];
	void* thread_results[NUM_THREADS];
	long total_sum = 0;
	init_arr();
	for(int i = 0; i<NUM_THREADS; i++){
		thread_args[i] = i;
		pthread_create(&threads[i], NULL, sum_arr, (void *)&thread_args[i]); //fork phase -> parallel task creation
	}
	for(int i=0 ;i<NUM_THREADS; i++){
		pthread_join(threads[i], &thread_results[i]);
		total_sum += (long)thread_results[i];
	}
	printf("total sum of array elements: %ld\n", total_sum);
	return 0;
}

