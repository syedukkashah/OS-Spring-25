#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/wait.h"
int main(int agrc, char* argv[]){
	int i = fork();
	printf("%d\n", i);
	if(i==0){
		printf("Child %d\n", getpid());}
	else
		printf("Parent %d\n", getpid());
	return 0;
}
