#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "pthread.h"
#define NUM_THREADS 5
void* helloWorld(void* arg){
	int thread_num = *((int*)arg);
	sleep(1);
	printf("hello from thread %d\n", thread_num);
	return NULL;
}
int main(){
	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS];
	for(int i=0; i<NUM_THREADS; i++)
	{
		thread_args[i] = i+1;
		printf("Creating thread %d\n",i+1);
		pthread_create(&threads[i], NULL, helloWorld, NULL);
	}
	for(int i=0; i<5; i++) pthread_join(threads[i], NULL);
	printf("All threads finished");
	return 0;
}

