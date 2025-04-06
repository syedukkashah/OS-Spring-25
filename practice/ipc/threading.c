#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "pthread.h"

void* helloWorld(void* arg)
{
	sleep(1);
	printf("hello world\n");
	return NULL;
}

int main(){
	pthread_t thread_id;
	printf("before thread\n");
	pthread_create(&thread_id, NULL, helloWorld, NULL);
	pthread_join(thread_id, NULL);
	printf("after thread\n");
	exit(0);
}

